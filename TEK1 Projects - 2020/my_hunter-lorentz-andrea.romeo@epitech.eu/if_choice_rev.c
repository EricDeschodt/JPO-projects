/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** if_choice_rev
*/

#include "my.h"

void if_choice_is_3_rev(all_t *all, sfEvent event)
{
    if (all->my_int.choice == 3) {
        sfSprite_setPosition(all->sprite.duck1_rev, all->pos.pos_duck_rev);
        sfSprite_setTextureRect(all->sprite.duck1_rev, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck_rev.x != 850)
            sfRenderWindow_drawSprite(all->window, all->sprite.duck1_rev, NULL);
        if (all->pos.pos_duck_rev.x >= 850 && all->my_int.shoot == 1) {
            all->my_int.check = 0;
            sfSprite_setPosition(all->sprite.duck1_rev, all->pos.pos_duck_rev);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite.dead_duck1, all->pos.pos_save_rev);
            sfSound_play(all->sound.fall);
            sfClock_restart(all->clock.clock_dead);
        }
    }
}

void if_choice_is_4_rev(all_t *all, sfEvent event)
{
    if (all->my_int.choice == 4) {
        sfSprite_setPosition(all->sprite.duck2_rev, all->pos.pos_duck_rev);
        sfSprite_setTextureRect(all->sprite.duck2_rev, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck_rev.x != 850)
            sfRenderWindow_drawSprite(all->window, all->sprite.duck2_rev, NULL);
        if (all->pos.pos_duck_rev.x >= 850 && all->my_int.shoot == 1) {
            all->my_int.check = 0;
            sfSprite_setPosition(all->sprite.duck2_rev, all->pos.pos_duck_rev);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite.dead_duck2, all->pos.pos_save_rev);
            sfSound_play(all->sound.fall);
            sfClock_restart(all->clock.clock_dead);
        }
    }
}

void if_choice_is_5_rev(all_t *all, sfEvent event)
{
    if (all->my_int.choice == 5) {
        sfSprite_setPosition(all->sprite.duck3_rev, all->pos.pos_duck_rev);
        sfSprite_setTextureRect(all->sprite.duck3_rev, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck_rev.x != 850)
            sfRenderWindow_drawSprite(all->window, all->sprite.duck3_rev, NULL);
        if (all->pos.pos_duck_rev.x >= 850 && all->my_int.shoot == 1) {
            all->my_int.check = 0;
            sfSprite_setPosition(all->sprite.duck3_rev, all->pos.pos_duck_rev);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite.dead_duck3, all->pos.pos_save_rev);
            sfSound_play(all->sound.fall);
            sfClock_restart(all->clock.clock_dead);
        }
    }
}