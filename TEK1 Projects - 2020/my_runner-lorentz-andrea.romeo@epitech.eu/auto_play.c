/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** auto_play
*/

#include "my.h"

int check_fat_pos(all_t *all)
{
    int fat_pos = 1920, flying_pos = 1920;
    dlist_node_t *tmp = all->mobs->begin;
    while (tmp != NULL) {
        if (tmp->who == 0 && tmp->dead == 0) {
            if (tmp->fat.pos_fat.x >= all->pos.pos_michael.x
            && tmp->fat.pos_fat.x <= fat_pos)
                fat_pos = tmp->fat.pos_fat.x;
        }
        else if (tmp->who == 1 && tmp->dead < 3) {
            if (tmp->flying.pos_flying.x >= all->pos.pos_michael.x
            && tmp->flying.pos_flying.x <= flying_pos)
                flying_pos = tmp->flying.pos_flying.x;
        }
        tmp = tmp->next;
    }
    if (fat_pos - 300 <= flying_pos)
        return (1);
    else if (flying_pos < fat_pos - 300)
        return (0);
    return (1);
}

int check_traps_pos(all_t *all)
{
    int traps_pos = 1920;
    dlist_node_t *tmp = all->mobs->begin;
    while (tmp != NULL) {
        if ((tmp->who >= 2 && tmp->who <= 6) || tmp->who == 8) {
            if (tmp->traps.pos_traps.x >= all->pos.pos_michael.x
                && tmp->traps.pos_traps.x <= traps_pos)
                traps_pos = tmp->traps.pos_traps.x;
            }
        tmp = tmp->next;
    }
    if (traps_pos <= all->pos.pos_michael.x + 600)
        return (1);
    else
        return (0);
}

void auto_hit3(all_t *all, dlist_node_t *tmp, int check, int check_traps)
{
    if (tmp->who == 1 && tmp->dead == 0) {
        if (tmp->flying.pos_flying.x <= all->pos.pos_michael.x + 1600
            && tmp->flying.pos_flying.x >= all->pos.pos_michael.x + 400
            && all->my_int.hit != 1 && all->my_int.up_throw != 1 &&
            check == 0 && check_traps == 0 && all->my_int.jump != 1)
            all->my_int.up_throw = 1, sound_random(all);
        else if (all->my_int.up_throw != 1 && all->my_int.hit != 1 &&
            tmp->flying.pos_flying.x <= all->pos.pos_michael.x + 200)
            all->my_int.hit = 1, sound_random(all);
    }
    if (tmp->who == 2 && all->my_int.jump != 1 && tmp->traps.pos_traps.x
        <= all->pos.pos_michael.x + 340 && tmp->traps.pos_traps.x >=
        all->pos.pos_michael.x)
        all->my_int.jump = 1, all->my_int.energy = 30, sound_random(all);
    if (tmp->who == 8 && all->my_int.jump != 1
        && tmp->traps.pos_traps.x <= all->pos.pos_michael.x + 350
        && tmp->traps.pos_traps.x >= all->pos.pos_michael.x)
        all->my_int.jump = 1, all->my_int.energy = 30, sound_random(all);
}

void auto_hit2(all_t *all, dlist_node_t *tmp, int check, int check_traps)
{
    if (tmp->who == 1 && tmp->dead == 2) {
        if (tmp->flying.pos_flying.x <= all->pos.pos_michael.x + 1600 &&
            all->my_int.hit != 1 && check_traps == 0 && check == 0
            && all->my_int.jump != 1)
            all->my_int.jump = 1, all->my_int.energy = 30, sound_random(all);
        else if (tmp->flying.pos_flying.x <= all->pos.pos_michael.x +
            400 && all->my_int.hit != 1 && all->my_int.jump != 1)
            all->my_int.jump = 1, all->my_int.energy = 30, sound_random(all);
        if (tmp->flying.pos_flying.x <= all->pos.pos_michael.x + 1600 &&
            tmp->flying.pos_flying.x >= all->pos.pos_michael.x + 400 &&
            all->my_int.hit != 1 && all->my_int.up_throw != 1 &&
            all->my_int.jump == 1 && check_traps == 0 && check == 0)
            all->my_int.up_throw = 1, sound_random(all);
        else if (all->my_int.up_throw != 1 && all->my_int.hit != 1 &&
            tmp->flying.pos_flying.x <= all->pos.pos_michael.x + 200)
            all->my_int.hit = 1, sound_random(all);
    }
}

void auto_hit(all_t *all)
{
    if (all->mobs != NULL ) {
        dlist_node_t *tmp = all->mobs->begin;
        int check = check_fat_pos(all), check_traps = check_traps_pos(all);
        while (tmp != NULL) {
            auto_hit4(all, tmp);
            auto_hit2(all, tmp, check, check_traps);
            auto_hit3(all, tmp, check, check_traps);
            tmp = tmp->next;
        }
    }
}