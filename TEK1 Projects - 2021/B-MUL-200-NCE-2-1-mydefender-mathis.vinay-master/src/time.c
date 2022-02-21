/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** time functions
*/

#include "../include/time.h"

_time_t *time_create(void)
{
    _time_t *time = malloc(sizeof(_time_t));
    time->clock = sfClock_create();
    time->is_paused = true;
    time->counter = 0;
    time->counter_2 = 0;
    time->counter_3 = 0;
    time->counter_4 = 0;
    time->counter_5 = 0;
    time->counter_dps = 0;
    return time;
}

void time_update(_time_t *time, double degree)
{
    sfTime elapsed_time = sfClock_getElapsedTime(time->clock);
    if (!time->is_paused) {
        time->counter += (long long) (elapsed_time.microseconds * degree);
        time->counter_2 += (long long) (elapsed_time.microseconds * degree);
        time->counter_3 += (long long) (elapsed_time.microseconds * degree);
        time->counter_4 += (long long) (elapsed_time.microseconds * degree);
        time->counter_5 += (long long) (elapsed_time.microseconds * degree);
        time->counter_dps += (float) (elapsed_time.microseconds * degree);
    } else
        time->is_paused = false;
    sfClock_restart(time->clock);
}

void time_destroy(_time_t *time)
{
    sfClock_destroy(time->clock);
    free(time);
}
