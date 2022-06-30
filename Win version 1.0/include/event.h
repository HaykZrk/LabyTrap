/**
 * @file event.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Event file.
 * @version 1.0
 * @date 2021-09-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef EVENT_H
#define EVENT_H

#include <allegro5/allegro.h>

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *queue;
ALLEGRO_TIMER *timer;

/**
 * @brief Event registration.
 * 
 */
void register_event (void);

#endif
