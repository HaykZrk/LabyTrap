/**
 * @file main.c
 * @author ZARIKIAN Hayk (hykzrk@gmail.com)
 * @brief Main function.
 * @version 1.0
 * @date 2021-09-26
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/error_handling.h"
#include "../include/keyboard_management.h"
#include "../include/mouse_management.h"
#include "../include/game_window.h"
#include "../include/garbage_collector.h"

/**
 * @brief Main function.
 *
 * @return int
 */
int main()
{
    srand (time(NULL));
    game_window ();
    free_total ();
    return 0;
}
