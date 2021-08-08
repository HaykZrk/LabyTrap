#include "../include/keyboard_management.h"

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
