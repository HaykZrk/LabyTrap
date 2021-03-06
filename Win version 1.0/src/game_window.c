/**
 * @file game_window.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Game file.
 * @version 1.0
 * @date 2021-09-26
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "../include/game_window.h"
#include "../include/keyboard_management.h"
#include "../include/mouse_management.h"
#include "../include/error_handling.h"
#include "../include/garbage_collector.h"
#include "../include/event.h"
#include "../include/menu.h"
#include "../include/level_menu.h"

/**
 * @brief Main function to start the game menu.
 *
 */
void game_window (void) {
// INIT AND GLOBALE
    for (int i = 0; i < KEYMAX; i++)
        keyy[i] = false;
    dessine = true;
    continuer = true;
    play = false;

    owl_go = 0;
    x = -100;
    y = 100;

    active_level = 0;

    int oldx = 0, oldy = 0;

    test_init ();
    al_set_new_display_flags (ALLEGRO_WINDOWED);
    display = al_create_display (800, 600);
    al_set_window_title (display, "LabyTrap");
    test_display ();

    queue = al_create_event_queue ();
    test_queue ();

    timer = al_create_timer (1.0 / 10);
    test_timer ();

    test_mouse ();
    test_keyboard ();

    al_init_font_addon ();
    test_ttf ();

    al_init_primitives_addon ();
    test_primitives ();

    al_init_image_addon ();
    if (!al_init_image_addon ())
        error ("al_init_image_addon()");

    al_install_audio ();
    al_init_acodec_addon ();
    test_audio ();
    test_acodec ();
// INIT AND GLOBALE (END)

// OBJECTS LOAD
    image_owl_face = al_load_bitmap ("../assets/characters/owl_face.png");
    test_image (image_owl_face, "owl_face.png");

    image_owl_go_right_left = al_load_bitmap ("../assets/characters/owl_go_right-left.png");
    test_image (image_owl_go_right_left, "owl_go_right-left.png");

    image_return = al_load_bitmap ("../assets/utility/return.png");
    test_image (image_return, "return.png");

    image_return_active = al_load_bitmap ("../assets/utility/return_active.png");
    test_image (image_return_active, "return_active.png");

    image_flag = al_load_bitmap ("../assets/utility/flag.png");
    test_image (image_flag, "flag.png");

    image_flag_green = al_load_bitmap ("../assets/utility/flag_green.png");
    test_image (image_flag_green, "flag_green.png");

    image_bomb = al_load_bitmap ("../assets/utility/bomb.png");
    test_image (image_bomb, "bomb.png");

    image_explosion = al_load_bitmap ("../assets/utility/explosion.png");
    test_image (image_explosion, "explosion.png");

    image_level_1_bg = al_load_bitmap ("../assets/utility/LEVEL_1_BACKGROUND.bmp");
    test_image (image_level_1_bg, "LEVEL_1_BACKGROUND.bmp");

    arial72 = al_load_font ("../assets/fonts/arial.ttf", 72, 0);
    test_font (arial72);

    arial15 = al_load_font ("../assets/fonts/arial.ttf", 15, 0);
    test_font (arial15);

    arial30 = al_load_font ("../assets/fonts/arial.ttf", 30, 0);
    test_font (arial30);

    al_reserve_samples (10);
    MENU_Song = al_load_sample ("../assets/audio/menu_song.wav");
    test_sample (MENU_Song);

    MENU_Click_Song = al_load_sample ("../assets/audio/menu_click_song.ogg");
    test_sample (MENU_Click_Song);

    LEVEL_Bomb_Song = al_load_sample ("../assets/audio/level_bomb_song.ogg");
    test_sample (LEVEL_Bomb_Song);

    LEVEL_1_Song = al_load_sample ("../assets/audio/level_1_song.wav");
    test_sample (LEVEL_1_Song);

    songInstance = al_create_sample_instance (MENU_Song);
    test_sample_instance (songInstance);
    al_set_sample_instance_playmode (songInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer (songInstance, al_get_default_mixer ());

    songInstance2 = al_create_sample_instance (LEVEL_1_Song);
    test_sample_instance (songInstance2);
    al_set_sample_instance_playmode (songInstance2, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer (songInstance2, al_get_default_mixer ());

    register_event ();

    for (int i = 0; i < 8; i++) {
        sprintf (nom, "../assets/characters/z%d.png", i);
        anim[i] = al_load_bitmap (nom);
        test_image (anim[i], "nom");
    }
    dir = cmptimage = 0;
    image = 2;

    al_start_timer (timer);
// OBJECTS LOAD (END)

// GAME LAUNCHER
    while (continuer){
        if (!play) {
            al_clear_to_color (WHITE);

            ALLEGRO_EVENT event;
            al_wait_for_event (queue, &event);
            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                continuer = false;

            else if (event.type == ALLEGRO_EVENT_TIMER) {
                al_get_keyboard_state (&key);
                al_get_mouse_state (&mouse);

                if (oldx != mouse.x || oldy != mouse.y){
                    oldx = mouse.x;
                    oldy = mouse.y;
                }

                launch_display ();
                menu_dynamic ();

                if (owl_go == 0)
                    owl_go = 1;
                else
                    owl_go = 0;

                x++;
                if (x > 830)
                    x = -30;
                    
                al_flip_display ();
            }
        }
        else if (play) {
            al_clear_to_color (WHITE);

            ALLEGRO_EVENT event;
            al_wait_for_event (queue, &event);
            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                continuer = false;

            else if (event.type == ALLEGRO_EVENT_TIMER) {
                al_get_keyboard_state (&key);
                al_get_mouse_state (&mouse);

                level_launch_display ();
                level_menu_dynamic ();

                al_flip_display ();
            }
        }
   }
// GAME LAUNCHER (END)
}
