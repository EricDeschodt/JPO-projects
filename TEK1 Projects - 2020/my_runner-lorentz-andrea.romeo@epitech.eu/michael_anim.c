/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** michael_anim
*/

#include "my.h"

void moonwalk_rect(all_t *all)
{
    if (all->my_int.i == 1)
        all->rect.rect_michael.width = 80, all->rect.rect_michael.left -= 5;
    if (all->my_int.i == 2)
        all->rect.rect_michael.left -= 37;
    if (all->my_int.i == 3)
        all->rect.rect_michael.width = 100, all->rect.rect_michael.left -= 25;
    if (all->my_int.i == 4)
        all->rect.rect_michael.left -= 19;
    if (all->my_int.i == 5)
        all->rect.rect_michael.width = 85, all->rect.rect_michael.left -= 19;
    if (all->my_int.i == 6)
        all->rect.rect_michael.left -= 37;
    if (all->my_int.i == 8)
        all->rect.rect_michael.width = 80, all->rect.rect_michael.left -= 10;
    if (all->my_int.i == 9)
        all->rect.rect_michael.width = 95, all->rect.rect_michael.left -= 35;
    if (all->my_int.i == 10)
        all->rect.rect_michael.left -= 15;
    sfSprite_setTextureRect(all->sprite.michael, all->rect.rect_michael);
}

void michael_rect_jump(all_t *all)
{
    if (all->my_int.jump_count == 6) {
        all->rect.rect_jump.left = 140;
        sfSprite_setTextureRect(all->sprite.jump, all->rect.rect_jump);
    }
    else if (all->my_int.jump_count == 24) {
        all->rect.rect_jump.left = 280;
        sfSprite_setTextureRect(all->sprite.jump, all->rect.rect_jump);
    }
}

void michael_jump_bis(all_t *all)
{
    if (all->my_int.energy == 1)
        all->my_int.high = 1;
    if (all->clock.seconds_jump > 0.01 && all->my_int.high == 1
        && all->my_int.energy < 11) {
        all->my_int.jump_count++;
        all->my_int.energy++, all->pos.pos_michael.y += all->my_int.energy;
        michael_jump_set(all);
        sfClock_restart(all->clock.clock_jump);
    }
    if (all->clock.seconds_jump > 0.01 && all->my_int.index != -1
        && all->my_int.high == 1 && all->my_int.energy == 11) {
        all->my_int.jump_count++;
        all->pos.pos_michael.y += all->my_int.gravity[all->my_int.index];
        all->my_int.index--;
        michael_jump_set(all);
        sfClock_restart(all->clock.clock_jump);
    }
}

void michael_jump(all_t *all)
{
    if (all->my_int.jump == 1) {
        clock_set(all), michael_rect_jump(all);
        if (all->clock.seconds_jump > 0.01 && all->my_int.energy > 1 &&
        all->my_int.high == 0) {
            all->my_int.jump_count++, all->pos.pos_michael.y -=
                all->my_int.energy, all->my_int.energy /= 1.1;
            michael_jump_set(all);
            sfClock_restart(all->clock.clock_jump);
        } michael_jump_bis(all);
        if (all->my_int.index == -1) {
            all->my_int.jump = 0, all->my_int.energy = 30;
            all->my_int.high = 0, all->my_int.index = 7;
            all->my_int.jump_count = 0, all->rect.rect_jump.left = 0;
            sfSprite_setTextureRect(all->sprite.jump, all->rect.rect_jump);
            sfSprite_setPosition(all->sprite.hit, all->pos.pos_michael);
            sfSprite_setPosition(all->sprite.up_throw, all->pos.pos_michael);
            all->pos.pos_hat.y = 580;
        }
    }
}

void michael_moonwalk(all_t *all)
{
    if (all->clock.seconds_michael > 0.10 && all->my_int.menu != 5) {
        night_day_cycle(all);
        if (all->rect.rect_michael.left >= 1115)
            all->rect.rect_michael.left = 0, all->my_int.i = -1;
        else all->rect.rect_michael.left += 120;
        moonwalk_rect(all);
        all->my_int.i++, sfClock_restart(all->clock.clock_michael);
    }
}
