/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** if_duck_overlap
*/

#include "my.h"

void duck_overlap2(all_t *all)
{
    if ((all->pos.pos_duck_bot2.x >= all->pos.pos_duck_bot.x
        && all->pos.pos_duck_bot2.x <= all->pos.pos_duck_bot.x + 80) &&
        (all->pos.pos_duck_bot2.y >= all->pos.pos_duck_bot.y
        && all->pos.pos_duck_bot2.y <= all->pos.pos_duck_bot.y + 70)) {
        all->pos.pos_duck_bot2.y = 460;
        all->pos.pos_duck_bot2.x = 50 + rand() % 700;
    }
}

void duck_overlap(all_t *all)
{
    if ((all->pos.pos_duck2.x >= all->pos.pos_duck.x
        && all->pos.pos_duck2.x <= all->pos.pos_duck.x + 80) &&
        (all->pos.pos_duck2.y >= all->pos.pos_duck.y
        && all->pos.pos_duck2.y <= all->pos.pos_duck.y + 70)) {
        all->pos.pos_duck2.x = -130;
        all->pos.pos_duck2.y = rand() % 350;
    }
    if ((all->pos.pos_duck_rev2.x >= all->pos.pos_duck_rev.x
        && all->pos.pos_duck_rev2.x <= all->pos.pos_duck_rev.x + 80) &&
        (all->pos.pos_duck_rev2.y >= all->pos.pos_duck_rev.y
        && all->pos.pos_duck_rev2.y <= all->pos.pos_duck_rev.y + 70)) {
        all->pos.pos_duck_rev2.x = 860;
        all->pos.pos_duck_rev2.y = rand() % 350;
    }
    duck_overlap2(all);
}