/**
 * @file game_window.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Game file.
 * @version 1.0
 * @date 2021-09-26
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef GAME_WINDOW
#define GAME_WINDOW

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

#define BLACK al_map_rgb (0, 0, 0)
#define WHITE al_map_rgb (255, 255, 255)
#define ORANGE al_map_rgb (255, 57, 0)
#define GREY al_map_rgba (90, 90, 90, 150)

enum {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    KEYMAX
};

bool dessine;
bool keyy[KEYMAX];
int dir, cmptimage, image;
int posx, posy;
char nom[256];

bool continuer;
bool play;

int x, y;
int owl_go;

int active_level;

ALLEGRO_MOUSE_STATE mouse;
ALLEGRO_KEYBOARD_STATE key;

ALLEGRO_FONT *arial72;
ALLEGRO_FONT *arial15;
ALLEGRO_FONT *arial30;

ALLEGRO_BITMAP *image_owl_face;
ALLEGRO_BITMAP *image_owl_go_right_left;
ALLEGRO_BITMAP *image_return;
ALLEGRO_BITMAP *image_return_active;
ALLEGRO_BITMAP *image_flag;
ALLEGRO_BITMAP *image_flag_green;
ALLEGRO_BITMAP *anim[8];

ALLEGRO_BITMAP *image_bomb;
ALLEGRO_BITMAP *image_explosion;
ALLEGRO_BITMAP *image_level_1_bg;

ALLEGRO_SAMPLE *MENU_Song;
ALLEGRO_SAMPLE *MENU_Click_Song;
ALLEGRO_SAMPLE *LEVEL_Bomb_Song;
ALLEGRO_SAMPLE *LEVEL_1_Song;

ALLEGRO_SAMPLE_INSTANCE *songInstance;
ALLEGRO_SAMPLE_INSTANCE *songInstance2;

/**
 * @brief Main function to start the game menu.
 *
 */
void game_window (void);

#endif
