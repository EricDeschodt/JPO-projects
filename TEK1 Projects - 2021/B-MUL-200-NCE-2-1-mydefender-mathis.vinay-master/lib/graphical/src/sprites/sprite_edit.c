/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Sprite edit functions
*/

#include "../../include/sprites.h"

float get_pos_o(sfSprite *sprite, char pos, char axe)
{
    float res = 0;
    sfFloatRect r = sfSprite_getLocalBounds(sprite);
    if (pos == 'C')
        res = (axe == 'y')?r.height / 2:r.width / 2;
    if (pos == 'N' || pos == 'O' || pos == 'W')
        res = 0;
    if (pos == 'S' || pos == 'E')
        res = (axe == 'y')?r.height:r.width;
    return res;
}

void sprite_set_origin(sprite_t *sprite, char const *pos)
{
    float y = 0;
    float x = 0;
    if (my_strlen(pos) == 2) {
        y = get_pos_o(sprite->sprite, pos[0], 'y');
        x = get_pos_o(sprite->sprite, pos[1], 'x');
    } else if (my_strlen(pos) == 1) {
        y = get_pos_o(sprite->sprite, pos[0], 'y');
        x = get_pos_o(sprite->sprite, pos[0], 'x');
    } else {
        y = get_pos_o(sprite->sprite, 'N', 'y');
        x = get_pos_o(sprite->sprite, 'W', 'x');
    }
    sfVector2f vect = {x, y};
    sfSprite_setOrigin(sprite->sprite, vect);
}

void sprite_set_pos(sprite_t *sprite, float x, float y, float scale)
{
    if (scale != 0.0) {
        sfVector2f scale_vect = {scale, scale};
        sfSprite_setScale(sprite->sprite, scale_vect);
    }
    sfVector2f position = {x, y};
    sfSprite_setPosition(sprite->sprite, position);
}

void sprite_add_pos(sprite_t *sprite, float x, float y, float scale)
{
    sfVector2f act_s = sfSprite_getScale(sprite->sprite);
    sfVector2f scale_vect = {scale + act_s.x, scale + act_s.y};
    sfSprite_setScale(sprite->sprite, scale_vect);
    sfVector2f act_p = sfSprite_getPosition(sprite->sprite);
    sfVector2f position = {x + act_p.x, y + act_p.y};
    sfSprite_setPosition(sprite->sprite, position);
}