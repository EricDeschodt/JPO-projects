/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** hit_box3
*/

#include "my.h"

void crouch_fat_hit_box2(all_t *all, dlist_node_t *tmp)
{
    if ((all->pos.pos_michael.x + 190 >= tmp->flying.pos_flying.x
        && all->pos.pos_michael.x + 100 <= tmp->flying.pos_flying.x + 180
        && all->pos.pos_michael.y + 200 >= tmp->flying.pos_flying.y
        && all->pos.pos_michael.y <= tmp->flying.pos_flying.y + 280) &&
        all->my_int.hit_crouch == 1 && tmp->dead == 0) {
        punches_sounds_random(all);
        tmp->flying.rect_flying.height = 440;
        tmp->dead = 1;
        tmp->flying.rect_flying.width = 180;
        tmp->flying.rect_flying.top = 460;
        tmp->flying.rect_flying.left = 800;
        tmp->flying.pos_flying.y = 340;
        sfSprite_setTextureRect(tmp->flying.sprite, tmp->flying.rect_flying);
        sfSprite_setPosition(tmp->flying.sprite, tmp->flying.pos_flying);
    }
}

void crouch_fat_hit_box(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 0) {
        if ((all->pos.pos_michael.x + 190 >= tmp->fat.pos_fat.x -
            (150 * tmp->fat.float_fat) && all->pos.pos_michael.x + 150 <=
            tmp->fat.pos_fat.x && all->pos.pos_michael.y + 200 >=
            tmp->fat.pos_fat.y - (280 * tmp->fat.float_fat)) && all->my_int
            .hit_crouch == 1 && tmp->dead == 0) {
            punches_sounds_random(all);
            tmp->fat.rect_fat.top = 1349, tmp->dead = 1;
            tmp->fat.rect_fat.left = 900;
            sfSprite_setTextureRect(tmp->fat.sprite, tmp->fat.rect_fat);
        }
    }
    else if (tmp->who == 1) {
        crouch_fat_hit_box2(all, tmp);
    }
}

void michael_axe1_hit_box_jump2(all_t *all, dlist_node_t *tmp, float rotate)
{
    if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x + 180
        && all->pos.pos_michael.x <= tmp->traps.pos_traps.x + 145
        && all->pos.pos_michael.y + 200 >= tmp->traps.pos_traps.y - 50
        && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 50)
        && all->my_int.jump == 1 && (rotate >= 240 && rotate <= 300))
        hit_box_stat(all), sfSound_play(all->sound.scream);
}

void michael_axe1_hit_box_jump(all_t *all, dlist_node_t *tmp, float rotate)
{
    if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x - 180
        && all->pos.pos_michael.x <= tmp->traps.pos_traps.x - 145
        && all->pos.pos_michael.y + 200 >= tmp->traps.pos_traps.y - 50
        && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 50)
        && all->my_int.jump == 1 && (rotate >= 60 && rotate <= 120))
        hit_box_stat(all), sfSound_play(all->sound.scream);
    if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x - 25
        && all->pos.pos_michael.x <= tmp->traps.pos_traps.x + 25
        && all->pos.pos_michael.y + 200 >= tmp->traps.pos_traps.y - 185
        && all->pos.pos_michael.y <= tmp->traps.pos_traps.y - 145)
        && all->my_int.jump == 1 && (rotate >= 150 && rotate <= 210))
        hit_box_stat(all), sfSound_play(all->sound.scream);
    michael_axe1_hit_box_jump2(all, tmp, rotate);
}

void michael_spikes_hit_box(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 8) {
        if ((all->pos.pos_michael.x + 80 >= tmp->traps.pos_traps.x + 5
            && all->pos.pos_michael.x <= tmp->traps.pos_traps.x + 135
            && all->pos.pos_michael.y + 260 >= tmp->traps.pos_traps.y
            && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 45))
            hit_box_stat(all), sfSound_play(all->sound.scream);
        if ((all->pos.pos_michael.x + 80 >= tmp->traps.pos_traps.x
            && all->pos.pos_michael.x <= tmp->traps.pos_traps.x + 140
            && all->pos.pos_michael.y + 170 >= tmp->traps.pos_traps.y
            && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 50))
            hit_box_stat(all), sfSound_play(all->sound.scream);
    }
}