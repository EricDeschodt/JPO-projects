/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** dog_animation_round
*/

#include "my.h"

void perfect(all_t *all)
{
    if (all->clock.seconds_dog_jump >= 3.9
    && all->clock.seconds_dog_jump <= 4) {
        if (all->rect.red_duck.width == 380 && all->my_int.perfect == 0) {
            all->my_int.score_int += 10000;
            all->write.score = my_put_nbr(all->my_int.score_int,
                all->write.score);
            sfText_setString(all->write.text6, all->write.score);
            all->my_int.perfect = 1;
        }
    }
}

void dog_jump3(all_t *all)
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
            all->pos.pos_dog.x += 2;
            all->pos.pos_dog.y += 3;
            sfSprite_setPosition(all->sprite.dog_jump, all->pos.pos_dog);
        }
        if (all->clock.seconds_dog_jump > 7.6) {
            all->my_int.main_menu = 0;
            all->my_int.spawn_count = 0; }
    }
}

void dog_walking3(all_t *all)
{
    if (all->my_int.round_check == 0) {
        sfSound_play(all->sound.round);
        all->my_int.round_check = 1;
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

void dog_walking_round(all_t *all)
{
    perfect(all);
    if (all->clock.seconds_dog > 0.08 && all->clock.seconds_dog_jump < 6.1)
        dog_walking3(all);
    else if (all->clock.seconds_dog_jump >= 6.1) {
        if (all->my_int.dog_draw != 1)
            all->my_int.dog_draw = 1;
        dog_jump(all);
    }
    dog_jump3(all);
}