/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** if_dead
*/

#include "my.h"

void if_dead0_1(all_t *all)
{
    if (all->my_int.choice2 == 0) {
        if (all->pos.pos_duck2.x <= -120 && all->my_int.shoot2 == 1) {
            all->my_int.check2 = 0;
            sfSprite_setPosition(all->sprite2.duck1_2, all->pos.pos_duck2);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite2.dead_duck1_2, all->pos.pos_save2);
            sfSound_play(all->sound.fall2);
            sfClock_restart(all->clock.clock_dead2);
        }
    }
    if (all->my_int.choice2 == 1) {
        if (all->pos.pos_duck2.x <= -120 && all->my_int.shoot2 == 1) {
            all->my_int.check2 = 0;
            sfSprite_setPosition(all->sprite2.duck2_2, all->pos.pos_duck2);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite2.dead_duck2_2, all->pos.pos_save2);
            sfSound_play(all->sound.fall2);
            sfClock_restart(all->clock.clock_dead2);
        }
    }
}

void if_dead2_1(all_t *all)
{
    if_dead2_1_2(all);
    if (all->my_int.choice2 == 6) {
        if (all->pos.pos_duck_bot2.y >= 450 && all->my_int.shoot2 == 1) {
            all->my_int.check2 = 0;
            sfSprite_setPosition(all->sprite2.duck1_bot2,
                all->pos.pos_duck_bot2);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite2.dead_duck1_2,
                all->pos.pos_save_bot2);
            sfSound_play(all->sound.fall2);
            sfClock_restart(all->clock.clock_dead2);
        }
    }
}

void if_dead7_8(all_t *all)
{
    if_dead7_8_2(all);
    if (all->my_int.choice2 == 8) {
        if (all->pos.pos_duck_bot2.y >= 450 && all->my_int.shoot2 == 1) {
            all->my_int.check2 = 0;
            sfSprite_setPosition(all->sprite2.duck3_bot2,
                all->pos.pos_duck_bot2);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite2.dead_duck3_2,
                all->pos.pos_save_bot2);
            sfSound_play(all->sound.fall2);
            sfClock_restart(all->clock.clock_dead2);
        }
    }
}

void if_dead3_4(all_t *all)
{
    if_dead3_4_2(all);
    if (all->my_int.choice2 == 4) {
        if (all->pos.pos_duck_rev2.x >= 850 && all->my_int.shoot2 == 1) {
            all->my_int.check2 = 0;
            sfSprite_setPosition(all->sprite2.duck2_rev2,
                all->pos.pos_duck_rev2);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite2.dead_duck2_2,
                all->pos.pos_save_rev2);
            sfSound_play(all->sound.fall2);
            sfClock_restart(all->clock.clock_dead2);
        }
    }
}

void if_dead5(all_t *all)
{
    if (all->my_int.choice2 == 5) {
        if (all->pos.pos_duck_rev2.x >= 850 && all->my_int.shoot2 == 1) {
            all->my_int.check2 = 0;
            sfSprite_setPosition(all->sprite2.duck3_rev2,
                all->pos.pos_duck_rev2);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite2.dead_duck3_2,
                all->pos.pos_save_rev2);
            sfSound_play(all->sound.fall2);
            sfClock_restart(all->clock.clock_dead2);
        }
    }
}