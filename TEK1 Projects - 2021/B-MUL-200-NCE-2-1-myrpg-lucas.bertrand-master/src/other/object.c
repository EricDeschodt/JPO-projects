/*
** EPITECH PROJECT, 2020
** graphical
** File description:
** object
*/
#include "../../include/my.h"
#include "../../include/struct.h"

sfVector2f create_v2f(float x, float y)
{
    sfVector2f vec;
    vec.x = x;
    vec.y = y;
    return (vec);
}

sfIntRect create_rect_int(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

object_t *create_object(char *path_to_spritesheet, sfVector2f pos,
                                  sfIntRect rect, sfVector2f scale)
{
    object_t *new = malloc(sizeof(object_t));

    new->pos = pos;
    new->rect = rect;
    new->scale = scale;
    new->my_sprite = sfSprite_create();
    new->my_texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    sfSprite_setScale(new->my_sprite, scale);
    sfSprite_setPosition(new->my_sprite, pos);
    sfSprite_setTexture(new->my_sprite, new->my_texture, sfFalse);
    sfSprite_setTextureRect(new->my_sprite, new->rect);
    sfTexture_setSmooth(new->my_texture, sfTrue);
    new->rect_max = new->rect.left + 450;
    return (new);
}

void destroy_object(sfSprite *sprite, sfTexture *texture)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}
