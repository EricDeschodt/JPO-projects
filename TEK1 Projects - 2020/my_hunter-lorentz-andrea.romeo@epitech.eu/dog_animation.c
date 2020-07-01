/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** dog_animation
*/

#include "my.h"

void dog_count_wait(all_t *all)
{
    if (all->my_int.count != 27)
        all->rect.dog.left = move_dog(all->rect.dog).left;
    else {
        all->rect.dog_stop.left = move_dog_stop(all->rect.dog_stop).left;
        all->rect.dog.left = all->rect.dog_stop.left;
    }
    if (all->my_int.wait == 4) {
        all->my_int.wait = 0;
        all->my_int.count = 0;
    }
}

void dog_walking2(all_t *all)
{
    if (all->my_int.intro_check == 0) {
        sfSound_play(all->sound.intro);
        all->my_int.intro_check = 1;
    }
    sfSprite_setPosition(all->sprite.dog, all->pos.pos_dog);
    if (all->rect.dog.left == 480)
        all->rect.dog.left = 0;
    else if (all->my_int.count == 27 && all->my_int.wait != 4)
        all->my_int.wait++;
    else {
        all->pos.pos_dog.x += all->my_int.x2;
        all->my_int.count++;
    }
    dog_count_wait(all);
    sfSprite_setTextureRect(all->sprite.dog, all->rect.dog);
    sfClock_restart(all->clock.clock_dog);
}

void dog_walking(all_t *all)
{
    if (all->clock.seconds_dog > 0.08 && all->clock.seconds_dog_jump < 6.1)
        dog_walking2(all);
    else if (all->clock.seconds_dog_jump >= 6.1) {
        all->my_int.dog_draw = 1;
        dog_jump(all);
    }
    dog_jump2(all);
}

void dog_jump2(all_t *all)
{
    if (all->clock.seconds_dog_jump2 > 0.4 && all->my_int.dog_draw2 == 1) {
        if (all->clock.seconds_dog_jump <= 7.1) {
            all->pos.pos_dog.x += 2;
            all->pos.pos_dog.y -= 3;
            sfSprite_setPosition(all->sprite.dog_jump, all->pos.pos_dog);
        }
        else if (all->clock.seconds_dog_jump <= 7.6) {
            all->my_int.dog_draw3 = 1;
            all->rect.dog.left = 200;
            sfSprite_setTextureRect(all->sprite.dog_jump, all->rect.dog);
            all->pos.pos_dog.x += 2, all->pos.pos_dog.y += 3;
            sfSprite_setPosition(all->sprite.dog_jump, all->pos.pos_dog);
        }
        if (all->clock.seconds_dog_jump > 7.6) {
            all->pos.pos_dog.x = 15;
            sfSprite_setPosition(all->sprite.dog, all->pos.pos_dog);
        }
    }
}

void dog_jump(all_t *all)
{
    if (all->clock.seconds_dog_jump >= 6.1 && all->my_int.dog_draw2 != 1) {
        sfSprite_setPosition(all->sprite.dog_jump, all->pos.pos_dog);
        if (all->clock.seconds_dog_jump >= 6.6 && all->my_int.dog_draw2 == 0) {
            all->my_int.dog_draw2 = 1;
            all->rect.dog.left = 105;
        }
        else if (all->my_int.dog_draw2 == 0)
            all->rect.dog.left = 0;
        sfSprite_setTextureRect(all->sprite.dog_jump, all->rect.dog);
    }
}