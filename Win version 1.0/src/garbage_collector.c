/**
 * @file garbage_collector.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Garbage collector file.
 * @version 1.0
 * @date 2021-09-26
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "../include/garbage_collector.h"
#include "../include/game_window.h"
#include "../include/event.h"
#include "../include/menu.h"

/**
 * @brief Memory release.
 *
 */
void free_total (void) {
    al_destroy_display (display);

    al_destroy_event_queue (queue);

    al_destroy_timer (timer);

    al_destroy_font (arial72);
    al_destroy_font (arial15);
    al_destroy_font (arial30);

    al_destroy_sample (MENU_Song);
    al_destroy_sample (MENU_Click_Song);
    al_destroy_sample_instance (songInstance);
    al_destroy_sample (LEVEL_Bomb_Song);
    al_destroy_sample (LEVEL_1_Song);
    al_destroy_sample_instance (songInstance2);

    al_destroy_bitmap (image_owl_face);
    al_destroy_bitmap (image_owl_go_right_left);
    al_destroy_bitmap (image_return);
    al_destroy_bitmap (image_return_active);
    al_destroy_bitmap (image_flag);
    al_destroy_bitmap (image_flag_green);
    for (int i = 0; i < 8; i++)
        al_destroy_bitmap (anim[i]);
    al_destroy_bitmap (image_bomb);
    al_destroy_bitmap (image_explosion);
    al_destroy_bitmap (image_level_1_bg);

}
