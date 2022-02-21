/*
** EPITECH PROJECT, 2020
** bootstrap graphique lourd
** File description:
** functions for clocks handeling
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/time.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

_time_t *create_time(void)
{
    _time_t *time = malloc(sizeof(_time_t));
    time->clock = sfClock_create();
    time->moove_microseconds = 0;
    time->anime_microseconds = 0;
    return time;
}

void destroy_time(_time_t *time)
{
    sfClock_destroy(time->clock);
    free(time);
}

void add_elapsed_time(_time_t *time)
{
    sfTime elapsed_time = sfClock_getElapsedTime(time->clock);
    time->moove_microseconds += elapsed_time.microseconds;
    time->anime_microseconds += elapsed_time.microseconds;
    sfClock_restart(time->clock);
}