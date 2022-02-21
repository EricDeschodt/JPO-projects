/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** time
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void time_restart(struct_time_t *times)
{
    times->time = sfClock_restart(times->clock);
    times->seconds = 0;
}

void time_increase(struct_time_t *times)
{
    times->time = sfClock_getElapsedTime(times->clock);
    times->seconds = times->time.microseconds / 1000000.0;
}
