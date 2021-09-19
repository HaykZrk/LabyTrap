#include "../include/level.h"
#include "../include/game_window.h"
#include "../include/event.h"
#include "../include/keyboard_management.h"
#include "../include/mouse_management.h"

void level_1 (void) {
    ALLEGRO_EVENT event;
    al_wait_for_event (queue, &event);

    image_flag_active = 0;
    image_bomb_active = 0;

    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        continuer_level = false;
        continuer = false;
    }

    else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_UP :
                keyy[UP] = true;
                dir = 0;
                break;
            case ALLEGRO_KEY_RIGHT :
                keyy[RIGHT] = true;
                dir = 1;
                break;
            case ALLEGRO_KEY_DOWN :
                keyy[DOWN] = true;
                dir = 2;
                break;
            case ALLEGRO_KEY_LEFT :
                keyy[LEFT] = true;
                dir = 3;
                break;
        }
        cmptimage = 1 - cmptimage;
        image = (dir * 2) + cmptimage;
    }
    else if (event.type == ALLEGRO_EVENT_KEY_UP) {
        switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_UP :
                keyy[UP] = false;
                break;

            case ALLEGRO_KEY_RIGHT :
                keyy[RIGHT] = false;
                break;

            case ALLEGRO_KEY_DOWN :
                keyy[DOWN] = false;
                break;

            case ALLEGRO_KEY_LEFT :
                keyy[LEFT] = false;
                break;
        }
    }
    else if (event.type == ALLEGRO_EVENT_TIMER) {
        al_get_keyboard_state (&key);
        al_get_mouse_state (&mouse);

        if (posx > 670 && posx < 745 && posy < 465 && posy > 420) {
            image_flag_active = 1;
            if (is_key_pressed (&key, ALLEGRO_KEY_SPACE, 1))
                while (continuer_level) {
                    al_stop_sample_instance (songInstance2);
                    victory_level ();
                }
        }
        else
            image_flag_active = 0;

        if (posx > 490 && posx < 570 && posy > 380 && posy < 510) {
            image_bomb_active = 1;
            al_stop_sample_instance (songInstance2);
            al_draw_bitmap (image_explosion, 530, 416, 0);
            al_draw_bitmap (image_explosion, 530, 448, 0);
            al_draw_bitmap (image_explosion, 530, 480, 0);
            al_draw_bitmap (image_explosion, posx, posy, 0);
            al_play_sample (LEVEL_Bomb_Song, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
            al_flip_display ();
            al_rest (1);
            while (continuer_level)
                defeat_level ();
        }


        if ( (posx > 100 && posx < 120 && posy < 230 && posy > 160) ||
             (posx > 160 && posx < 180 && posy < 280 && posy > 120) ||
             (posx > 120 && posx < 140 && posy < 420 && posy > 280) ||
             (posx > 700 && posy < 510 && posy > 420)               ||
             (posx > 60 && posx < 100 && posy < 510 && posy > 280)  ||
             (posx > 600 && posy < 410 && posy > 300)               )
            posx += 0;
        else
            posx += 10 * keyy[RIGHT];

        if ( (posx < 160 && posx > 130 && posy < 230 && posy > 160) ||
             (posx < 60 && posx > 49 && posy < 500 && posy > 145)   ||
             (posx < 120 && posx > 90 && posy < 510 && posy > 280)  ||
             (posx < 410 && posx > 390 && posy < 420 && posy > 280) )
            posx -= 0;
        else
            posx -= 10 * keyy[LEFT];

        if ( (posx < 720 && posx > 40 && posy > 490) ||
             (posx < 130 && posx > 40 && posy > 200 && posy < 220)  ||
             (posx < 210 && posx > 130 && posy > 260 && posy < 300) )
            posy += 0;
        else
            posy += 10 * keyy[DOWN];

        if ( (posx > 40 && posy > 130 && posy < 150 ) ||
             (posx > 40 && posx < 140 && posy > 230 && posy < 250)  ||
             (posx > 130 && posx < 400 && posy > 420 && posy < 440) ||
             (posx > 390 && posx < 650 && posy > 310 && posy < 330) ||
             (posx > 610 && posx < 750 && posy > 430 && posy < 450) )
            posy += 0;
        else
            posy -= 10 * keyy[UP];

        dessine = true;
    }
    if (dessine == true && al_is_event_queue_empty (queue)) {
        al_clear_to_color (WHITE);

        al_draw_textf (arial72, BLACK, 400, 0, ALLEGRO_ALIGN_CENTRE, "LEVEL 1");
        al_draw_bitmap (image_return, 0, 0, 0);
        al_draw_line (0, 90, 800, 90, BLACK, 3);

        al_draw_tinted_bitmap (image_level_1_bg, al_map_rgb(120, 120, 120), 0, 90, 0);
        al_draw_textf (arial15, BLACK, 450, 200, ALLEGRO_ALIGN_LEFT, "THE PROBLEME IS NOT THE PROBLEM");

        al_draw_line (50, 150, 750, 150, BLACK, 5);
        al_draw_line (50, 147, 50, 200, BLACK, 5);
        al_draw_line (50, 250, 50, 540, BLACK, 5);
        al_draw_line (50, 538, 750, 538, BLACK, 5);
        al_draw_line (748, 538, 748, 488, BLACK, 5);
        al_draw_line (748, 438, 748, 150, BLACK, 5);
        al_draw_line (47, 250, 150, 250, BLACK, 5);
        al_draw_line (148, 248, 148, 200, BLACK, 5);
        al_draw_line (210, 148, 210, 310, BLACK, 5);
        al_draw_line (212, 310, 160, 310, BLACK, 5);
        al_draw_line (163, 310, 163, 438, BLACK, 5);
        al_draw_line (103, 310, 103, 540, BLACK, 5);
        al_draw_line (160, 438, 400, 438, BLACK, 5);
        al_draw_line (650, 438, 750, 438, BLACK, 5);
        al_draw_line (398, 438, 398, 320, BLACK, 5);
        al_draw_line (650, 440, 650, 320, BLACK, 5);
        al_draw_line (395, 320, 652, 320, BLACK, 5);

        al_draw_bitmap (image_bomb, 530, 416, 0);
        al_draw_bitmap (image_bomb, 530, 448, 0);
        al_draw_bitmap (image_bomb, 530, 480, 0);


        if (image_flag_active == 0) {
            al_draw_bitmap (image_flag, 710, 448, 0);
        }
        else {
            al_draw_bitmap (image_flag_green, 710, 448, 0);
        }


        if (mouse.x > 0 && mouse.x < 30 && mouse.y > 0 && mouse.y < 30) {
            al_draw_bitmap (image_return_active, 0, 0, 0);
            if (is_mouse_pressed (&mouse, 1, 1)) {
                continuer_level = false;
            }
        }

        al_draw_bitmap (anim[image], posx, posy, 0);
        al_flip_display ();
        dessine = false;
    }
}

void victory_level (void) {
    al_clear_to_color (WHITE);

    ALLEGRO_EVENT event;
    al_wait_for_event (queue, &event);
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        continuer = false;
        continuer_level = false;
    }

    else if (event.type == ALLEGRO_EVENT_TIMER) {
        al_get_keyboard_state (&key);
        al_get_mouse_state (&mouse);

        al_draw_textf (arial72, BLACK, 400, 250, ALLEGRO_ALIGN_CENTRE, "VICTORY");

        al_flip_display ();
        al_rest(2);
        continuer_level = false;
        al_flip_display ();

    }
}

void defeat_level (void) {
    al_clear_to_color (WHITE);

    ALLEGRO_EVENT event;
    al_wait_for_event (queue, &event);
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        continuer = false;
        continuer_level = false;
    }

    else if (event.type == ALLEGRO_EVENT_TIMER) {
        al_get_keyboard_state (&key);
        al_get_mouse_state (&mouse);

        al_draw_textf (arial72, BLACK, 400, 250, ALLEGRO_ALIGN_CENTRE, "DEFEAT");

        al_flip_display ();
        al_rest(2);
        continuer_level = false;
        al_flip_display ();
    }
}
