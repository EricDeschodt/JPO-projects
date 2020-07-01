/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** targetting2
*/

#include "defender.h"

void set_show_targetting(list_targetting_t *s_targetting)
{
    targetting_t *tmp = s_targetting->begin;
    for (; tmp != NULL && tmp->big != 1; tmp = tmp->next);
    for (int i = 0; i != 2; i++) {
        if (i == 1) tmp->show = 1;
        if (tmp->back == NULL) {
            tmp = s_targetting->end;
            continue;
        } tmp = tmp->back;
    } tmp->show = 0;
    for (int i = 0; i != 4; i++) {
        if (i == 3) tmp->show = 1;
        if (tmp->next == NULL) {
            tmp = s_targetting->begin;
            continue;
        } tmp = tmp->next;
    } tmp->show = 0;
}

void keep_centered_targetting3(list_targetting_t *s_targetting,
    targetting_t *tmp, int big_pos)
{
    if (big_pos == 4) {
        s_targetting->begin->pos.x = (tmp->pos.x +
            (s_targetting->size * 2));
        s_targetting->begin->next->pos.x =
            (tmp->pos.x - (s_targetting->size * 2));
        sfSprite_setPosition(s_targetting->begin->sprite,
            s_targetting->begin->pos), sfSprite_setPosition(s_targetting->
            begin->next->sprite, s_targetting->begin->next->pos);
    } if (big_pos == 5) {
        tmp->back->back->pos.x =
            (tmp->pos.x - (s_targetting->size * 2));
        s_targetting->begin->pos.x =
            (tmp->pos.x + (s_targetting->size));
        s_targetting->begin->next->pos.x = (tmp->pos.x +
            (s_targetting->size * 2));
        sfSprite_setPosition(s_targetting->begin->sprite,
            s_targetting->begin->pos), sfSprite_setPosition(s_targetting->
            begin->next->sprite, s_targetting->begin->next->pos);
        sfSprite_setPosition(tmp->back->back->sprite, tmp->back->back->pos);
    }
}

void keep_centered_targetting2(list_targetting_t *s_targetting,
    targetting_t *tmp, int big_pos)
{
    if (big_pos == 2) {
        s_targetting->end->pos.x = (tmp->pos.x -
            (s_targetting->size * 2));
        tmp->next->next->pos.x =
            (tmp->pos.x + (s_targetting->size * 2));
        sfSprite_setPosition(tmp->next->next->sprite, tmp->next->next->pos);
        sfSprite_setPosition(s_targetting->end->sprite,
            s_targetting->end->pos);
    } if (big_pos == 3) {
        s_targetting->begin->pos.x = (tmp->pos.x -
            (s_targetting->size * 2));
        tmp->next->next->pos.x =
            (tmp->pos.x + (s_targetting->size * 2));
        sfSprite_setPosition(tmp->next->next->sprite,
            tmp->next->next->pos);
        sfSprite_setPosition(s_targetting->begin->sprite,
            s_targetting->begin->pos);
    }
}

void keep_centered_targetting(list_targetting_t *s_targetting)
{
    targetting_t *tmp = s_targetting->begin;
    int big_pos = 1;
    while (tmp != NULL && tmp->big != 1) {
        big_pos++;
        tmp = tmp->next;
    } tmp = s_targetting->begin;
    while (tmp != NULL && tmp->big != 1) tmp = tmp->next;
    if (big_pos == 1) {
        tmp->next->next->next->next->pos.x =
            (tmp->pos.x - s_targetting->size);
        tmp->next->next->next->pos.x =
            (tmp->pos.x - (s_targetting->size * 2));
        tmp->next->next->pos.x =
            (tmp->pos.x + (s_targetting->size * 2));
        sfSprite_setPosition(tmp->next->next->next->next->sprite, tmp->next->
        next->next->next->pos), sfSprite_setPosition(tmp->next->next->next->
        sprite, tmp->next->next->next->pos), sfSprite_setPosition(tmp->next->
        next->sprite, tmp->next->next->pos);
    } keep_centered_targetting2(s_targetting, tmp, big_pos);
    keep_centered_targetting3(s_targetting, tmp, big_pos);
}