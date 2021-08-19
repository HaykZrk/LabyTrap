/**
 * @file event.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Event file.
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "../include/event.h"

/**
 * @brief Event registration.
 * 
 */
void register_event (void) {

    al_register_event_source (queue, al_get_display_event_source(display));
    al_register_event_source (queue, al_get_keyboard_event_source());
    al_register_event_source (queue, al_get_mouse_event_source());
    al_register_event_source (queue, al_get_timer_event_source(timer));
}
