/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** if_choice
*/

#include "my.h"

void if_choice_is_0(all_t *all, sfEvent event)
{
    if (all->my_int.choice == 0) {
        sfSprite_setPosition(all->sprite.duck1, all->pos.pos_duck);
        sfSprite_setTextureRect(all->sprite.duck1, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck.x != -120)
            sfRenderWindow_drawSprite(all->window, all->sprite.duck1, NULL);
        if (all->pos.pos_duck.x <= -120 && all->my_int.shoot == 1) {
            all->my_int.check = 0;
            sfSprite_setPosition(all->sprite.duck1, all->pos.pos_duck);
            sfSprite_setPosition(all->sprite.dead_duck1,
                                    all->pos.pos_save);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSound_play(all->sound.fall);
            sfClock_restart(all->clock.clock_dead);
        }
    }
}

void if_choice_is_1(all_t *all, sfEvent event)
{
    if (all->my_int.choice == 1) {
        sfSprite_setPosition(all->sprite.duck2, all->pos.pos_duck);
        sfSprite_setTextureRect(all->sprite.duck2, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck.x != -120)
            sfRenderWindow_drawSprite(all->window, all->sprite.duck2, NULL);
        if (all->pos.pos_duck.x <= -120 && all->my_int.shoot == 1) {
            all->my_int.check = 0;
            sfSprite_setPosition(all->sprite.duck2, all->pos.pos_duck);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite.dead_duck2,
                                    all->pos.pos_save);
            sfSound_play(all->sound.fall);
            sfClock_restart(all->clock.clock_dead);
        }
    }
}

void if_choice_is_2(all_t *all, sfEvent event)
{
    if (all->my_int.choice == 2) {
        sfSprite_setPosition(all->sprite.duck3, all->pos.pos_duck);
        sfSprite_setTextureRect(all->sprite.duck3, all->rect.duck);
        analyse_events(event, all);
        if (all->pos.pos_duck.x != -120)
            sfRenderWindow_drawSprite(all->window, all->sprite.duck3, NULL);
        if (all->pos.pos_duck.x <= -120 && all->my_int.shoot == 1) {
            all->my_int.check = 0;
            sfSprite_setPosition(all->sprite.duck3, all->pos.pos_duck);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite.dead_duck3,
                                    all->pos.pos_save);
            sfSound_play(all->sound.fall);
            sfClock_restart(all->clock.clock_dead);
        }
    }
}

void spawn_duck_2(all_t *all, sfEvent event)
{
    if (all->my_int.duck_spawn2 < 1 && all->my_int.game_mode == 1) {
        if_choice_is_0_2(all, event);
        if_choice_is_1_2(all, event);
        if_choice_is_2_2(all, event);
        if_choice_is_3_rev_2(all, event);
        if_choice_is_4_rev_2(all, event);
        if_choice_is_5_rev_2(all, event);
        if_choice_is_6_bot_2(all, event);
        if_choice_is_7_bot_2(all, event);
        if_choice_is_8_bot_2(all, event);
    }
}

void regroup_if_choice(all_t *all, sfEvent event)
{
    if (all->my_int.duck_spawn1 < 1) {
        if_choice_is_0(all, event);
        if_choice_is_1(all, event);
        if_choice_is_2(all, event);
        if_choice_is_3_rev(all, event);
        if_choice_is_4_rev(all, event);
        if_choice_is_5_rev(all, event);
        if_choice_is_6_bot(all, event);
        if_choice_is_7_bot(all, event);
        if_choice_is_8_bot(all, event);
    }
    spawn_duck_2(all, event);
    if (all->my_int.game_mode == 1) {
        if_dead0_1(all), if_dead2_1(all);
        if_dead7_8(all);
        if_dead3_4(all);
        if_dead5(all);
    }
    duck_animation_dead(all);
    dog_spawn(all, event);
}
