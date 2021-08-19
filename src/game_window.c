/**
 * @file game_window.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Game file.
 * @version 0.1
 * @date 2021-08-10
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

/**
 * @brief Main function to start the game menu.
 *
 */
void game_window (void) {
    continuer = true;
    int oldx = 0, oldy = 0;
    test_init ();

    al_set_new_display_flags (ALLEGRO_WINDOWED);
    display = al_create_display (800, 600);
    al_set_window_title (display, "LabyTrap");
    test_display ();

    queue = al_create_event_queue ();
    test_queue ();

    timer = al_create_timer (2.0);
    test_timer ();

    test_mouse ();
    test_keyboard ();

    al_init_font_addon ();
    test_ttf ();

    arial72 = al_load_font ("fonts/arial.ttf", 72, 0);
    test_font (arial72);

    arial15 = al_load_font ("fonts/arial.ttf", 15, 0);
    test_font (arial15);

    al_install_audio ();
    al_init_acodec_addon ();
    test_audio ();
    test_acodec ();

    al_reserve_samples (1);
    MENU_Song = al_load_sample ("audio/menu_song.wav");
    test_sample (MENU_Song);

    MENU_Click_Song = al_load_sample ("audio/menu_click_song.ogg");
    test_sample (MENU_Click_Song);

    songInstance = al_create_sample_instance (MENU_Song);
    test_sample_instance (songInstance);
    al_set_sample_instance_playmode (songInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer (songInstance, al_get_default_mixer ());

    register_event ();
    //al_start_timer (timer);

    while (continuer){
        al_clear_to_color (WHITE);

        ALLEGRO_EVENT event;
        al_wait_for_event (queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            continuer = false;

        //else if (event.type == ALLEGRO_EVENT_TIMER) {
        al_get_keyboard_state (&key);
        al_get_mouse_state (&mouse);

        if (oldx != mouse.x || oldy != mouse.y){
            oldx = mouse.x;
            oldy = mouse.y;
        }

        launch_display ();
        menu_dynamic ();
        al_flip_display ();
   }
}
