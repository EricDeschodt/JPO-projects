/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** if_choice_bot2
*/

#include "my.h"

void if_choice_is_6_bot_2(all_t *all, sfEvent event)
{
    if (all->my_int.choice2 == 6) {
        sfSprite_setPosition(all->sprite2.duck1_bot2, all->pos.pos_duck_bot2);
        sfSprite_setTextureRect(all->sprite2.duck1_bot2, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck_bot2.y != 450)
            sfRenderWindow_drawSprite(all->window, all->sprite2.duck1_bot2,
                NULL);
    }
}

void if_choice_is_7_bot_2(all_t *all, sfEvent event)
{
    if (all->my_int.choice2 == 7) {
        sfSprite_setPosition(all->sprite2.duck2_bot2, all->pos.pos_duck_bot2);
        sfSprite_setTextureRect(all->sprite2.duck2_bot2, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck_bot2.y != 450)
            sfRenderWindow_drawSprite(all->window, all->sprite2.duck2_bot2,
                NULL);
    }
}

void if_choice_is_8_bot_2(all_t *all, sfEvent event)
{
    if (all->my_int.choice2 == 8) {
        sfSprite_setPosition(all->sprite2.duck3_bot2, all->pos.pos_duck_bot2);
        sfSprite_setTextureRect(all->sprite2.duck3_bot2, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck_bot2.y != 450)
            sfRenderWindow_drawSprite(all->window, all->sprite2.duck3_bot2,
                NULL);
    }
}