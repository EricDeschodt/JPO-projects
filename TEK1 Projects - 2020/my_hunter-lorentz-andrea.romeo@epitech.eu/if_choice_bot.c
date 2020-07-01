/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** if_choice_bot
*/

#include "my.h"

void if_choice_is_6_bot(all_t *all, sfEvent event)
{
    if (all->my_int.choice == 6) {
        sfSprite_setPosition(all->sprite.duck1_bot, all->pos.pos_duck_bot);
        sfSprite_setTextureRect(all->sprite.duck1_bot, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck_bot.y != 450)
            sfRenderWindow_drawSprite(all->window, all->sprite.duck1_bot, NULL);
        if (all->pos.pos_duck_bot.y >= 450 && all->my_int.shoot == 1) {
            all->my_int.check = 0;
            sfSprite_setPosition(all->sprite.duck1_bot, all->pos.pos_duck_bot);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite.dead_duck1, all->pos.pos_save_bot);
            sfSound_play(all->sound.fall);
            sfClock_restart(all->clock.clock_dead);
        }
    }
}

void if_choice_is_7_bot(all_t *all, sfEvent event)
{
    if (all->my_int.choice == 7) {
        sfSprite_setPosition(all->sprite.duck2_bot, all->pos.pos_duck_bot);
        sfSprite_setTextureRect(all->sprite.duck2_bot, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck_bot.y != 450)
            sfRenderWindow_drawSprite(all->window, all->sprite.duck2_bot, NULL);
        if (all->pos.pos_duck_bot.y >= 450 && all->my_int.shoot == 1) {
            all->my_int.check = 0;
            sfSprite_setPosition(all->sprite.duck2_bot, all->pos.pos_duck_bot);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite.dead_duck2, all->pos.pos_save_bot);
            sfSound_play(all->sound.fall);
            sfClock_restart(all->clock.clock_dead);
        }
    }
}

void if_choice_is_8_bot(all_t *all, sfEvent event)
{
    if (all->my_int.choice == 8) {
        sfSprite_setPosition(all->sprite.duck3_bot, all->pos.pos_duck_bot);
        sfSprite_setTextureRect(all->sprite.duck3_bot, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck_bot.y != 450)
            sfRenderWindow_drawSprite(all->window, all->sprite.duck3_bot, NULL);
        if (all->pos.pos_duck_bot.y >= 450 && all->my_int.shoot == 1) {
            all->my_int.check = 0;
            sfSprite_setPosition(all->sprite.duck3_bot, all->pos.pos_duck_bot);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite.dead_duck3, all->pos.pos_save_bot);
            sfSound_play(all->sound.fall);
            sfClock_restart(all->clock.clock_dead);
        }
    }
}