/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** hit_box5
*/

#include "my.h"

void michael_balls_hit_box_jump2(all_t *all, dlist_node_t *tmp, float rotate)
{
    if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x + 200
        && all->pos.pos_michael.x <= tmp->traps.pos_traps.x + 160
        && all->pos.pos_michael.y + 200 >= tmp->traps.pos_traps.y - 30
        && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 30)
        && all->my_int.jump == 1 && (rotate >= 240 && rotate <= 300))
        all->my_int.menu = 5, sfSound_play(all->sound.scream);
}

void michael_balls_hit_box_jump(all_t *all, dlist_node_t *tmp, float rotate)
{
    if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x - 200
        && all->pos.pos_michael.x <= tmp->traps.pos_traps.x - 160
        && all->pos.pos_michael.y + 200 >= tmp->traps.pos_traps.y - 30
        && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 30)
        && all->my_int.jump == 1 && (rotate >= 60 && rotate <= 120))
        all->my_int.menu = 5, sfSound_play(all->sound.scream);
    if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x - 30
        && all->pos.pos_michael.x <= tmp->traps.pos_traps.x + 30
        && all->pos.pos_michael.y + 200 >= tmp->traps.pos_traps.y - 200
        && all->pos.pos_michael.y <= tmp->traps.pos_traps.y - 160)
        && all->my_int.jump == 1 && (rotate >= 130 && rotate <= 230))
        all->my_int.menu = 5, sfSound_play(all->sound.scream);
    michael_balls_hit_box_jump2(all, tmp, rotate);
}

void michael_balls_hit_box2(all_t *all, dlist_node_t *tmp, float rotate)
{
    if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x + 200
        && all->pos.pos_michael.x <= tmp->traps.pos_traps.x + 160
        && all->pos.pos_michael.y + 250 >= tmp->traps.pos_traps.y - 30
        && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 30)
        && all->my_int.jump != 1 && (rotate >= 240 && rotate <= 300)) {
        all->my_int.menu = 5, sfSound_play(all->sound.scream);
    }
}

void michael_balls_hit_box(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 4) {
        float rotate = sfSprite_getRotation(tmp->traps.sprite);
        if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x - 200
            && all->pos.pos_michael.x <= tmp->traps.pos_traps.x - 160
            && all->pos.pos_michael.y + 250 >= tmp->traps.pos_traps.y - 30
            && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 30)
            && all->my_int.jump != 1 && (rotate >= 60 && rotate <= 120)) {
            hit_box_stat(all), sfSound_play(all->sound.scream);
        }
        if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x - 50
            && all->pos.pos_michael.x <= tmp->traps.pos_traps.x + 50
            && all->pos.pos_michael.y + 270 >= tmp->traps.pos_traps.y - 200
            && all->pos.pos_michael.y <= tmp->traps.pos_traps.y - 160)
            && all->my_int.jump != 1 && (rotate >= 130 && rotate <= 230)) {
            hit_box_stat(all), sfSound_play(all->sound.scream);
        }
        michael_balls_hit_box2(all, tmp, rotate);
        michael_balls_hit_box_jump(all, tmp, rotate);
    }
}

void michael_axe2_hit_box(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 6) {
        float rotate = sfSprite_getRotation(tmp->traps.sprite);
        if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x - 190
            && all->pos.pos_michael.x <= tmp->traps.pos_traps.x - 155
            && all->pos.pos_michael.y + 273 >= tmp->traps.pos_traps.y - 50
            && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 50)
            && all->my_int.jump != 1 && (rotate >= 60 && rotate <= 120))
            hit_box_stat(all), sfSound_play(all->sound.scream);
        if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x - 50
            && all->pos.pos_michael.x <= tmp->traps.pos_traps.x + 50
            && all->pos.pos_michael.y + 273 >= tmp->traps.pos_traps.y - 190
            && all->pos.pos_michael.y <= tmp->traps.pos_traps.y - 155)
            && all->my_int.jump != 1 && (rotate >= 130 && rotate <= 230))
            all->my_int.menu = 5, sfSound_play(all->sound.scream);
        michael_axe2_hit_box2(all, tmp, rotate);
    }
}