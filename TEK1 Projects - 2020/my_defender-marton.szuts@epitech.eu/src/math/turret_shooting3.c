/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_shooting3
*/

#include "defender.h"
#include "utils.h"

void targetting_selector(all_t *s_all, turret_t *tmp)
{
    targetting_t *target = tmp->target->begin;
    int i = 0;
    for (; target != NULL && target->big != 1; i++, target = target->next);
    if (i == 0)
        find_pos_first(s_all, tmp);
    if (i == 1)
        find_pos_last(s_all, tmp);
    if (i == 2)
        find_pos_weak(s_all, tmp);
    if (i == 3)
        find_pos_strong(s_all, tmp);
    if (i == 4)
        find_pos_closest(s_all, tmp);
}

void find_pos_first2(all_t *s_all, turret_t *turret, tuto_t **locked,
    tuto_t *tmp)
{
    for (int len = linked_len(s_all, 1); len != 0; len--) {
        tmp = s_all->s_wave_c.round;
        for (int i = 1; tmp != NULL && i != len; i++) tmp = tmp->next;
        if (tmp->state == -1) continue;
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range) { *locked = tmp;
            break; }
    } tmp = s_all->s_wave_c.square;
    for (int len = linked_len(s_all, 2); len != 0; len--) {
        tmp = s_all->s_wave_c.square;
        for (int i = 1; tmp != NULL && i != len; i++) tmp = tmp->next;
        if (tmp->state == -1) continue;
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && *locked == NULL) { *locked = tmp;
            break;
        } else if (magnitude <= turret->range && *locked != NULL) {
            if ((*locked)->nb > tmp->nb) *locked = tmp;
            break; }
    }
}

void find_pos_first(all_t *s_all, turret_t *turret)
{
    tuto_t *locked = NULL, *tmp = s_all->s_wave_c.round;
    find_pos_first2(s_all, turret, &locked, tmp);
    tmp = s_all->s_wave_c.triangle;
    for (int len = linked_len(s_all, 3); len != 0; len--) {
        tmp = s_all->s_wave_c.triangle;
        for (int i = 1; tmp != NULL && i != len; i++) tmp = tmp->next;
        if (tmp->state == -1) continue;
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && locked == NULL) { locked = tmp;
            break;
        } else if (magnitude <= turret->range && locked != NULL) {
            if (locked->nb > tmp->nb) locked = tmp;
            break; }
    } lock_target_in_range(turret, locked);
}

void find_pos_weak(all_t *s_all, turret_t *turret)
{
    tuto_t *locked = NULL, *tmp = s_all->s_wave_c.round;
    int life = __INT_MAX__;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->state == -1) continue;
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && tmp->life < life) { locked = tmp;
            life = tmp->life; }
    } tmp = s_all->s_wave_c.square;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->state == -1) continue;
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && tmp->life < life) { locked = tmp;
            life = tmp->life; }
    } tmp = s_all->s_wave_c.triangle;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->state == -1) continue;
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && tmp->life < life) { locked = tmp;
            life = tmp->life; }
    } lock_target_in_range(turret, locked);
}

void find_pos_strong(all_t *s_all, turret_t *turret)
{
    tuto_t *locked = NULL, *tmp = s_all->s_wave_c.round;
    int life = -2147483648;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->state == -1) continue;
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && tmp->life > life) { locked = tmp;
            life = tmp->life; }
    } tmp = s_all->s_wave_c.square;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->state == -1) continue;
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && tmp->life > life) { locked = tmp;
            life = tmp->life; }
    } tmp = s_all->s_wave_c.triangle;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->state == -1) continue;
        float magnitude = calcul_magnitude(tmp, turret);
        if (magnitude <= turret->range && tmp->life > life) { locked = tmp;
            life = tmp->life; }
    } lock_target_in_range(turret, locked);
}