/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_tower.c
*/

#include <stdlib.h>
#include "defender.h"

static int build_tower(items_t **it, sfVector2f decal)
{
    sfIntRect text_rect = {0, 0, 100, 120};
    char path[] = "assets/textures/tower.png";
    int i = 0;

    for (; i < 6; i++) {
        if (i == 3) {
            it[0]->pos[i].x = decal.x;
            it[0]->pos[i].y = decal.y + it[0]->offset.y;
        } else if (i != 0) {
            it[0]->pos[i].x = it[0]->pos[i - 1].x + it[0]->offset.x;
            it[0]->pos[i].y = it[0]->pos[i - 1].y;
        }
        it[0]->rect[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(it[0]->rect[i], it[0]->size);
        sfRectangleShape_setPosition(it[0]->rect[i], it[0]->pos[i]);
        sfTexture *texture = sfTexture_createFromFile(path, &text_rect);
        sfRectangleShape_setTexture(it[0]->rect[i], texture, sfFalse);
        text_rect.left += 100;
    }
    return (i);
}

void create_tower(items_t **it)
{
    sfVector2f decal = {120, 160};
    int i = 0;

    it[0]->rect = malloc(sizeof(sfRectangleShape *) * 7);
    it[0]->size.x = 100;
    it[0]->size.y = 120;
    it[0]->pos = malloc(sizeof(sfVector2f) * 6);
    it[0]->pos[0].x = 120;
    it[0]->pos[0].y = 150;
    it[0]->offset.x = 120;
    it[0]->offset.y = 130;
    i = build_tower(it, decal);
    it[0]->rect[i] = NULL;
}
