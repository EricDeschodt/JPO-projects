/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** hit_box2
*/

#include "my.h"

void michael_fat_hit_box(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 0) {
        if ((all->pos.pos_michael.x + 90 >= tmp->fat.pos_fat.x - (150 *
            tmp->fat.float_fat) && all->pos.pos_michael.x <= tmp->fat
            .pos_fat.x && all->pos.pos_michael.y + 273 >= tmp->fat.pos_fat.y -
            (280 * tmp->fat.float_fat) && all->pos.pos_michael.y
            <= tmp->fat.pos_fat.y) && tmp->dead == 0 && all->my_int.jump != 1)
            hit_box_stat(all), sfSound_play(all->sound.scream);
        if ((all->pos.pos_michael.x + 100 >= tmp->fat.pos_fat.x - (150 *
            tmp->fat.float_fat) && all->pos.pos_michael.x + 20 <= tmp->fat
            .pos_fat.x && all->pos.pos_michael.y + 135 >= tmp->fat.pos_fat.y
            - (280 * tmp->fat.float_fat)) && tmp->dead == 0 && all->my_int
            .jump == 1 && all->my_int.high != 1)
            hit_box_stat(all), sfSound_play(all->sound.scream);
        if ((all->pos.pos_michael.x + 100 >= tmp->fat.pos_fat.x - (150 *
            tmp->fat.float_fat) && all->pos.pos_michael.x + 20 <= tmp->fat
            .pos_fat.x && all->pos.pos_michael.y + 170 >= tmp->fat.pos_fat.y -
            (280 * tmp->fat.float_fat)) && tmp->dead == 0 && all->my_int.jump
            == 1 && all->my_int.high == 1)
            hit_box_stat(all), sfSound_play(all->sound.scream);
    }
}

void michael_flying_hit_box(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 1) {
        if ((all->pos.pos_michael.x + 90 >= tmp->flying.pos_flying.x + 30
            && all->pos.pos_michael.x <= tmp->flying.pos_flying.x + 150
            && all->pos.pos_michael.y + 273 >= tmp->flying.pos_flying.y
            && all->pos.pos_michael.y <= tmp->flying.pos_flying.y + 250)
            && tmp->dead == 0 && all->my_int.jump != 1)
            hit_box_stat(all), sfSound_play(all->sound.scream);
        if ((all->pos.pos_michael.x + 90 >= tmp->flying.pos_flying.x
            && all->pos.pos_michael.x <= tmp->flying.pos_flying.x + 140
            && all->pos.pos_michael.y + 135 >= tmp->flying.pos_flying.y - 20
            && all->pos.pos_michael.y <= tmp->flying.pos_flying.y + 250) &&
            tmp->dead == 0 && all->my_int.jump == 1 && all->my_int.high != 1)
            hit_box_stat(all), sfSound_play(all->sound.scream);
        if ((all->pos.pos_michael.x + 90 >= tmp->flying.pos_flying.x
            && all->pos.pos_michael.x + 20 <= tmp->flying.pos_flying.x + 140
            && all->pos.pos_michael.y + 170 >= tmp->flying.pos_flying.y - 20
            && all->pos.pos_michael.y <= tmp->flying.pos_flying.y + 250) &&
            tmp->dead == 0 && all->my_int.jump == 1 && all->my_int.high == 1)
            hit_box_stat(all), sfSound_play(all->sound.scream);
    }
}

void michael_flying_hit_box2(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 1) {
        if ((all->pos.pos_michael.x + 90 >= tmp->flying.pos_flying.x + 50
            && all->pos.pos_michael.x <= tmp->flying.pos_flying.x + 150
            && all->pos.pos_michael.y + 273 >= tmp->flying.pos_flying.y
            && all->pos.pos_michael.y <= tmp->flying.pos_flying.y + 500)
            && tmp->dead == 2 && all->my_int.jump != 1)
            hit_box_stat(all), sfSound_play(all->sound.scream);
        if ((all->pos.pos_michael.x + 100 >= tmp->flying.pos_flying.x + 20
            && all->pos.pos_michael.x <= tmp->flying.pos_flying.x + 140
            && all->pos.pos_michael.y + 135 >= tmp->flying.pos_flying.y - 20
            && all->pos.pos_michael.y <= tmp->flying.pos_flying.y + 500)
            && tmp->dead == 2 && all->my_int.jump == 1)
            hit_box_stat(all), sfSound_play(all->sound.scream);
    }
}

void michael_axe1_hit_box2(all_t *all, dlist_node_t *tmp, float rotate)
{
    if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x + 180
        && all->pos.pos_michael.x <= tmp->traps.pos_traps.x + 145
        && all->pos.pos_michael.y + 273 >= tmp->traps.pos_traps.y - 50
        && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 50)
        && all->my_int.jump != 1 && (rotate >= 240 && rotate <= 300))
        hit_box_stat(all), sfSound_play(all->sound.scream);
}

void michael_axe1_hit_box(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 3) {
        float rotate = sfSprite_getRotation(tmp->traps.sprite);
        if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x - 180
            && all->pos.pos_michael.x <= tmp->traps.pos_traps.x - 145
            && all->pos.pos_michael.y + 273 >= tmp->traps.pos_traps.y - 50
            && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 50)
            && all->my_int.jump != 1 && (rotate >= 60 && rotate <= 120))
            hit_box_stat(all), sfSound_play(all->sound.scream);
        if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x - 40
            && all->pos.pos_michael.x <= tmp->traps.pos_traps.x + 40
            && all->pos.pos_michael.y + 273 >= tmp->traps.pos_traps.y - 185
            && all->pos.pos_michael.y <= tmp->traps.pos_traps.y - 145)
            && all->my_int.jump != 1 && (rotate >= 150 && rotate <= 210))
            hit_box_stat(all), sfSound_play(all->sound.scream);
        michael_axe1_hit_box2(all, tmp, rotate);
        michael_axe1_hit_box_jump(all, tmp, rotate);
    }
}