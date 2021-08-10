/**
 * @file garbage_collector.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Garbage collector file.
 * @version 0.1
 * @date 2021-08-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "../include/garbage_collector.h"
#include "../include/game_window.h"

/**
 * @brief Memory release.
 * 
 */
void free_total (void) {
    al_destroy_display (display);
    al_destroy_event_queue (queue);
    al_destroy_timer (timer);
}
