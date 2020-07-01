/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** clocks2
*/

#include "defender.h"

void init_clocks2(all_t *s_all)
{
    s_all->s_map_edit.time = sfClock_getElapsedTime(s_all->s_map_edit.clock);
    s_all->s_map_edit.seconds =
    s_all->s_map_edit.time.microseconds / 1000000.0;
    s_all->s_game.anim_time = sfClock_getElapsedTime(s_all->s_game.anim_clock);
    s_all->s_game.anim_seconds =
    s_all->s_game.anim_time.microseconds / 1000000.0;
    s_all->s_texture.time = sfClock_getElapsedTime(s_all->s_texture.clock);
    s_all->s_texture.seconds =
    s_all->s_texture.time.microseconds / 1000000.0;
}