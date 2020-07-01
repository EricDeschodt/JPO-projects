/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** menu_functions
*/

#include "defender.h"

void on_click_levels(void *data)
{
    s_game *game = (s_game *)data;
    game->menu->pages_state = LEVELS;
}

void on_click_score(void *data)
{
    s_game *game = (s_game *)data;
    game->menu->pages_state = SCORE;
}

void on_click_guide(void *data)
{
    s_game *game = (s_game *)data;
    game->menu->pages_state = GUIDE;
}

void on_click_settings(void *data)
{
    s_game *game = (s_game *)data;
    game->menu->pages_state = SETTINGS;
}

void on_click_ret(void *data)
{
    s_game *game = (s_game *)data;
    game->menu->pages_state = -1;
}