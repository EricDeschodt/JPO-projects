/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Handles the background
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_BACKGROUND_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_BACKGROUND_H

#include "libs.h"
#include "time.h"
#include <stdlib.h>

typedef struct back {
    sprite_t *background;
    sprite_t *background_planes;
    sprite_t *perso;
    _time_t *time;
} back_ground_t;

back_ground_t *background_create();
void background_display(back_ground_t *back, sfRenderWindow *win);
void background_animate(back_ground_t *b, int mode);
void background_destroy(back_ground_t *back);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_BACKGROUND_H
