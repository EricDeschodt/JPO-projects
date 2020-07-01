/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** destroy2
*/

#include "defender.h"
#include "utils.h"

tuto_t *destroy_mob_head(tuto_t *s_tuto, tuto_t *temp3, all_t *s_all)
{
    tuto_t *temp = s_tuto->next;
    if (s_tuto->scale.x > 0.1 && s_tuto->scale.y > 0.1) {
        mob_destroy_animation(s_tuto);
        return (temp);
    } else {
        sfSprite_destroy(s_tuto->sprite);
        sfClock_destroy(s_tuto->clock);
        free(s_tuto);
        if (temp3 == s_all->s_wave_c.round)
            s_all->s_wave_c.round = temp;
        if (temp3 == s_all->s_wave_c.square)
            s_all->s_wave_c.square = temp;
        if (temp3 == s_all->s_wave_c.triangle)
            s_all->s_wave_c.triangle = temp;
        return (temp);
    }
}

tuto_t *destroy_part1(all_t *s_all, tuto_t *temp2, tuto_t *temp3, tuto_t *temp)
{
    turret_t *tmp = s_all->s_turret;
    while (tmp != NULL) {
        if (tmp->locked == temp) {
            tmp->locked = NULL;
            tmp->pos_bullet = tmp->pos_c;
            sfSprite_setPosition(tmp->bullet, tmp->pos_c);
        } tmp = tmp->next;
    } temp = free_node(temp, temp2, temp3, s_all);
    return (temp);
}

void destroy_part2(all_t *s_all, int id, tuto_t *temp)
{
    turret_t *tmp = s_all->s_turret;
    while (tmp != NULL) {
        tmp->locked = NULL;
        tmp->pos_bullet = tmp->pos_c;
        sfSprite_setPosition(tmp->bullet, tmp->pos_c);
        tmp = tmp->next;
    }
    free_node2(s_all, temp, id);
}

tuto_t *destroy_part3(all_t *s_all, tuto_t *temp3, tuto_t *temp)
{
    turret_t *tmp = s_all->s_turret;
    while (tmp != NULL) {
        tmp->locked = NULL;
        tmp->pos_bullet = tmp->pos_c;
        sfSprite_setPosition(tmp->bullet, tmp->pos_c);
        tmp = tmp->next;
    } temp = destroy_mob_head(temp, temp3, s_all);
    return (temp);
}