/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_magic.c
*/

#include <stdlib.h>
#include "defender.h"

static void prepare_magic(items_t **it)
{
    it[1]->offset.x = 120;
    it[1]->offset.y = 0;
    it[1]->rect = malloc(sizeof(sfRectangleShape *) * 4);
    it[1]->size.x = 100;
    it[1]->size.y = 120;
    it[1]->pos = malloc(sizeof(sfVector2f) * 3);
    it[1]->pos[0].x = 120;
    it[1]->pos[0].y = 610;
}

void create_magic(items_t **it)
{
    char path[] = "assets/textures/magic.png";
    sfIntRect text_rect = {0, 0, 100, 120};
    int i = 0;

    prepare_magic(it);
    for (i = 0; i < 3; i++) {
        if (i != 0) {
            it[1]->pos[i].x = it[1]->pos[i - 1].x + it[1]->offset.x;
            it[1]->pos[i].y = it[1]->pos[i - 1].y;
        }
        it[1]->rect[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(it[1]->rect[i], it[1]->size);
        sfRectangleShape_setPosition(it[1]->rect[i], it[1]->pos[i]);
        sfTexture *texture = sfTexture_createFromFile(path, &text_rect);
        sfRectangleShape_setTexture(it[1]->rect[i], texture, sfFalse);
        text_rect.left += 100;
    }
    it[1]->rect[i] = NULL;
}
