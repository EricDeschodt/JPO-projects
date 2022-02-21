/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_obsuce.c
*/

#include "defender.h"

void create_obscur_background(items_t **it)
{
    sfVector2f size = { 1920, 1080 };
    sfVector2f pos = { 0, 0 };
    sfColor color = { 0, 0, 0, 200};

    it[0]->filter = sfRectangleShape_create();
    sfRectangleShape_setSize(it[0]->filter, size);
    sfRectangleShape_setPosition(it[0]->filter, pos);
    sfRectangleShape_setFillColor(it[0]->filter, color);
}
