/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-mydefender-philippe.cheype
** File description:
** create_score.c
*/

#include "defender.h"

void create_stats(items_t **it)
{
    sfVector2f pos_killed = {1650, 95};
    sfVector2f pos_money = {1203, 85};
    sfVector2f pos_score = {800, 95};

    it[0]->info.score = 0;
    it[0]->info.score_t = create_text(pos_score, "0", 50, sfBlack);
    it[0]->info.money = 999999;
    it[0]->info.money_t = create_text(pos_money, "1000", 100, sfBlack);
    it[0]->info.killed = 0;
    it[0]->info.killed_t = create_text(pos_killed, "0", 50, sfBlack);
}
