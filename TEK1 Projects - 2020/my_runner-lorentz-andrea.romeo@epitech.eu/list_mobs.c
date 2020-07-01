/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** list_mobs
*/

#include "my.h"

void list_fat_zombie1_bis(all_t *all, int pos, int j)
{
    if (j == 1)
        all->mobs = push_back_fat1(all, all->mobs, pos);
    if (j == 2)
        all->mobs = push_back_flying(all, all->mobs, pos);
    if (j == 3)
        all->mobs = push_back_traps_axe1(all, all->mobs, pos);
    if (j == 4)
        all->mobs = push_back_traps_balls(all, all->mobs, pos);
    if (j == 5)
        all->mobs = push_back_traps_saw(all, all->mobs, pos);
    if (j == 6)
        all->mobs = push_back_traps_axe2(all, all->mobs, pos);
    if (j == 6 || j == 5 || j == 4 || j == 3)
        all->mobs = push_back_traps_base(all, all->mobs, pos);
    if (j == 7)
        all->mobs = push_back_sign(all, all->mobs, pos);
    if (j == 8)
        all->mobs = push_back_iron_spikes(all, all->mobs, pos);
    if (j == 9 || j == 0)
        all->mobs = push_back_skull(all, all->mobs, pos, j);
}

void list_fat_zombie1(all_t *all, char *map)
{
    int nb = count_entities(map);
    int pos = 2000;
    int j = who_entities(map, 1);
    all->mobs = push_back_skull(all, all->mobs, 0, -1);
    for (int i = 1; i != nb + 1; i++, j = who_entities(map, i)) {
        pos = pos_entities(map, i, pos);
        list_fat_zombie1_bis(all, pos, j);
    }
}

void list_skulls(all_t *all, dlist_node_t *tmp)
{
    if ((tmp->who == 9 || tmp->who == -1) && all->clock.seconds_skull >= 0.1) {
        if (tmp->traps.rect_traps.left >= 420) {
            tmp->traps.rect_traps.left = 0;
            tmp->traps.rect_traps.width = 62;
        }
        else if (tmp->traps.rect_traps.left == 378) {
            tmp->traps.rect_traps.left += 63;
            tmp->traps.rect_traps.width += 20;
        }
        else {
            tmp->traps.rect_traps.left += 63;
            tmp->traps.rect_traps.width = 62;
        }
        sfSprite_setTextureRect(tmp->traps.sprite, tmp->traps.rect_traps);
        sfClock_restart(all->clock.clock_skull);
    }
}

void list_axes_saw(all_t *all, dlist_node_t *tmp)
{
    if (tmp->who != -1) tmp->traps.pos_traps.x -= all->my_int.speed / 11;
    sfSprite_setPosition(tmp->traps.sprite, tmp->traps.pos_traps);
    if (tmp->who == 3 || tmp->who == 5) {
        if (tmp->traps.rotate >= 360)
            tmp->traps.rotate = 0;
        else
            tmp->traps.rotate += 15;
        sfSprite_setRotation(tmp->traps.sprite, tmp->traps.rotate);
    }
    if (tmp->who == 4 || tmp->who == 6) {
        if (tmp->traps.rotate <= 0)
            tmp->traps.rotate = 360;
        else
            tmp->traps.rotate -= 15;
        sfSprite_setRotation(tmp->traps.sprite, tmp->traps.rotate);
    }
    list_skulls(all, tmp);
}

void list_move_zombie_inside(all_t *all, dlist_node_t *tmp)
{
    if (all->my_int.menu != 5) {
        if (tmp->who == 0)
            fat_walk_anim(all, tmp);
        else if (tmp->who == 1)
            flying_walk_anim(all, tmp);
        else
            list_axes_saw(all, tmp);
    }
}