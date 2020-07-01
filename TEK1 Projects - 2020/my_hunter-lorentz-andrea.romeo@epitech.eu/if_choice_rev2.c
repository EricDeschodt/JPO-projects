/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** if_choice_rev2
*/

#include "my.h"

void if_choice_is_3_rev_2(all_t *all, sfEvent event)
{
    if (all->my_int.choice2 == 3) {
        sfSprite_setPosition(all->sprite2.duck1_rev2, all->pos.pos_duck_rev2);
        sfSprite_setTextureRect(all->sprite2.duck1_rev2, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck_rev2.x != 850)
            sfRenderWindow_drawSprite(all->window, all->sprite2.duck1_rev2,
                NULL);
    }
}

void if_choice_is_4_rev_2(all_t *all, sfEvent event)
{
    if (all->my_int.choice2 == 4) {
        sfSprite_setPosition(all->sprite2.duck2_rev2, all->pos.pos_duck_rev2);
        sfSprite_setTextureRect(all->sprite2.duck2_rev2, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck_rev2.x != 850)
            sfRenderWindow_drawSprite(all->window, all->sprite2.duck2_rev2,
                NULL);
    }
}

void if_choice_is_5_rev_2(all_t *all, sfEvent event)
{
    if (all->my_int.choice2 == 5) {
        sfSprite_setPosition(all->sprite2.duck3_rev2, all->pos.pos_duck_rev2);
        sfSprite_setTextureRect(all->sprite2.duck3_rev2, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck_rev2.x != 850)
            sfRenderWindow_drawSprite(all->window, all->sprite2.duck3_rev2,
                NULL);
    }
}