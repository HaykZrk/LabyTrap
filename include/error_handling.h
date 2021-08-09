#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

#include <allegro5/allegro_primitives.h>


void error (const char *txt);

void test_init (void);

void test_display (void);

void test_mouse (void);

void test_keyboard (void);

void test_primitives (void);

void test_queue (void);

void test_timer (void);

#endif
