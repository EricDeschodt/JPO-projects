/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** functions to quickly edit texture rect
*/

#include "../../include/sprites.h"

void sprite_set_texturerect_pos(sprite_t *sprite, int x, int y)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite->sprite);
    rect.top = y;
    rect.left = x;
    sfSprite_setTextureRect(sprite->sprite, rect);
}

void sprite_add_texturerect_pos(sprite_t *sprite, int x, int y)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite->sprite);
    rect.top += y;
    rect.left += x;
    sfSprite_setTextureRect(sprite->sprite, rect);
}

void sprite_set_texturerect_size(sprite_t *sprite, int x, int y)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite->sprite);
    rect.height = y;
    rect.width = x;
    sfSprite_setTextureRect(sprite->sprite, rect);
}

void sprite_add_texturerect_size(sprite_t *sprite, int x, int y)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite->sprite);
    rect.height += y;
    rect.width += x;
    sfSprite_setTextureRect(sprite->sprite, rect);
}