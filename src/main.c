#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/error_handling.h"
#include "../include/keyboard_management.h"
#include "../include/mouse_management.h"

int main()
{
    // obligatoire pour utiliser allegro
    if(!al_init())
        error("al_init()");

    // un petit message de bienvenue
    al_show_native_message_box(NULL,"Premier programme",
                               "Hello allegro !",NULL,NULL,0);

    return 0;
}
