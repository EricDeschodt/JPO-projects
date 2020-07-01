/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** hit_box4
*/

#include "my.h"

void punches_sounds_random(all_t *all)
{
    if (all->my_int.menu == 0) {
        all->my_int.jump_sound = rand() % 5;
        if (all->my_int.jump_sound == 0)
            sfSound_play(all->sound.upper_cut);
        if (all->my_int.jump_sound == 1)
            sfSound_play(all->sound.left_hook);
        if (all->my_int.jump_sound == 2)
            sfSound_play(all->sound.right_cross);
        if (all->my_int.jump_sound == 3)
            sfSound_play(all->sound.right_hook);
        if (all->my_int.jump_sound == 4)
            sfSound_play(all->sound.jab);
    }
}

void michael_saw_hit_box(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 5) {
        if ((all->pos.pos_michael.x + 100 >= tmp->traps.pos_traps.x - 70
            && all->pos.pos_michael.x + 40 <= tmp->traps.pos_traps.x + 70
            && all->pos.pos_michael.y + 250 >= tmp->traps.pos_traps.y - 70
            && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 70))
            hit_box_stat(all), sfSound_play(all->sound.scream);
    }
}

void michael_axe2_hit_box2(all_t *all, dlist_node_t *tmp, float rotate)
{
    if ((all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x + 190
        && all->pos.pos_michael.x <= tmp->traps.pos_traps.x + 155
        && all->pos.pos_michael.y + 273 >= tmp->traps.pos_traps.y - 50
        && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 50)
        && all->my_int.jump != 1 && (rotate >= 240 && rotate <= 300))
        hit_box_stat(all), sfSound_play(all->sound.scream);
}

void skull_hit_box(all_t *all, dlist_node_t *tmp)
{
    if (all->pos.pos_michael.x + 90 >= tmp->traps.pos_traps.x
        && all->pos.pos_michael.x <= tmp->traps.pos_traps.x + 52
        && all->pos.pos_michael.y + 273 >= tmp->traps.pos_traps.y
        && all->pos.pos_michael.y <= tmp->traps.pos_traps.y + 65) {
        if (all->my_int.menu == 0) sfSound_play(all->sound.skull);
        tmp->dead = 1, all->my_int.skull *= 2;
    } if (all->pos.pos_hat.x + 70 >= tmp->traps.pos_traps.x
        && all->pos.pos_hat.x <= tmp->traps.pos_traps.x + 62
        && all->pos.pos_hat.y + 30 >= tmp->traps.pos_traps.y
        && all->pos.pos_hat.y <= tmp->traps.pos_traps.y + 75
        && all->my_int.hat == 1 && tmp->dead == 0) {
        if (all->my_int.menu != 1) sfSound_play(all->sound.skull);
        if (all->my_int.up_throw == 1)
            all->my_int.hit_time = 20 + (20 - all->my_int.hit_time);
        else if (all->my_int.down_throw == 1)
            all->my_int.hit_time = 17 + (17 - all->my_int.hit_time);
        tmp->dead = 1, all->my_int.skull *= 2;
    }
}