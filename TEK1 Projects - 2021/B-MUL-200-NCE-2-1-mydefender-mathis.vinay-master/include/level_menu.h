/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** handle the level selecting menu
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_LEVEL_MENU_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_LEVEL_MENU_H

#include <stdlib.h>
#include "../include/libs.h"
#include "../include/time.h"
#include "levels.h"

typedef struct {
    sprite_t *button_left;
    sprite_t *button_right;
    sprite_t *button_return;
    sprite_t *button_select;
    sprite_t *button_score;
    sprite_t *htp_button;
    sprite_t *shadow;
    _time_t *time;
    levels_t *lvl;
}level_menu_t;

level_menu_t *level_menu_create();
void level_menu_init(level_menu_t *menu);
void level_menu_display(level_menu_t *level_menu, sfRenderWindow *win);
void level_menu_destroy(level_menu_t *level_menu);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_LEVEL_MENU_H
