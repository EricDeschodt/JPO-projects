/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Map
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_LEVELS_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_LEVELS_H

#include "../include/libs.h"

typedef struct {
    char **list_lvl;
    int list_index;
    sprite_t *lvl_image;
    text_t *lvl_title_text;
}levels_t;

levels_t *levels_create();
void levels_display(levels_t *lvl, sfRenderWindow *win);
void levels_destroy(levels_t *lvl);
void levels_update(levels_t *lvl);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_LEVELS_H
