/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** create_radius.c
*/

#include <stdlib.h>
#include "defender.h"

static void prepare_radius(game_t *gm, obj_t *obj, sfVector2f center)
{
    sfVector2f rad_size = {1152, 192};
    sfVector2f rad_center;
    sfVector2f size = {32, 64};

    obj->body.index = gm->it[0]->temp.index;
    obj->action = malloc(sizeof(sfCircleShape *) * 2);
    rad_center.x = 633;
    rad_center.y = center.y - 64;
    obj->radius = sfRectangleShape_create();
    sfRectangleShape_setPosition(obj->radius, rad_center);
    sfRectangleShape_setSize(obj->radius, rad_size);
    sfRectangleShape_setFillColor(obj->radius, sfTransparent);
    for (int i = 0; i < 2; i++) {
        obj->action[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(obj->action[i], size);
    }
}

obj_t *create_radius(obj_t *obj, game_t *gm)
{
    sfVector2f center;

    center = sfRectangleShape_getPosition(obj->body.rect);
    prepare_radius(gm, obj, center);
    sfRectangleShape_setPosition(obj->action[0], center);
    center.x += 32;
    sfRectangleShape_setPosition(obj->action[1], center);
    sfRectangleShape_setFillColor(obj->action[0], sfTransparent);
    sfRectangleShape_setFillColor(obj->action[1], sfTransparent);
    return (obj);
}
