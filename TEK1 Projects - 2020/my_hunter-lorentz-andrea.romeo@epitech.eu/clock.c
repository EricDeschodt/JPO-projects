/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** clock_init
*/

#include "my.h"

void clock_init(my_clock_t *clock)
{
    clock->clock0_1s = sfClock_create();
    clock->clock_dead = sfClock_create();
    clock->clock_dead2 = sfClock_create();
    clock->clock_dog = sfClock_create();
    clock->clock_dog_jump = sfClock_create();
    clock->clock_dog_jump2 = sfClock_create();
}

void clock_set(all_t *all)
{
    all->clock.time0_1s = sfClock_getElapsedTime(all->clock.clock0_1s);
    all->clock.seconds0_1s = all->clock.time0_1s.microseconds / 1000000.0;
    all->clock.time_dead = sfClock_getElapsedTime(all->clock.clock_dead);
    all->clock.seconds_dead = all->clock.time_dead.microseconds / 1000000.0;
    all->clock.time_dead2 = sfClock_getElapsedTime(all->clock.clock_dead2);
    all->clock.seconds_dead2 = all->clock.time_dead2.microseconds / 1000000.0;
    all->clock.time_dog = sfClock_getElapsedTime(all->clock.clock_dog);
    all->clock.seconds_dog = all->clock.time_dog.microseconds / 1000000.0;
    all->clock.time_dog_jump =
        sfClock_getElapsedTime(all->clock.clock_dog_jump);
    all->clock.seconds_dog_jump = all->clock.time_dog_jump.microseconds /
        1000000.0;
    all->clock.time_dog_jump2 =
        sfClock_getElapsedTime(all->clock.clock_dog_jump2);
    all->clock.seconds_dog_jump2 = all->clock.time_dog_jump2.microseconds /
        1000000.0;
}