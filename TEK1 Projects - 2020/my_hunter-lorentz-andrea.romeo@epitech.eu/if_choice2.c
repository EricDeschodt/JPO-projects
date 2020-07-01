/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** if_choice2
*/

#include "my.h"

void if_choice_is_0_2(all_t *all, sfEvent event)
{
    if (all->my_int.choice2 == 0) {
        sfSprite_setPosition(all->sprite2.duck1_2, all->pos.pos_duck2);
        sfSprite_setTextureRect(all->sprite2.duck1_2, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck2.x != -120)
            sfRenderWindow_drawSprite(all->window, all->sprite2.duck1_2, NULL);
    }
}

void if_choice_is_1_2(all_t *all, sfEvent event)
{
    if (all->my_int.choice2 == 1) {
        sfSprite_setPosition(all->sprite2.duck2_2, all->pos.pos_duck2);
        sfSprite_setTextureRect(all->sprite2.duck2_2, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck2.x != -120)
            sfRenderWindow_drawSprite(all->window, all->sprite2.duck2_2, NULL);
    }
}

void if_choice_is_2_2(all_t *all, sfEvent event)
{
    if (all->my_int.choice2 == 2) {
        sfSprite_setPosition(all->sprite2.duck3_2, all->pos.pos_duck2);
        sfSprite_setTextureRect(all->sprite2.duck3_2, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck2.x != -120)
            sfRenderWindow_drawSprite(all->window, all->sprite2.duck3_2, NULL);
    }
}