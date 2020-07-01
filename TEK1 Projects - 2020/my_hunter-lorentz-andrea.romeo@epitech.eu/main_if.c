/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** main_if_clock
*/

#include "my.h"

void main_walking(all_t *all, sfEvent event)
{
    while (sfRenderWindow_pollEvent(all->window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(all->window);
    dog_walking_round(all);
    draw_sprite_new_round(all, event);
}

void main_if_clock(all_t *all, sfEvent event)
{
    if (all->clock.seconds0_1s > 0.08) {
        duck_animation(all);
        sfClock_restart(all->clock.clock0_1s);
    }
    dog_walking(all);
    draw_sprite(event, all);
}