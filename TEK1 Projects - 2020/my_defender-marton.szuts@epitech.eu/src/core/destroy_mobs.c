/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** destroy_mobs
*/

#include "defender.h"

tuto_t *get_prev(all_t *s_all, int id, tuto_t *node)
{
    tuto_t *temp = s_all->s_tuto;
    if (id == 1) temp = s_all->s_wave_c.round;
    if (id == 2) temp = s_all->s_wave_c.square;
    if (id == 3) temp = s_all->s_wave_c.triangle;
    while (temp != NULL) {
        if (temp->next == node)
            return (temp);
        temp = temp->next;
    }
    return (temp);
}

tuto_t *destroy_mob_node(all_t *s_all, tuto_t *prev, tuto_t *temp)
{
    turret_t *tmp = s_all->s_turret;
    while (tmp != NULL) {
        if (tmp->locked == temp) { tmp->locked = NULL;
        tmp->pos_bullet = tmp->pos_c;
        sfSprite_setPosition(tmp->bullet, tmp->pos_c);
        } tmp = tmp->next;
    }
    if (temp->scale.x > 0.1 && temp->scale.y > 0.1) {
        mob_destroy_animation(temp);
        return (temp->next);
    }
    prev->next = temp->next;
    free(temp);
    return (prev->next);
}

void reset_locked(all_t *s_all)
{
    turret_t *fi = s_all->s_turret;
    while (fi != NULL) {
        fi->locked = NULL;
        fi->pos_bullet = fi->pos_c;
        sfSprite_setPosition(fi->bullet, fi->pos_c);
        fi = fi->next;
    }
}

void destroy_mobs(all_t *s_all, int id)
{
    tuto_t *temp = s_all->s_tuto, *tmp = s_all->s_tuto;
    if (id == 1) temp = s_all->s_wave_c.round;
    if (id == 2) temp = s_all->s_wave_c.square;
    if (id == 3) temp = s_all->s_wave_c.triangle;
    while (temp != NULL) {
        if (id == 1) tmp = s_all->s_wave_c.round;
        if (id == 2) tmp = s_all->s_wave_c.square;
        if (id == 3) tmp = s_all->s_wave_c.triangle;
        tuto_t *prev = get_prev(s_all, id, temp);
        if (my_if(temp)) losing_life(s_all);
        if (prev != NULL && temp->state == -1) {
            temp = destroy_mob_node(s_all, prev, temp);
            continue;
        }
        else if (temp->state == -1){
            reset_locked(s_all);
            temp = destroy_mob_head(temp, tmp, s_all);
            continue;
        } temp = temp->next;
    }
}