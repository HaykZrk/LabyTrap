/**
 * @file keyboard_management.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Keyboard management file.
 * @version 0.1
 * @date 2021-08-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef KEYBOARD_MANAGEMENT
#define KEYBOARD_MANAGEMENT

#include <allegro5/allegro.h>

/**
 * @brief Function that take the keyboard, a key of the keyboard and the number of repeat.
 * 
 * @param[in] key 
 * @param[in] keyboard_key 
 * @param[in] repeat 
 * @return int 
 */
int is_key_pressed (ALLEGRO_KEYBOARD_STATE *key, int keyboard_key, int repeat);

#endif
