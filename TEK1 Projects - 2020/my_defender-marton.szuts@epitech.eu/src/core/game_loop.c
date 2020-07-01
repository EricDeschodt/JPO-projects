/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** game_loop
*/

#include "defender.h"

int game_loop(all_t *s_all)
{
    if (!s_all->s_game.window) return (EXIT_FAILURE);
    while (sfRenderWindow_isOpen(s_all->s_game.window)) {
        while (sfRenderWindow_pollEvent(s_all->s_game.window,
        &s_all->s_game.event))
            event_controll(s_all);
        general_game_clock(s_all);
        display(s_all);
    } return (0);
}