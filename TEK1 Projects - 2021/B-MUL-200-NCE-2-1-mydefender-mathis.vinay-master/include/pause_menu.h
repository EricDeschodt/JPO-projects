/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** handles the pause menu
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_PAUSE_MENU_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_PAUSE_MENU_H

#include "../include/libs.h"

typedef struct {
    sprite_t *cadre;
    sprite_t *resume_button;
    sprite_t *restart_button;
    sprite_t *main_menu_button;
    sprite_t *exit_button;
    sprite_t *pause_logo;
    sprite_t *shade;
    sprite_t *htp_button;
    sprite_t *setting_b;
}pause_menu_t;

void pause_menu_destroy(pause_menu_t *pause_menu);
void pause_menu_display(pause_menu_t *pause_menu, sfRenderWindow *win);
pause_menu_t *pause_menu_create(void);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_PAUSE_MENU_H
