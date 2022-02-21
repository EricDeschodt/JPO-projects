/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** init_slider
*/

#include "defender.h"

void set_slider_sizes(menu_t *s_mn, menu_t *mn)
{
    sfVector2f size = sfRectangleShape_getSize(s_mn->slide->slider);
    sfVector2f vol_pos;
    float volume;

    volume = sfMusic_getVolume(mn->music);
    vol_pos = sfRectangleShape_getPosition(s_mn->slide->slider);
    vol_pos.x += volume * 6;
    sfRectangleShape_setPosition(s_mn->slide->slider, vol_pos);
    s_mn->pos[2] = size;
    s_mn->pos_onclick[2].x = s_mn->pos[1].x + (size.x / BTN_HOVER - size.x) / 2;
    s_mn->pos_onclick[2].y = s_mn->pos[1].y + (size.y / BTN_HOVER - size.y) / 2;
    s_mn->pos[2].x = vol_pos.x;
}
