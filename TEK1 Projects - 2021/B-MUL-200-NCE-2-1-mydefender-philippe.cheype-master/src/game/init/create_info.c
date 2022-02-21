/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_info.c
*/

#include "defender.h"

void create_info(items_t **it)
{
    it[0]->info.score = 0;
    it[0]->info.killed = 0;
    it[0]->info.clock = sfClock_create();
    it[0]->info.check.x = 0;
    it[0]->info.check.y = 0;
}
