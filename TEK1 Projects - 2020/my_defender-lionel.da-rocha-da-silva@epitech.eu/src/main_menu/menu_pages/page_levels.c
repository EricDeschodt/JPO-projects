/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** page_levels.c
*/

#include "defender.h"

void map1(void *data)
{
    s_game *g = (s_game *)data;
    g->levels = MAP1;
}

void map2(void *data)
{
    s_game *g = (s_game *)data;
    g->levels = MAP2;
}

void map3(void *data)
{
    s_game *g = (s_game *)data;
    g->levels = MAP3;
}

void map4(void *data)
{
    s_game *g = (s_game *)data;
    g->levels = MAP4;
}

void map5(void *data)
{
    s_game *g = (s_game *)data;
    g->levels = MAP5;
}