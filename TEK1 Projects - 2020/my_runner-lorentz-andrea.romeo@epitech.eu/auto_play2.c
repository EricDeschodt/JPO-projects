/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** auto_play2
*/

#include "my.h"

void auto_hit4(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who == 0 && tmp->dead == 0) {
        if (tmp->fat.pos_fat.x <= all->pos.pos_michael.x + 350 &&
            tmp->fat.pos_fat.x >= all->pos.pos_michael.x &&
            all->my_int.hit != 1 && all->my_int.up_throw != 1)
            all->my_int.hit = 1, sound_random(all);
    }
}