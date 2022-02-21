/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_store.c
*/

#include <stdlib.h>
#include "defender.h"

static void get_it_values(items_t **it)
{
    it[2]->offset.x = 120;
    it[2]->offset.y = 0;
    it[2]->rect = malloc(sizeof(sfRectangleShape *) * 4);
    it[2]->size.x = 100;
    it[2]->size.y = 120;
    it[2]->pos = malloc(sizeof(sfVector2f) * 3);
    it[2]->pos[0].x = 120;
    it[2]->pos[0].y = 860;
}

void create_store(items_t **it)
{
    char path[] = "assets/textures/bonus.png";
    sfIntRect text_rect = {0, 0, 100, 120};
    int i = 0;

    get_it_values(it);
    for (i = 0; i < 3; i++) {
        if (i != 0) {
            it[2]->pos[i].x = it[2]->pos[i - 1].x + it[2]->offset.x;
            it[2]->pos[i].y = it[2]->pos[i - 1].y;
        }
        it[2]->rect[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(it[2]->rect[i], it[2]->size);
        sfRectangleShape_setPosition(it[2]->rect[i], it[2]->pos[i]);
        sfTexture *texture = sfTexture_createFromFile(path, &text_rect);
        sfRectangleShape_setTexture(it[2]->rect[i], texture, sfFalse);
        text_rect.left += 100;
    }
    it[2]->rect[i] = NULL;
}
