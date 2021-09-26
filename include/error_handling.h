/**
 * @file error_handling.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Test and error file.
 * @version 1.0
 * @date 2021-09-26
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include "game_window.h"
#include "menu.h"

/**
 * @brief Display of error text.
 *
 * @param[in] txt
 */
void error (const char *txt);

/**
 * @brief Initialization test.
 *
 */
void test_init (void);

/**
 * @brief Display test.
 *
 */
void test_display (void);

/**
 * @brief Mouse test.
 *
 */
void test_mouse (void);

/**
 * @brief Keyboard test.
 *
 */
void test_keyboard (void);

/**
 * @brief Addon primitives test.
 *
 */
void test_primitives (void);

/**
 * @brief Event queue test.
 *
 */
void test_queue (void);

/**
 * @brief Timer test.
 *
 */
void test_timer (void);

/**
 * @brief Addon ttf test.
 *
 */
void test_ttf (void);

/**
 * @brief Font test.
 *
 */
void test_font (ALLEGRO_FONT *font);

/**
 * @brief Audio test.
 *
 */
void test_audio (void);

/**
 * @brief Acodec test.
 *
 */
void test_acodec (void);

/**
 * @brief Sample song test.
 *
 * @param[in] sample
 */
void test_sample (ALLEGRO_SAMPLE *sample);

/**
 * @brief Sample instance song test.
 *
 * @param[in] sample_instance
 */
void test_sample_instance (ALLEGRO_SAMPLE_INSTANCE *sample_instance);

/**
 * @brief Bitmap test.
 * 
 * @param[in] image 
 * @param[in] name
 */
void test_image (ALLEGRO_BITMAP *image, char name[]);

#endif
