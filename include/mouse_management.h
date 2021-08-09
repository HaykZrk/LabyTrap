#ifndef MOUSE_MANAGEMENT_H
#define MOUSE_MANAGEMENT_H

#include <allegro5/allegro.h>

static int *PRESS = NULL;

int is_mouse_pressed (ALLEGRO_MOUSE_STATE *mouse, int btn, int repeat);

#endif
