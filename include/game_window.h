#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <allegro5/allegro.h>

#define NOIR al_map_rgb (0, 0, 0)
#define BLANC al_map_rgb (255, 255, 255)
#define ORANGE al_map_rgb (255, 57, 0)

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *queue;
ALLEGRO_TIMER *timer;


void game (void);
