/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** if_dead2.c
*/

#include "my.h"

void if_dead2_1_2(all_t *all)
{
    if (all->my_int.choice2 == 2) {
        if (all->pos.pos_duck2.x <= -120 && all->my_int.shoot2 == 1) {
            all->my_int.check2 = 0;
            sfSprite_setPosition(all->sprite2.duck3_2, all->pos.pos_duck2);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite2.dead_duck3_2, all->pos.pos_save2);
            sfSound_play(all->sound.fall2);
            sfClock_restart(all->clock.clock_dead2);
        }
    }
}

void if_dead7_8_2(all_t *all)
{
    if (all->my_int.choice2 == 7) {
        if (all->pos.pos_duck_bot2.y >= 450 && all->my_int.shoot2 == 1) {
            all->my_int.check2 = 0;
            sfSprite_setPosition(all->sprite2.duck2_bot2,
                all->pos.pos_duck_bot2);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite2.dead_duck2_2,
                all->pos.pos_save_bot2);
            sfSound_play(all->sound.fall2);
            sfClock_restart(all->clock.clock_dead2);
        }
    }
}

void if_dead3_4_2(all_t *all)
{
    if (all->my_int.choice2 == 3) {
        if (all->pos.pos_duck_rev2.x >= 850 && all->my_int.shoot2 == 1) {
            all->my_int.check2 = 0;
            sfSprite_setPosition(all->sprite2.duck1_rev2,
                all->pos.pos_duck_rev2);
            sfRenderWindow_clear(all->window, sfWhite);
            sfSprite_setPosition(all->sprite2.dead_duck1_2,
                all->pos.pos_save_rev2);
            sfSound_play(all->sound.fall2);
            sfClock_restart(all->clock.clock_dead2);
        }
    }
}