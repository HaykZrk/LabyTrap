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

/**
 * @brief Main function to start the game menu.
 *
 */
void game (void) {
    bool continuer = true;
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
    test_font ();

    al_register_event_source (queue, al_get_display_event_source(display));
    al_register_event_source (queue, al_get_keyboard_event_source());
    al_register_event_source (queue, al_get_mouse_event_source());
    al_register_event_source (queue, al_get_timer_event_source(timer));

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

        al_draw_textf (arial72, BLACK, 400, 400, ALLEGRO_ALIGN_CENTRE, "Exit");
        al_draw_textf (arial72, BLACK, 400, 300, ALLEGRO_ALIGN_CENTRE, "Settings");
        al_draw_textf (arial72, BLACK, 400, 200, ALLEGRO_ALIGN_CENTRE, "Play");
        al_draw_textf (arial72, BLACK, 400, 0, ALLEGRO_ALIGN_CENTRE, "LabyTrap");

        if (mouse.x > 320 && mouse.x < 480 && mouse.y > 400 && mouse.y < 480) {
            al_draw_textf (arial72, ORANGE, 400, 400, ALLEGRO_ALIGN_CENTRE, "Exit");
            if (is_mouse_pressed (&mouse, 1, 1))
                continuer = false;
        }

        al_flip_display ();
   }
    free_total ();
}
