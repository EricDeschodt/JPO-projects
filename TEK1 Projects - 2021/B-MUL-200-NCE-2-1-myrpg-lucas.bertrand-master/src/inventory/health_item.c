/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** health_item
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void health_item_10(protagonist_t *player)
{
    int pv_max = ((player->lvl - 1) * 10) + 20;

    for (int i = 0; i < 10; i++) {
        if (player->pv >= pv_max)
            break;
        player->pv++;
    }
}

void health_item_25(protagonist_t *player)
{
    int pv_max = ((player->lvl - 1) * 10) + 20;

    for (int i = 0; i < 25; i++) {
        if (player->pv >= pv_max)
            break;
        player->pv++;
    }
}

void health_item_50(protagonist_t *player)
{
    int pv_max = ((player->lvl - 1) * 10) + 20;

    for (int i = 0; i < 50; i++) {
        if (player->pv >= pv_max)
            break;
        player->pv++;
    }
}

void health_item_max(protagonist_t *player)
{
    int pv_max = ((player->lvl - 1) * 10) + 20;

    for ( ; player->pv < pv_max; player->pv++);
}
