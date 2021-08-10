/**
 * @file keyboard_management.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Keyboard management file.
 * @version 0.1
 * @date 2021-08-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "../include/keyboard_management.h"

/**
 * @brief Function that take the keyboard, a key of the keyboard and the number of repeat.
 * 
 * @param[in] key 
 * @param[in] keyboard_key 
 * @param[in] repeat 
 * @return int 
 */
int is_key_pressed (ALLEGRO_KEYBOARD_STATE *key, int keyboard_key, int repeat) {
    static int press[ALLEGRO_KEY_MAX] = {0};
    int res = 0;

    if (al_key_down (key, keyboard_key) && press[keyboard_key] < repeat) {
        press[keyboard_key]++;
        res = 1;
    }

    else if (!al_key_down (key, keyboard_key))
        press[keyboard_key] = 0;
    return res;
}
