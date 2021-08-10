/**
 * @file mouse_management.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Mouse management file.
 * @version 0.1
 * @date 2021-08-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef MOUSE_MANAGEMENT_H
#define MOUSE_MANAGEMENT_H

#include <allegro5/allegro.h>

/**
 * @brief Function that take mouse, a button of mouse and the number of repeat.
 * 
 * @param[in] mouse 
 * @param[in] btn 
 * @param[in] repeat 
 * @return int 
 */
int is_mouse_pressed (ALLEGRO_MOUSE_STATE *mouse, int btn, int repeat);

#endif
