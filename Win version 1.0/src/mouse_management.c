/**
 * @file mouse_management.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief  Mouse management file.
 * @version 1.0
 * @date 2021-09-26
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "../include/mouse_management.h"

/**
 * @brief Function that take mouse, a button of mouse and the number of repeat.
 *
 * @param[in] mouse
 * @param[in] btn
 * @param[in] repeat
 * @return int
 */
int is_mouse_pressed (ALLEGRO_MOUSE_STATE *mouse, int btn, int repeat) {
    int res = 0;
    int nbbtn = al_get_mouse_num_buttons();
    int static PRESS[5];

    /*if (PRESS == NULL) {
        PRESS = (int*)calloc(nbbtn + 1, sizeof(int));
        memset (PRESS, 0, sizeof(int) * (nbbtn + 1));
    }*/

    if (btn > nbbtn)
        btn = nbbtn;

    if (al_mouse_button_down (mouse, btn) && PRESS[btn] < repeat) {
        PRESS[btn]++;
        res = 1;
    }
    else if (!al_mouse_button_down (mouse, btn))
        PRESS[btn] = 0;

    return res;
}
