#include "../include/level.h"
#include "../include/game_window.h"
#include "../include/event.h"
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

    al_flip_display ();
}
