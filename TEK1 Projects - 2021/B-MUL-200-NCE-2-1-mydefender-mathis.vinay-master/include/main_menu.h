/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** structure for the main menu
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_MAIN_MENU_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_MAIN_MENU_H

#include "../lib/graphical/include/graphical.h"

typedef struct {
    sprite_t *logo;
    sprite_t *play_button;
    sprite_t *exit_button;
    text_t *credits;
    sprite_t *setting_b;
} main_menu_t;

main_menu_t *main_menu_create();
void main_menu_display(main_menu_t *menu, sfRenderWindow *win);
void main_menu_destroy(main_menu_t *menu);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_MAIN_MENU_H
