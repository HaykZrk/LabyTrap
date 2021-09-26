/**
 * @file level.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Level file.
 * @version 1.0
 * @date 2021-09-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef LEVEL_H
#define LEVEL_H

#include <allegro5/allegro.h>

bool continuer_level;
int image_flag_active;
int image_bomb_active;

/**
 * @brief Level 1.
 * 
 */
void level_1 (void);

/**
 * @brief Function of victory level.
 * 
 */
void victory_level (void);

/**
 * @brief Function of defeat level.
 * 
 */
void defeat_level (void);

#endif
