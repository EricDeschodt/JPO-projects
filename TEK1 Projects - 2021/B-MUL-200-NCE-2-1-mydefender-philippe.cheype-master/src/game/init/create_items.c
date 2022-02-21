/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_items.c
*/

#include <stdlib.h>
#include "defender.h"

items_t **create_items(void)
{
    items_t **it;

    it = malloc(sizeof(items_t *) * 4);
    for (int i = 0; i < 3; i++)
        it[i] = malloc(sizeof(items_t));
    it[0]->overlay = create_terrain_overlay();
    create_info(it);
    create_obscur_background(it);
    create_tower(it);
    create_magic(it);
    create_store(it);
    create_stats(it);
    it[3] = NULL;
    return (it);
}
