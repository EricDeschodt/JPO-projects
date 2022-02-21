/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** button_handlers
*/

#include "defender.h"

int check_if_return_is_pressed(int i)
{
    if (i == 1 && sfMouse_isButtonPressed(0)) {
        WAIT_FOR_BUTTON_RELEASE;
        return (1);
    }
    return (0);
}

void check_if_sound_interacted(menu_t *s_mn, menu_t *mn,     \
                                    int i, sfVector2f c)
{
    sfVector2f slider_pos = s_mn->pos[0];
    if (i != 0) return;

    if (sfMouse_isButtonPressed(0)) {
        if (c.x < 180 + 600 - 25) {
            slider_pos.x = c.x;
            sfRectangleShape_setPosition(s_mn->slide->slider, slider_pos);
        }
        set_menu_volume(s_mn, mn);
    }
}
