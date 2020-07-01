/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** list_mobs2
*/

#include "my.h"

void list_move_zombie(all_t *all)
{
    if (all->mobs != NULL) {
        dlist_node_t *tmp = all->mobs->begin;
        while (tmp != NULL) {
            list_move_zombie_inside(all, tmp);
            tmp = tmp->next;
        }
    }
}

int list_end_map(all_t *all)
{
    if (all->mobs != NULL) {
        dlist_node_t *tmp = all->mobs->end;
        while (tmp != NULL && tmp->who != 7)
            tmp = tmp->back;
        if (tmp != NULL && tmp->who == 7
            && (tmp->traps.pos_traps.x <= all->pos.pos_michael.x))
            return (1);
    }
    return (0);
}

void load_bis(all_t *all, char *map)
{
    sfSprite_setPosition(all->sprite.michael, all->pos.pos_michael);
    sfSprite_setPosition(all->sprite.hit, all->pos.pos_michael);
    sfSprite_setPosition(all->sprite.up_throw, all->pos.pos_michael);
    sfSprite_setPosition(all->sprite.down_throw, all->pos.pos_michael);
    all->mobs = clear_list(all->mobs), list_fat_zombie1(all, map);
    sfClock_restart(all->clock.clock_total), all->my_int.reset = 0;
}

int load_map(all_t *all, char *argv)
{
    if (all->my_int.reset == 1) {
        char *map = NULL;
        if (all->my_int.level == 3)
            map = load_file_in_mem("maps/map3");
        if (all->my_int.level == 2)
            map = load_file_in_mem("maps/map2");
        if (all->my_int.level == 1)
            map = load_file_in_mem("maps/map1");
        if (all->my_int.level == 4)
            map = load_file_in_mem(argv);
        if (all->my_int.level == 0)
            map = load_file_in_mem("maps/menu");
        if (map == NULL) return (84);
        init_pos(&all->pos);
        load_bis(all, map);
    } return (0);
}