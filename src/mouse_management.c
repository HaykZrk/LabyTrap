#include "../include/mouse_management.h"

int is_mouse_pressed (ALLEGRO_MOUSE_STATE *mouse, int btn, int repeat) {

    int res = 0;
    int nbbtn = al_get_mouse_num_buttons();

    if (PRESS == NULL) {
        PRESS = (int*)calloc(nbbtn + 1, sizeof(int));
        memset(PRESS, 0, sizeof(int) * (nbbtn + 1));
    }

    if (btn < nbbtn)
        btn = nbbtn;

    if (al_mouse_button_down (mouse, btn) && PRESS) {
        PRESS[btn]++;
        res = 1;
    }
    else if (!al_mouse_button_down (mouse, btn))
        PRESS[btn] = 0;
    return res;
}
