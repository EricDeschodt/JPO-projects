/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** how to play menu
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_HOW_TO_PLAY_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_HOW_TO_PLAY_H

#include "libs.h"

typedef struct {
    text_t *htp_title;
    text_t *htp;
    sprite_t *return_button;
    sprite_t *manual_button;
    int last_mode;
}how_t;

typedef struct {
    text_t *enemies;
    sprite_t *e1;
    sprite_t *e2;
    sprite_t *e3;
    sprite_t *e4;
    sprite_t *e5;
    sprite_t *e6;
    text_t *e1_t;
    text_t *e2_t;
    text_t *e3_t;
    text_t *e4_t;
    text_t *e5_t;
    text_t *e6_t;
    sprite_t *return_button;
    int last_mode;
}manual_t;

how_t *create_htp(void);
void htp_destroy(how_t *htp);
void htp_display(how_t *htp, sfRenderWindow *win);
void manual_destroy(manual_t *manual);
void manual_display(manual_t *manual, sfRenderWindow *win);
manual_t *manual_create(void);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_HOW_TO_PLAY_H
