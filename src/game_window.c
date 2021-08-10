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
    al_set_window_title (display, "Jeu");
    test_display ();

    queue = al_create_event_queue ();
    test_queue ();

    timer = al_create_timer (2.0);
    test_timer ();

    test_mouse ();
    test_keyboard ();

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
        al_flip_display ();
   }
    free_total ();
}
