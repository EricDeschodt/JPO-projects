/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** duck_animation3
*/

#include "my.h"

void duck_animation_dead3(all_t *all)
{
    if (all->my_int.save_choice2 == 2 || all->my_int.save_choice2 == 5
        || all->my_int.save_choice2 == 8)
        sfRenderWindow_drawSprite(all->window, all->sprite2.dead_duck3_2, NULL);
    if (all->my_int.save_choice2 == 1 || all->my_int.save_choice2 == 4
        || all->my_int.save_choice2 == 7)
        sfRenderWindow_drawSprite(all->window, all->sprite2.dead_duck2_2, NULL);
    if (all->my_int.save_choice2 == 0 || all->my_int.save_choice2 == 3
        || all->my_int.save_choice2 == 6)
        sfRenderWindow_drawSprite(all->window, all->sprite2.dead_duck1_2, NULL);
    all->clock.time_dead2 = sfClock_getElapsedTime(all->clock.clock_dead2);
    all->clock.seconds_dead2 = all->clock.time_dead2.microseconds / 1000000.0;
    if (all->clock.seconds_dead2 >= 0.3) {
        all->my_int.shoot_check2 = 0;
        all->my_int.rand_check2 = 0;
    }
}