/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** create a button (struct sprite_t)
*/

#include "../../include/buttons.h"

sprite_t *button_create(char *texture_name, char const *pos)
{
    sprite_t *button = malloc(sizeof(sprite_t));
    button->texture = texture_create(texture_name, false, false);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfIntRect rect = {0, 0, (int)(sfTexture_getSize(button->texture).x),
    (int)(sfTexture_getSize(button->texture).y / 3)};
    sfSprite_setTextureRect(button->sprite, rect);
    sprite_set_origin(button, pos);
    return button;
}