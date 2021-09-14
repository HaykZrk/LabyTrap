/**
 * @file error_handling.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Test and error file.
 * @version 0.1
 * @date 2021-08-10
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "../include/error_handling.h"
#include "../include/game_window.h"
#include "../include/event.h"

/**
 * @brief Display of error text.
 *
 * @param[in] txt
 */
void error (const char *txt) {
    ALLEGRO_DISPLAY *d;
    d = al_is_system_installed() ? al_get_current_display() : NULL;
    al_show_native_message_box(d, "Error", txt, NULL, NULL, 0);
    exit(EXIT_FAILURE);
}

/**
 * @brief Initialization test.
 *
 */
void test_init (void) {
    if (!al_init ())
        error ("allegro init");
}

/**
 * @brief Display test.
 *
 */
void test_display (void) {
    if (!display)
        error ("display");
}

/**
 * @brief Mouse test.
 *
 */
void test_mouse (void) {
    if (!al_install_mouse ())
        error("install mouse");
}

/**
 * @brief Keyboard test.
 *
 */
void test_keyboard (void) {
    if (!al_install_keyboard ())
        error ("install clavier");
}

/**
 * @brief Addon primitives test.
 *
 */
void test_primitives (void) {
    if (!al_init_primitives_addon ())
        error ("al_primitives_addon ()");
}

/**
 * @brief Event queue test.
 *
 */
void test_queue (void) {
    if (!queue)
        error("al_create_event_queue()");
}

/**
 * @brief Timer test.
 *
 */
void test_timer (void) {
    if (!timer)
        error ("al_create_timer()");
}

/**
 * @brief Addon ttf test.
 *
 */
void test_ttf (void) {
    if (!al_init_ttf_addon())
        error ("al_init_ttf_addon()");
}

/**
 * @brief Font test.
 *
 * @param[in] font
 */
void test_font (ALLEGRO_FONT *font) {
    if (!font)
        error ("al_load_font()");
}

/**
 * @brief Audio test.
 *
 */
void test_audio (void) {
    if (!al_install_audio ())
        error ("al_install_audio ()");
}

/**
 * @brief Acodec test.
 *
 */
void test_acodec (void) {
    if (!al_init_acodec_addon ())
        error ("al_init_acodec_addon ()");
}

/**
 * @brief Sample song test.
 *
 * @param[in] sample
 */
void test_sample (ALLEGRO_SAMPLE *sample) {
    if (!sample)
        error ("al_load_sample ()");
}

/**
 * @brief Sample instance song test.
 *
 * @param[in] sample_instance
 */
void test_sample_instance (ALLEGRO_SAMPLE_INSTANCE *sample_instance) {
    if (!sample_instance)
        error ("al_create_sample_instance ()");
}

void test_image_flag (ALLEGRO_BITMAP *image) {
    if (!image)
        error ("al_load_bitmap()");
}

