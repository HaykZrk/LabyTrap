/**
 * @file error_handling.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Test and error file.
 * @version 0.1
 * @date 2021-08-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

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

#endif
