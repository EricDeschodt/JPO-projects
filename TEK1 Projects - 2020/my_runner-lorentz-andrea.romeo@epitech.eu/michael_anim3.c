/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** michael_anim3
*/

#include "my.h"

void michael_down_throw2(all_t *all)
{
    if (all->my_int.hit_time > 2 && all->my_int.hit_time < 4)
        all->rect.rect_down_throw.left += 140, all->pos.pos_hat.y = 690;
    if (all->my_int.hit_time > 4 && all->my_int.hit_time < 6)
        all->rect.rect_down_throw.left += 140;
    if (all->my_int.hit_time > 6 && all->my_int.hit_time < 8)
        all->rect.rect_down_throw.left += 110, all->my_int.hat = 1;
    if (all->my_int.hit_time >= 8 && all->my_int.hit_time <= 16)
        all->pos.pos_hat.x += 130;
    else if (all->my_int.hit_time >= 17 && all->my_int.hit_time <= 25)
        all->pos.pos_hat.x -= 130;
    if (all->my_int.hit_time > 25 && all->my_int.hit_time < 27)
        all->rect.rect_down_throw.left -= 110, all->my_int.hat = 0;
    if (all->my_int.hit_time > 27 && all->my_int.hit_time < 29)
        all->rect.rect_down_throw.left -= 140;
    if (all->my_int.hit_time > 29 && all->my_int.hit_time < 31)
        all->rect.rect_down_throw.left -= 140;
    all->my_int.hit_time++;
}

void michael_down_throw(all_t *all)
{
    if (all->clock.seconds_hit > 0.01 && all->my_int.down_throw == 1) {
        michael_down_throw2(all);
        if (all->my_int.hit_time > 30 && all->my_int.hit_time < 32) {
            all->my_int.hit_time = 0, all->my_int.down_throw = 0;
            all->rect.rect_down_throw.left = 0, all->pos.pos_hat.x = 435;
            sfSprite_setPosition(all->sprite.hat, all->pos.pos_hat);
            if (all->my_int.check_throw == 0)
                all->my_int.crouch = 0;
        }
        sfSprite_setPosition(all->sprite.hat, all->pos.pos_hat);
        sfClock_restart(all->clock.clock_hit);
        sfSprite_setTextureRect(all->sprite.down_throw,
                                all->rect.rect_down_throw);
    }
}