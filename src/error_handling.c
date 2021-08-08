#include "../include/error_handling.h"

void error (const char *txt) {
    ALLEGRO_DISPLAY *d;
    d = al_is_system_installed() ? al_get_current_display() : NULL;
    al_show_native_message_box(d, "Error", txt, NULL, NULL, 0);
    exit(EXIT_FAILURE);
}
