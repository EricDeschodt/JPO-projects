/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** page_settings_onclicks.c
*/

#include "defender.h"

void on_frame_up(void *d)
{
    s_game *g = (s_game *)d;
    g->framerate += 1;
    put_text(&g->menu->settings->framerate,
    my_itoa(g->framerate), (v2){1150, 550 - 4}, 32);
}

void on_frame_down(void *d)
{
    s_game *g = (s_game *)d;
    g->framerate -= 1;
    if (g->framerate < 1)
    g->framerate = 1;
    put_text(&g->menu->settings->framerate,
    my_itoa(g->framerate), (v2){1150, 550 - 4}, 32);
}