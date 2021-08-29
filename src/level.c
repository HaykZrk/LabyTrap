#include "../include/level.h"
#include "../include/game_window.h"
#include "../include/event.h"
#include "../include/keyboard_management.h"
#include "../include/mouse_management.h"

void level_1 (void) {
    al_clear_to_color (WHITE);

    ALLEGRO_EVENT event;
    al_wait_for_event (queue, &event);
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        continuer_level = false;
        continuer = false;
    }

    else if (event.type == ALLEGRO_EVENT_TIMER) {
        al_get_keyboard_state (&key);
        al_get_mouse_state (&mouse);
    }

    al_draw_textf (arial72, BLACK, 400, 0, ALLEGRO_ALIGN_CENTRE, "LEVEL 1");
    al_draw_bitmap (image_return, 0, 0, 0);
    al_draw_line (0, 90, 800, 90, BLACK, 3);

    if (mouse.x > 0 && mouse.x < 30 && mouse.y > 0 && mouse.y < 30) {
        al_draw_bitmap (image_return_active, 0, 0, 0);
        if (is_mouse_pressed (&mouse, 1, 1))
            continuer_level = false;
    }

    al_draw_bitmap (image_owl_face, 30, 208, 0);

    al_draw_line (50, 150, 750, 150, BLACK, 5);
    al_draw_line (50, 147, 50, 200, BLACK, 5);
    al_draw_line (50, 250, 50, 540, BLACK, 5);
    al_draw_line (50, 538, 750, 538, BLACK, 5);
    al_draw_line (748, 538, 748, 488, BLACK, 5);
    al_draw_line (748, 438, 748, 150, BLACK, 5);
    al_draw_line (47, 250, 150, 250, BLACK, 5);
    al_draw_line (148, 248, 148, 200, BLACK, 5);
    al_draw_line (210, 148, 210, 310, BLACK, 5);
    al_draw_line (212, 310, 160, 310, BLACK, 5);
    //al_draw_line (50, 310, 105, 310, BLACK, 5);
    al_draw_line (163, 310, 163, 438, BLACK, 5);
    al_draw_line (103, 310, 103, 540, BLACK, 5);
    al_draw_line (160, 488, 750, 488, BLACK, 5);
    al_draw_line (160, 438, 400, 438, BLACK, 5);
    al_draw_line (450, 438, 600, 438, BLACK, 5);
    al_draw_line (650, 438, 750, 438, BLACK, 5);
    al_draw_line (398, 438, 398, 320, BLACK, 5);
    al_draw_line (453, 438, 453, 388, BLACK, 5);
    al_draw_line (598, 438, 598, 388, BLACK, 5);
    al_draw_line (600, 388, 450, 388, BLACK, 5);
    al_draw_line (650, 440, 650, 320, BLACK, 5);
    al_draw_line (395, 320, 652, 320, BLACK, 5);
    al_draw_bitmap (image_flag, 720, 448, 0);


    al_flip_display ();
}
