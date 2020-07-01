/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** clock_init
*/

#include "my.h"

void clock_init(my_clock_t *clock)
{
    clock->clock = sfClock_create();
    clock->clock_michael = sfClock_create();
    clock->clock_jump = sfClock_create();
    clock->clock_hit = sfClock_create();
    clock->clock_fat = sfClock_create();
    clock->clock_flying = sfClock_create();
    clock->clock_flying_dead = sfClock_create();
    clock->clock_fat_dead = sfClock_create();
    clock->clock_skull = sfClock_create();
    clock->clock_total = sfClock_create();
    clock->clock_cycle = sfClock_create();
}

void clock_set2(all_t *all)
{
    all->clock.time_fat_dead =
        sfClock_getElapsedTime(all->clock.clock_fat_dead);
    all->clock.seconds_fat_dead =
        all->clock.time_fat_dead.microseconds / 1000000.0;
    all->clock.time_skull = sfClock_getElapsedTime(all->clock.clock_skull);
    all->clock.seconds_skull = all->clock.time_skull.microseconds / 1000000.0;
    all->clock.time_total = sfClock_getElapsedTime(all->clock.clock_total);
    all->clock.seconds_total = all->clock.time_total.microseconds / 1000000.0;
    all->clock.time_cycle = sfClock_getElapsedTime(all->clock.clock_cycle);
    all->clock.seconds_cycle = all->clock.time_cycle.microseconds / 1000000.0;
}

void clock_set(all_t *all)
{
    all->clock.time = sfClock_getElapsedTime(all->clock.clock);
    all->clock.seconds = all->clock.time.microseconds / 1000000.0;
    all->clock.time_michael = sfClock_getElapsedTime(all->clock.clock_michael);
    all->clock.seconds_michael =
        all->clock.time_michael.microseconds / 1000000.0;
    all->clock.time_jump = sfClock_getElapsedTime(all->clock.clock_jump);
    all->clock.seconds_jump = all->clock.time_jump.microseconds / 1000000.0;
    all->clock.time_hit = sfClock_getElapsedTime(all->clock.clock_hit);
    all->clock.seconds_hit = all->clock.time_hit.microseconds / 1000000.0;
    all->clock.time_fat = sfClock_getElapsedTime(all->clock.clock_fat);
    all->clock.seconds_fat = all->clock.time_fat.microseconds / 1000000.0;
    all->clock.time_flying = sfClock_getElapsedTime(all->clock.clock_flying);
    all->clock.seconds_flying = all->clock.time_flying.microseconds / 1000000.0;
    all->clock.time_flying_dead =
        sfClock_getElapsedTime(all->clock.clock_flying_dead);
    all->clock.seconds_flying_dead =
        all->clock.time_flying_dead.microseconds / 1000000.0;
    clock_set2(all);
}