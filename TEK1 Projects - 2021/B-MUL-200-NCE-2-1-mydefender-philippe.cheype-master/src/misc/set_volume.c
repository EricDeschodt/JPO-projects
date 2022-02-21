/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** set_volume
*/

#include "defender.h"

void set_menu_volume(menu_t *s_mn, menu_t *mn)
{
    sfVector2f volume_pos;
    float volume = 0;

    volume_pos = sfRectangleShape_getPosition(s_mn->slide->slider);
    volume = (volume_pos.x - s_mn->pos[0].x) / 6;
    if (volume < 1.67) volume = 0;
    sfMusic_setVolume(mn->music, volume);
}
