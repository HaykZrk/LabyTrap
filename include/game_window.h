/**
 * @file game_window.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Game file.
 * @version 0.1
 * @date 2021-08-10
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

#define BLACK al_map_rgb (0, 0, 0)
#define WHITE al_map_rgb (255, 255, 255)
#define ORANGE al_map_rgb (255, 57, 0)

bool continuer;

ALLEGRO_MOUSE_STATE mouse;
ALLEGRO_KEYBOARD_STATE key;

ALLEGRO_FONT *arial72;
ALLEGRO_FONT *arial15;

ALLEGRO_SAMPLE *MENU_Song;
ALLEGRO_SAMPLE *MENU_Click_Song;
ALLEGRO_SAMPLE_INSTANCE *songInstance;

/**
 * @brief Main function to start the game menu.
 *
 */
void game_window (void);
