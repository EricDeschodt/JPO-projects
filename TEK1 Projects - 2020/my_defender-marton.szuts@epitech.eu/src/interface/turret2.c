/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret2
*/

#include "defender.h"

void fill_turret_xp(turret_t *new)
{
    new->xp_bar = sfRectangleShape_create();
    new->under = sfRectangleShape_create();
    sfRectangleShape_setFillColor(new->xp_bar, (sfColor){255, 150, 50, 255});
    sfRectangleShape_setFillColor(new->under, (sfColor){35, 35, 35, 255});
    sfRectangleShape_setPosition(new->xp_bar, new->pos_xp);
    sfRectangleShape_setPosition(new->under, new->pos_xp), new->max = 0;
    sfRectangleShape_setSize(new->xp_bar, (sfVector2f){3, 20});
    sfRectangleShape_setSize(new->under, (sfVector2f){300, 20});
}