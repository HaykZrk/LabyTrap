/**
 * @file menu.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Menu file.
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "../include/menu.h"
#include "../include/game_window.h"
#include "../include/error_handling.h"
#include "../include/mouse_management.h"

bool MENU_click_song_active_exit = true;
bool MENU_click_song_active_settings = true;
bool MENU_click_song_active_play = true;
bool MENU_song_active = true;

/**
 * @brief Launch display (without dynamism).
 * 
 */
void launch_display (void) {
    al_draw_textf (arial72, BLACK, 400, 0, ALLEGRO_ALIGN_CENTRE, "LabyTrap");

    al_draw_textf (arial15, BLACK, 800, 0, ALLEGRO_ALIGN_RIGHT, "PLAY MUSIC");
    al_draw_textf (arial15, BLACK, 0, 0, ALLEGRO_ALIGN_LEFT, "STOP MUSIC");

    al_draw_textf (arial72, BLACK, 400, 200, ALLEGRO_ALIGN_CENTRE, "Play");
    al_draw_textf (arial72, BLACK, 400, 300, ALLEGRO_ALIGN_CENTRE, "Settings");
    al_draw_textf (arial72, BLACK, 400, 400, ALLEGRO_ALIGN_CENTRE, "Exit");
}

/**
 * @brief Activation of menu interaction (clicks, color change, ...).
 * 
 */
void menu_dynamic (void) {
    if (MENU_song_active)
        al_play_sample_instance (songInstance);

    if (mouse.x > 700 && mouse.x < 800 && mouse.y > 0 && mouse.y < 15) {
        al_draw_textf (arial15, ORANGE, 800, 0, ALLEGRO_ALIGN_RIGHT, "PLAY MUSIC");
        if (is_mouse_pressed (&mouse, 1, 1))
            MENU_song_active = true;
    }

    if (mouse.x > 0 && mouse.x < 100 && mouse.y > 0 && mouse.y < 15) {
        al_draw_textf (arial15, ORANGE, 0, 0, ALLEGRO_ALIGN_LEFT, "STOP MUSIC");
        if (is_mouse_pressed (&mouse, 1, 1)) {
            al_stop_sample_instance (songInstance);
            MENU_song_active = false;
        }
    }

    if ((mouse.x < 320 || mouse.x > 480) || (mouse.y < 200 || mouse.y > 280))
        MENU_click_song_active_play = true;
    if ((mouse.x <= 250 || mouse.x >= 550) || (mouse.y <= 300 || mouse.y >= 380))
        MENU_click_song_active_settings = true;
    if ((mouse.x <= 320 || mouse.x >= 480) || (mouse.y <= 400 || mouse.y >= 480))
        MENU_click_song_active_exit = true;

    if (mouse.x > 320 && mouse.x < 480 && mouse.y > 200 && mouse.y < 280) {
        if (MENU_click_song_active_play) {
            al_play_sample (MENU_Click_Song, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
            MENU_click_song_active_play = false;
        }
        al_draw_textf (arial72, ORANGE, 400, 200, ALLEGRO_ALIGN_CENTRE, "Play");
    }

    if (mouse.x > 250 && mouse.x < 550 && mouse.y > 300 && mouse.y < 380) {
        if (MENU_click_song_active_settings) {
            al_play_sample (MENU_Click_Song, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
            MENU_click_song_active_settings = false;
        }
        al_draw_textf (arial72, ORANGE, 400, 300, ALLEGRO_ALIGN_CENTRE, "Settings");
    }


    if (mouse.x > 320 && mouse.x < 480 && mouse.y > 400 && mouse.y < 480) {
        if (MENU_click_song_active_exit) {
            al_play_sample (MENU_Click_Song, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
            MENU_click_song_active_exit = false;
        }

        al_draw_textf (arial72, ORANGE, 400, 400, ALLEGRO_ALIGN_CENTRE, "Exit");
        if (is_mouse_pressed (&mouse, 1, 1)) {
            continuer = false;
        }
    }
}
