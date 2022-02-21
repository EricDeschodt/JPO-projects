/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-mydefender-philippe.cheype
** File description:
** opt.c
*/

#include "defender.h"

void bomb_opt(game_t *gm, obj_t *tower, sfVector2f pos)
{
    tower->stats.level = 1;
    tower->head = gm->tw->head;
    tower->stop = 0;
    pos.x += 32;
    gm->it[0]->info.money -= 150 + 50 * tower->body.index.y;
    pos.y += 64;
    for (gm->tw = gm->tw->head; gm->tw->next; gm->tw = gm->tw->next);
    tower->frame_clock = sfClock_create();
    tower->prev = gm->tw;
    gm->tw->next = tower;
    return;
}

void bonus_opt(game_t *gm, obj_t *tower, sfVector2f pos)
{
    tower->stats.level = 1;
    tower->head = gm->tw->head;
    pos.x += 32;
    gm->it[0]->info.money -= 5000;
    pos.y += 64;
    for (gm->tw = gm->tw->head; gm->tw->next; gm->tw = gm->tw->next);
    tower->frame_clock = sfClock_create();
    tower->frame = 0;
    tower->prev = gm->tw;
    gm->tw->next = tower;
    return;
}

void tower_opt(game_t *gm, obj_t *tower, sfVector2f pos)
{
    tower->stats.level = 1;
    tower->stats.shot_by = 0;
    tower->head = gm->tw->head;
    gm->it[0]->info.money -= 50 + tower->body.index.y * 50;
    pos.x += 32;
    pos.y += 64;
    for (gm->tw = gm->tw->head; gm->tw->next; gm->tw = gm->tw->next);
    tower->prev = gm->tw;
    tower->frame_clock = sfClock_create();
    gm->tw->next = tower;
}