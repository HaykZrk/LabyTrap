/**
 * @file level_menu.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Level menu file.
 * @version 0.1
 * @date 2021-08-22
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "../include/level_menu.h"
#include "../include/game_window.h"
#include "../include/error_handling.h"
#include "../include/mouse_management.h"
#include "../include/level.h"

/**
 * @brief Level launch display (without dynamism).
 *
 */
void level_launch_display (void) {
    al_draw_textf (arial72, BLACK, 400, 0, ALLEGRO_ALIGN_CENTRE, "LEVEL MENU");
    al_draw_bitmap (image_return, 0, 0, 0);
    al_draw_line (0, 90, 800, 90, BLACK, 3);

    al_draw_rectangle (10, 100, 50, 140, BLACK, 3);

    if (active_level == 0)
        al_draw_textf (arial30, BLACK, 30, 102, ALLEGRO_ALIGN_CENTRE, "1");
    else
        al_draw_textf (arial30, ORANGE, 30, 102, ALLEGRO_ALIGN_CENTRE, "1");


    al_draw_line (0, 510, 800, 510, BLACK, 3);
    if (active_level == 0)
        al_draw_textf (arial72, GREY, 400, 510, ALLEGRO_ALIGN_CENTRE, "GO");
    else
        al_draw_textf (arial72, BLACK, 400, 510, ALLEGRO_ALIGN_CENTRE, "GO");
}

/**
 * @brief Activation of menu interaction (clicks, color change, ...).
 *
 */
void level_menu_dynamic (void) {
    if (mouse.x > 0 && mouse.x < 30 && mouse.y > 0 && mouse.y < 30) {
        al_draw_bitmap (image_return_active, 0, 0, 0);
        if (is_mouse_pressed (&mouse, 1, 1)) {
            play = false;
            active_level = 0;
        }
    }

    if (mouse.x > 10 && mouse.x < 50 && mouse.y > 100 && mouse.y < 140) {
        if (active_level == 0) {
            al_draw_textf (arial30, ORANGE, 30, 102, ALLEGRO_ALIGN_CENTRE, "1");
            if (is_mouse_pressed (&mouse, 1, 1))
                active_level = 1;
        }
        else {
            al_draw_textf (arial30, BLACK, 30, 102, ALLEGRO_ALIGN_CENTRE, "1");
            if (is_mouse_pressed (&mouse, 1, 1))
                active_level = 0;
        }
    }

    if (active_level != 0) {
        if (mouse.x > 340 && mouse.x < 460 && mouse.y > 515 && mouse.y < 585) {
            al_draw_textf (arial72, ORANGE, 400, 510, ALLEGRO_ALIGN_CENTRE, "GO");
            if (is_mouse_pressed (&mouse, 1, 1)) {
                continuer_level = true;
                active_level = 0;
                    dx = 30;
                    dy = 205;
                while (continuer_level)
                    level_1 ();
            }
        }
    }
}
