/**
 * @file main.c
 * @author ZARIKIAN Hayk (hykzrk@gmail.com)
 * @brief Main function.
 * @version 0.1
 * @date 2021-08-10
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

/**
 * @brief Main function.
 * 
 * @return int 
 */
int main()
{
    srand (time(NULL));
    game ();
    return 0;
}
