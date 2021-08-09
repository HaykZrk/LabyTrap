#include "../include/game_window.h"
#include "../include/keyboard_management.h"
#include "../include/mouse_management.h"
#include "../include/error_handling.h"


void game (void) {
    ALLEGRO_MOUSE_STATE mouse;
    ALLEGRO_KEYBOARD_STATE k, *key = &k;

    bool continuer = true;
    int oldx = 0, oldy = 0;

    srand (time(NULL));
    test_init ();

    al_set_new_display_flags (ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);

    display = al_create_display (800, 600);
    test_display ();

    al_set_window_title (display, "Jeu");

    al_clear_to_color (BLANC);

    test_mouse ();

    test_keyboard ();

    queue = al_create_event_queue();
    test_queue ();

    timer = al_create_timer(1.0 / 30);
    test_timer ();


    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    while(continuer){
        al_clear_to_color(BLANC);

        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            continuer = false;


        else if (event.type == ALLEGRO_EVENT_TIMER) {
            al_get_keyboard_state(key);
            al_get_mouse_state(&mouse);

            if(oldx != mouse.x || oldy != mouse.y){
                oldx = mouse.x;
                oldy = mouse.y;
            }

            if(is_key_pressed(key, ALLEGRO_KEY_ESCAPE, 1))
                continuer = false;

            al_flip_display();
        }
   }

   al_destroy_display(display);
   al_destroy_event_queue(queue);
   al_destroy_timer(timer);
   free(PRESS);

}
