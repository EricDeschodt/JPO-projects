/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** character interactions fnc
*/

#include "../include/character_interactions.h"

bool animate_map(map_t *map, character_t *chr, int v)
{
    map->offset -= (float)v;
    if (map->offset <= -(double)((double)(1080)/7)) {
        map->offset += (float)((double)(1080)/7);
        map->rang++;
    }
    if (get_crn_blk(map, chr, 3, 0) == -1 || get_crn_blk(map, chr, 1, 0) ==
    -1 || get_crn_blk(map, chr, 3, 0) == 1 || get_crn_blk(map, chr, 1, 0) == 1)
        return false;
    return true;
}

short get_block(map_t *map, float y, float x)
{
    int int_y = (int)((7 * y) / 1080);
    int int_x = (int)((7 * (x - map->offset)) / 1080) + map->rang;
    if (int_y > 6)
        return -1;
    else if (int_y < 0)
        return 0;
    if (int_x >= map->x && int_y == 6)
        return 1;
    else if (int_x >= map->x && 0 <= int_y && int_y <= 5)
        return 0;
    char block = map->tab[int_y][int_x];
    if ('A' > block || block > 'S')
        return 0;
    else if ('A' <= block && block <= 'P')
        return 1;
    else
        return -1;
}

short get_crn_blk(map_t *map, character_t *chr, short corner, bool should_below)
{
    sfVector2f pos = sfSprite_getPosition(chr->sprite);
    sfIntRect rect = sfSprite_getTextureRect(chr->sprite);
    float x = (corner % 2 == 0)?pos.x - (float)(rect.width):pos.x;
    float y = (corner < 2)?pos.y - (float)(rect.height):pos.y;
    y += (should_below)?1:0;
    return get_block(map, y, x);
}

bool chr_fix_and_check(map_t *map, character_t *ch)
{
    sfVector2f pos = sfSprite_getPosition(ch->sprite);
    if (get_crn_blk(map, ch, 3, 0) == 1 || get_crn_blk(map, ch, 2, 0) == 1) {
        pos.y = round_coord(pos.y) - 1;
        sfSprite_setPosition(ch->sprite, pos);
    }
    if (get_crn_blk(map, ch, 0, 0) == -1 || get_crn_blk(map, ch, 1, 0) == -1 ||
    get_crn_blk(map, ch, 2, 0) == -1 || get_crn_blk(map, ch, 3, 0) == -1 ||
    get_crn_blk(map, ch, 0, 0) == 1 || get_crn_blk(map, ch, 1, 0) == 1)
        return false;
    pos = sfSprite_getPosition(ch->sprite);
    sfIntRect rect = sfSprite_getTextureRect(ch->sprite);
    if (get_block(map, pos.y + 1, pos.x) == 1 || get_block(map, pos.y + 1,
    pos.x - (float)(rect.width)) == 1)
        ch->pos = pos.y;
    return true;
}

bool chr_apply_gravity(map_t *map, character_t *ch, float v, float angle)
{
    if ((get_crn_blk(map, ch, 2, 1) == 1 || get_crn_blk(map, ch, 3, 1) == 1)
    && !ch->is_jumping)
        return true;
    sfVector2f moove = {0, 0};
    if (ch->is_jumping) {
        if (sfSprite_getPosition(ch->sprite).y < ch->pos - (1080.0/7) * 2.1) {
            ch->pos = (float) (ch->pos - (1080.0 / 7) * 2.1);
            ch->is_jumping = false;
            sfVector2f pos = {(float)((1080.0 / 7) * 2), ch->pos};
            sfSprite_setPosition(ch->sprite, pos);
            return true;
        }
        moove.y = (float)(-(((sfSprite_getPosition(ch->sprite).y) - (ch->pos -
        ((1080.0/7) * 2 + (1080.0/7) * angle))) / 300) * v);
    } else
        moove.y = (float) -((1 - (((sfSprite_getPosition(ch->sprite).y) -
        (ch->pos - ((1080.0/7) * 2.1 + (1080.0/7) * angle))) / 300)) * v);
    sfSprite_move(ch->sprite, moove);
    return chr_fix_and_check(map, ch);
}
