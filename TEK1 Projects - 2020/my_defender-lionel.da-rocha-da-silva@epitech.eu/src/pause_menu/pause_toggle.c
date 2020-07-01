/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** toggle.c
*/

#include "defender.h"

void toggle_pause(s_game **game)
{
    s_game *g = *game;
    if (g->state == GAME) {
        if ((g->g_pause.paused == sfFalse &&
        on_key_released(sfKeyEscape, game))) {
            g->g_pause.paused = sfTrue;
            g->m = 0;
            g->released = sfFalse;
        }
        else if (g->g_pause.paused == sfTrue &&
        on_key_released(sfKeyEscape, game)) {
            g->g_pause.paused = sfFalse;
            g->released = sfFalse;
            g->m = 0.1f;
            g->paused_time = 0;
        }
    }
}