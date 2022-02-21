/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_clone.c
*/

#include "defender.h"

void create_clone(items_t **it, int i, int j)
{
    sfVector2f reduce = { 0.5, 0.5 };

    it[0]->temp.rect = sfRectangleShape_create();
    it[0]->temp.rect = sfRectangleShape_copy(it[i]->rect[j]);
    sfRectangleShape_setScale(it[0]->temp.rect, reduce);
    it[0]->temp.index.x = i;
    it[0]->temp.index.y = j;
}
