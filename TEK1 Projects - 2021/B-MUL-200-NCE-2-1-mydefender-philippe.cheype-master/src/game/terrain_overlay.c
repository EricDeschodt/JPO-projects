/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** terrain_overlay
*/

#include <stdlib.h>
#include "defender.h"

sfRectangleShape ***create_terrain_overlay(void)
{
    sfVector2f pos = { 634, 373 };
    sfVector2f size = { 64, 64 };
    sfRectangleShape ***slots;
    int i = 0, j;

    slots = malloc(sizeof(sfRectangleShape **) * 9);
    for (; i < 8; i++) {
        slots[i] = malloc(sizeof(sfRectangleShape *) * 20);
        pos.x = 634;
        for (j = 0; j < 19; j++) {
            slots[i][j] = sfRectangleShape_create();
            sfRectangleShape_setSize(slots[i][j], size);
            sfRectangleShape_setPosition(slots[i][j], pos);
            pos.x += 64;
        }
        pos.y += 64;
        slots[i][j] = NULL;
    }
    slots[i] = NULL;
    return (slots);
}

static void handle_coloring(items_t **it, int opt, int i, int j)
{
    sfColor my_green = {0, 255, 0, 50}, my_red = {255, 0, 0, 50};

    if (opt == 1) {
        if (j < 5)
            sfRectangleShape_setFillColor(it[0]->overlay[i][j], my_green);
        else
            sfRectangleShape_setFillColor(it[0]->overlay[i][j], my_red);
    } else if (opt == 2) {
        if (j < 5)
            sfRectangleShape_setFillColor(it[0]->overlay[i][j], my_red);
        else
            sfRectangleShape_setFillColor(it[0]->overlay[i][j], my_green);
    } else
            sfRectangleShape_setFillColor(it[0]->overlay[i][j], my_green);
}

void display_terrain_overlay(vars_t *va, items_t **it, int opt)
{

    for (int i = 0; it[0]->overlay[i]; i++) {
        for (int j = 0; it[0]->overlay[i][j]; j++) {
            handle_coloring(it, opt, i, j);
            sfRenderWindow_drawRectangleShape(va->window,   \
                                        it[0]->overlay[i][j], NULL);
        }
    }
}
