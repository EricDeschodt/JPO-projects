/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** create a sprite
*/

#include "../../include/sprites.h"

sprite_t *sprite_create(char const *filepath, char const *pos,
                            bool is_repeted, bool is_smooth)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sprite->texture = texture_create(filepath, is_repeted, is_smooth);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sprite_set_origin(sprite, pos);
    return sprite;
}