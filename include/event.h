/**
 * @file event.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Event file.
 * @version 0.1
 * @date 2021-08-19
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

#endif // EVENT_H
