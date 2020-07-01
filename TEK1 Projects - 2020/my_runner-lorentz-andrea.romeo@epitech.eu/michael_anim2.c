/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** michael_anim2
*/

#include "my.h"

void michael_jump_set(all_t *all)
{
    sfSprite_setPosition(all->sprite.jump, all->pos.pos_michael);
    sfSprite_setPosition(all->sprite.hit, all->pos.pos_michael);
    sfSprite_setPosition(all->sprite.up_throw, all->pos.pos_michael);
    all->pos.pos_hat.y = all->pos.pos_michael.y + 60;
}

void michael_up_throw2(all_t *all)
{
    if (all->my_int.hit_time > 29 && all->my_int.hit_time < 31)
        all->my_int.hat = 0, all->rect.rect_up_throw.left -= 114;
    if (all->my_int.hit_time > 31 && all->my_int.hit_time < 33) {
        all->rect.rect_up_throw.left -= 155;
        all->rect.rect_up_throw.width += 30;
    }
    if (all->my_int.hit_time > 33 && all->my_int.hit_time < 35)
        all->rect.rect_up_throw.left -= 150;
    if (all->my_int.hit_time > 35 && all->my_int.hit_time < 37) {
        all->rect.rect_up_throw.left -= 151;
        all->rect.rect_up_throw.width += 10;
    }
    all->my_int.hit_time++;
    if (all->my_int.hit_time > 37 && all->my_int.hit_time < 39) {
        all->my_int.hit_time = 0, all->my_int.up_throw = 0;
        all->rect.rect_up_throw.left = 0, all->rect.rect_up_throw.width = 155;
        all->pos.pos_hat.x = 435;
        sfSprite_setPosition(all->sprite.hat, all->pos.pos_hat);
    }
    sfSprite_setPosition(all->sprite.hat, all->pos.pos_hat);
}

void michael_up_throw(all_t *all)
{
    if (all->clock.seconds_hit > 0.01 && all->my_int.up_throw == 1) {
        if (all->my_int.hit_time > 2 && all->my_int.hit_time < 4) {
            all->rect.rect_up_throw.left += 151, all->pos.pos_hat.y = 580;
            all->rect.rect_up_throw.width -= 10;
        }
        if (all->my_int.hit_time > 4 && all->my_int.hit_time < 6)
            all->rect.rect_up_throw.left += 150;
        if (all->my_int.hit_time > 6 && all->my_int.hit_time < 8) {
            all->rect.rect_up_throw.left += 155;
            all->rect.rect_up_throw.width -= 30;
        }
        if (all->my_int.hit_time > 8 && all->my_int.hit_time < 10)
            all->rect.rect_up_throw.left += 114, all->my_int.hat = 1;
        if (all->my_int.hit_time >= 10 && all->my_int.hit_time < 20)
            all->pos.pos_hat.x += 120;
        else if (all->my_int.hit_time >= 20 && all->my_int.hit_time < 30)
            all->pos.pos_hat.x -= 120;
        michael_up_throw2(all), sfClock_restart(all->clock.clock_hit);
        sfSprite_setTextureRect(all->sprite.up_throw, all->rect.rect_up_throw);
    }
}

void michael_hit_crouch(all_t *all)
{
    if (all->clock.seconds_hit > 0.01 && all->my_int.hit_crouch == 1) {
        if (all->my_int.hit_time > 1 && all->my_int.hit_time < 3) {
            all->rect.rect_crouch_hit.left += 150;
            all->rect.rect_crouch_hit.width += 100;
        }
        if (all->my_int.hit_time > 7 && all->my_int.hit_time < 9) {
            all->rect.rect_crouch_hit.left -= 150;
            all->rect.rect_crouch_hit.width -= 100;
        }
        all->my_int.hit_time++;
        if (all->my_int.hit_time > 9 && all->my_int.hit_time < 11)
            all->my_int.hit_time = 0, all->my_int.hit_crouch = 0;
        sfSprite_setTextureRect(all->sprite.crouch_hit,
            all->rect.rect_crouch_hit);
        sfClock_restart(all->clock.clock_hit);
    }
}

void michael_hit(all_t *all)
{
    if (all->clock.seconds_hit > 0.01 && all->my_int.hit == 1) {
        if (all->my_int.hit_time > 1 && all->my_int.hit_time < 3)
            all->rect.rect_hit.left += 120, all->rect.rect_hit.width += 60;
        if (all->my_int.hit_time > 2 && all->my_int.hit_time < 4)
            all->rect.rect_hit.left += 165, all->rect.rect_hit.width += 60;
        all->my_int.hit_time++;
        if (all->my_int.hit_time > 8 && all->my_int.hit_time < 10)
            all->rect.rect_hit.left -= 165, all->rect.rect_hit.width -= 60;
        if (all->my_int.hit_time > 10 && all->my_int.hit_time < 12)
            all->rect.rect_hit.left -= 120, all->rect.rect_hit.width -= 60;
        if (all->my_int.hit_time > 11 && all->my_int.hit_time < 13) {
            all->my_int.hit_time = 0, all->my_int.hit = 0;
            all->rect.rect_hit.left = 0, all->rect.rect_hit.width = 110;
        }
        sfSprite_setTextureRect(all->sprite.hit, all->rect.rect_hit);
        sfClock_restart(all->clock.clock_hit);
    }
}