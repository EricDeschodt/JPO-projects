/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** init_object
*/

#include <stdlib.h>
#include "defender.h"

static clone_t *handle_body(sfVector2f pos, sfVector2f size, char *path)
{
    sfTexture *texture;
    clone_t *body;

    body = malloc(sizeof(clone_t));
    texture = sfTexture_createFromFile(path, NULL);
    body->rect = create_rectangle(pos, size, texture, sfTrue);
    return (body);
}

health_t *handle_health_bar(sfVector2f pos, sfVector2f size)
{
    sfVector2f health_size = {size.x - 18, size.y - 56 };
    sfVector2f size_bg = { health_size.x - 2, health_size.y - 2 };
    sfVector2f pos_bg = { pos.x + 10, pos.y + 2 };
    health_t *health;

    health = malloc(sizeof(health_t));
    pos.x += 9;
    health->bar = create_rectangle(pos_bg, size_bg, NULL, sfTrue);
    health->background = create_rectangle(pos, health_size, NULL, sfTrue);
    sfRectangleShape_setFillColor(health->bar, sfGreen);
    sfRectangleShape_setFillColor(health->background, sfBlack);
    return (health);
}

static stats_t *handle_stats(void)
{
    stats_t *stats;

    stats = malloc(sizeof(stats_t));
    return (stats);
}

obj_t *init_object(sfVector2f pos, sfVector2f size, char *path)
{
    sfFloatRect pos_size = { pos.x, pos.y, size.x, size.y };
    obj_t *obj = NULL;

    obj = malloc(sizeof(obj_t));
    if (path) {
        obj->body = *handle_body(pos, size, path);
        obj->health = *handle_health_bar(pos, size);
    }
    obj->stats = *handle_stats();
    obj->pos_size = pos_size;
    obj->next = NULL;
    obj->prev = NULL;
    return (obj);
}
