/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** settings2
*/

#include "defender.h"

void set_eric_skin(all_t *s_all)
{
    tuto_t *tmp = s_all->s_wave_c.round;
    if (s_all->s_settings->eric == 1) {
        for (; tmp != NULL; tmp = tmp->next)
            sfSprite_setTexture(tmp->sprite, s_all->s_wave_c.eric, sfTrue);
    } else
        for (; tmp != NULL; tmp = tmp->next)
            sfSprite_setTexture(tmp->sprite, s_all->s_wave_c.one, sfTrue);
}