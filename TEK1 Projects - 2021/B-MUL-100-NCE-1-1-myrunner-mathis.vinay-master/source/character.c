/*
** EPITECH PROJECT, 2020
** bootstrap graphique lourd
** File description:
** functions to handle ducks
*/

#include "../include/character.h"

character_t *create_character(char const *filename)
{
    character_t *chr = malloc(sizeof(character_t));
    chr->texture = sfTexture_createFromFile(filename, NULL);
    chr->sprite = sfSprite_create();
    sfSprite_setTexture(chr->sprite, chr->texture, sfTrue);
    sfIntRect text_rect = {0, 0, 98, 153};
    sfSprite_setTextureRect(chr->sprite, text_rect);
    sfIntRect image_t = sfSprite_getTextureRect(chr->sprite);
    sfVector2f image_o_f = {(float)image_t.width,
    (float)image_t.height};
    sfSprite_setOrigin(chr->sprite, image_o_f);
    sfVector2f pos = {(float)(1080.0/7) * 2, (float)(1080.0/7) * 6 - 1};
    sfSprite_setPosition(chr->sprite, pos);
    chr->is_jumping = false;
    chr->pos = (float)(1080.0/7) * 6 - 1;
    return chr;
}

bool change_frame(character_t *chr)
{
    if (chr->is_jumping) {
        sfIntRect text_rect = {136, 155, 98, 158};
        sfSprite_setTextureRect(chr->sprite, text_rect);
        return true;
    }
    int pos = (sfSprite_getTextureRect(chr->sprite).top != 0)
    ?-98:sfSprite_getTextureRect(chr->sprite).left;
    pos += 98;
    if (pos >= 588)
        pos = 0;
    sfIntRect text_rect = {pos, 0, 98, 153};
    sfSprite_setTextureRect(chr->sprite, text_rect);
    return true;
}

float round_coord(float n)
{
    return (float)(((int)((7 * n) / 1080)) * (double)(1080.0/7));
}

void destroy_character(character_t *chr)
{
    sfTexture_destroy(chr->texture);
    sfSprite_destroy(chr->sprite);
    free(chr);
}
