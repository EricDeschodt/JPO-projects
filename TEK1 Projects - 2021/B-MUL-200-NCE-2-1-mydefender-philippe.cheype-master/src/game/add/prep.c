/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-mydefender-philippe.cheype
** File description:
** prep.c
*/

#include "defender.h"

obj_t *tower_prep(sfVector2f pos, game_t *gm, sfIntRect pos_size)
{
    obj_t *tower;

    sfTexture *texture;
    char tower_path[] = "assets/textures/towers_ss.png";
    sfVector2f size = { 64, 64 };
    char path[] = "assets/textures/missing.png";
    pos = sfRectangleShape_getPosition(gm->it[0]->temp.rect);
    pos = center_pos(pos);
    tower = init_object(pos, size, path);
    tower->stats.row = pos.y;
    tower->body.index = gm->it[0]->temp.index;
    pos_size.top = 64 * gm->it[0]->temp.index.y;
    texture = sfTexture_createFromFile(tower_path, &pos_size);
    sfRectangleShape_setTexture(tower->body.rect, texture, sfTrue);
    return (tower);
}

obj_t *bomb_prep(sfVector2f pos, game_t *gm, sfIntRect pos_size)
{
    sfVector2f size = { 64, 64 };
    obj_t *tower;
    char trap_path[] = "assets/textures/traps_ss.png";
    sfTexture *texture;
    char path[] = "assets/textures/missing.png";
    pos = sfRectangleShape_getPosition(gm->it[0]->temp.rect);
    pos = center_pos(pos);
    tower = init_object(pos, size, path);
    tower->stats.row = pos.y;
    pos_size.top = 64 * gm->it[0]->temp.index.y;
    texture = sfTexture_createFromFile(trap_path, &pos_size);
    sfRectangleShape_setTexture(tower->body.rect, texture, sfTrue);
    tower->body.index = gm->it[0]->temp.index;
    return tower;
}

obj_t *bonus_prep(sfVector2f pos, game_t *gm)
{
    obj_t *tower;
    char path[] = "assets/textures/bomb.png";
    sfVector2f size_text = {320, 320};
    pos = center_pos(pos);
    sfIntRect area = {0, 0, 255, 250}, area_h = {0, 250, 255, 250};
    sfTexture *texture;
    if (gm->it[0]->temp.index.y == 0)
        texture = sfTexture_createFromFile(path, &area);
    else
        texture = sfTexture_createFromFile(path, &area_h);
    pos = sfRectangleShape_getPosition(gm->it[0]->temp.rect);
    pos.x -= 128, pos.y -= 128;
    tower = init_object(pos, size_text, path);
    sfRectangleShape_setTexture(tower->body.rect, texture, sfTrue);
    tower->stats.row = pos.y;
    tower->body.index = gm->it[0]->temp.index;
    return tower;
}