#include "../include/error_handling.h"
#include "../include/game_window.h"

void error (const char *txt) {
    ALLEGRO_DISPLAY *d;
    d = al_is_system_installed() ? al_get_current_display() : NULL;
    al_show_native_message_box(d, "Error", txt, NULL, NULL, 0);
    exit(EXIT_FAILURE);
}

void test_init (void) {
    if (!al_init ())
        error ("allegro init");
}

void test_display (void) {
    if (!display)
        error ("display");
}

void test_mouse (void) {
    if (!al_install_mouse ())
        error("install mouse");
}

void test_keyboard (void) {
    if (!al_install_keyboard ())
        error ("install clavier");
}

void test_primitives (void) {
    if (!al_init_primitives_addon ())
        error ("al_primitives_addon ()");
}

void test_queue (void) {
    if (!queue)
        error("al_create_event_queue()");
}

void test_timer (void) {
    if (!timer)
        error ("al_create_timer()");
}
