/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** sidebar
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_SIDEBAR_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_SIDEBAR_H

#include "../libs.h"

typedef struct {
    sfSprite *turret_image;
    sprite_t *upgrade;
    sprite_t *adds;
    sprite_t *upgrade_b;
    sprite_t *delete_b;
    text_t *dps_text;
    text_t *ad_text;
    text_t *range_text;
    text_t *cost_text;
    text_t *turret_text;
    text_t *up_dmg_text;
    text_t *d_dps_text;
    char *d_dps_str;
    char *up_dmg_str;
    char *dps_str;
    char *ad_str;
    char *range_str;
    char *cost_str;
} upgrade_t;

typedef struct {
    sprite_t *fond;
    sprite_t *shop;
    sprite_t *pause_button;
    radio_buttons_t *turrets;
    text_t *hp_text;
    text_t *gold_text;
    text_t *wave_text;
    char *hp_str;
    char *gold_str;
    char *wave_str;
    upgrade_t *upgrade;
} sidebar_t;

void sidebar_destroy(sidebar_t *sidebar);
sidebar_t *sidebar_create();
upgrade_t *upgrade_create();
void upgrade_destroy(upgrade_t *u);
void sidebar_text_set_o(upgrade_t *up);
void upgrade_display(upgrade_t *u, sfRenderWindow * win, bool upgraded);


#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_SIDEBAR_H
