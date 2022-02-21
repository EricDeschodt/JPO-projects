/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** magic_item
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void magic_item_5(protagonist_t *player)
{
    int pm_max = ((player->lvl - 1) * 5) + 10;

    for (int i = 0; i < 5; i++) {
        if (player->pm >= pm_max)
            break;
        player->pm++;
    }
}

void magic_item_15(protagonist_t *player)
{
    int pm_max = ((player->lvl - 1) * 5) + 10;

    for (int i = 0; i < 15; i++) {
        if (player->pm >= pm_max)
            break;
        player->pm++;
    }
}

void magic_item_30(protagonist_t *player)
{
    int pm_max = ((player->lvl - 1) * 5) + 10;

    for (int i = 0; i < 30; i++) {
        if (player->pm >= pm_max)
            break;
        player->pm++;
    }
}

void magic_item_max(protagonist_t *player)
{
    int pm_max = ((player->lvl - 1) * 5) + 10;

    for ( ; player->pm < pm_max; player->pm++);
}
