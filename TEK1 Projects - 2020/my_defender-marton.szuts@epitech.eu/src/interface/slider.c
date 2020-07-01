/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** slider
*/

#include "defender.h"

void slider_on2(all_t *s_all, list_targetting_t *s_targetting)
{
    t_select_t *temp = s_all->s_t_select;
    s_all->s_hard_arrow.pos.x -= 50;
    turret_t *temp1 = s_all->s_turret;
    targetting_t *tmp;
    sfSprite_setPosition(s_all->s_hard_arrow.sprite, s_all->s_hard_arrow.pos);
    while (temp != NULL) {
        sfText_setPosition(temp->text, (sfVector2f){temp->pos.x + 90,
        temp->pos.y + 90});
        temp = temp->next;
    }
    for (; temp1 != NULL; temp1 = temp1->next) {
        if (temp1->target == s_targetting) continue;
        tmp = temp1->target->begin;
        while (tmp != NULL) {
            tmp->pos.x -= 50, tmp->text_pos.x -= 50;
            sfSprite_setPosition(tmp->sprite, tmp->pos);
            sfText_setPosition(tmp->str, tmp->text_pos);
            tmp = tmp->next;
        }
    }
}

void slider_on1(all_t *s_all, list_targetting_t *s_targetting)
{
    s_all->s_side_menu.pos.x -= 50;
    t_select_t *temp = s_all->s_t_select;
    targetting_t *tmp = s_targetting->begin;
    sfVector2f pos = s_all->s_side_menu.pos;
    pos.x += 138, pos.y = 495;
    sfSprite_setPosition(s_all->s_side_menu.sprite, s_all->s_side_menu.pos);
    for (; temp != NULL; pos.x += 122, temp = temp->next) {
        temp->pos = pos, sfSprite_setPosition(temp->sprite, pos);
    } if (s_targetting != s_all->s_targetting) {
        targetting_t *target = s_all->s_targetting->begin;
        for (; target != NULL; target = target->next) {
        target->pos.x -= 50, target->text_pos.x -= 50;
        sfSprite_setPosition(target->sprite, target->pos);
        sfText_setPosition(target->str, target->text_pos); }
    } for (; tmp != NULL; tmp = tmp->next) {
        tmp->pos.x -= 50, tmp->text_pos.x -= 50;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        sfText_setPosition(tmp->str, tmp->text_pos);
    } sfClock_restart(s_all->s_side_menu.clock);
    slider_on2(s_all, s_targetting), slider_on3(s_all), slider_on4(s_all);
}

void slider_off2(all_t *s_all, list_targetting_t *s_targetting)
{
    t_select_t *temp = s_all->s_t_select;
    s_all->s_hard_arrow.pos.x += 50;
    turret_t *temp1 = s_all->s_turret;
    targetting_t *tmp;
    sfSprite_setPosition(s_all->s_hard_arrow.sprite, s_all->s_hard_arrow.pos);
    while (temp != NULL) {
        sfText_setPosition(temp->text, (sfVector2f){temp->pos.x + 90,
        temp->pos.y + 90});
        temp = temp->next;
    }
    for (; temp1 != NULL; temp1 = temp1->next) {
        if (temp1->target == s_targetting) continue;
        tmp = temp1->target->begin;
        while (tmp != NULL) {
            tmp->pos.x += 50, tmp->text_pos.x += 50;
            sfSprite_setPosition(tmp->sprite, tmp->pos);
            sfText_setPosition(tmp->str, tmp->text_pos);
            tmp = tmp->next;
        }
    }
}

void slider_off1(all_t *s_all, list_targetting_t *s_targetting)
{
    s_all->s_side_menu.pos.x += 50;
    t_select_t *temp = s_all->s_t_select;
    targetting_t *tmp = s_targetting->begin;
    sfVector2f pos = s_all->s_side_menu.pos;
    pos.x += 138, pos.y = 495;
    sfSprite_setPosition(s_all->s_side_menu.sprite, s_all->s_side_menu.pos);
    for (; temp != NULL; pos.x += 122, temp = temp->next) {
        temp->pos = pos, sfSprite_setPosition(temp->sprite, pos);
    } if (s_targetting != s_all->s_targetting) {
        targetting_t *target = s_all->s_targetting->begin;
        for (; target != NULL; target = target->next) {
        target->pos.x += 50, target->text_pos.x += 50;
        sfSprite_setPosition(target->sprite, target->pos);
        sfText_setPosition(target->str, target->text_pos); }
    } for (; tmp != NULL; tmp = tmp->next) {
        tmp->pos.x += 50, tmp->text_pos.x += 50;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        sfText_setPosition(tmp->str, tmp->text_pos);
    } sfClock_restart(s_all->s_side_menu.clock);
    slider_off2(s_all, s_targetting), slider_off3(s_all), slider_off4(s_all);
}