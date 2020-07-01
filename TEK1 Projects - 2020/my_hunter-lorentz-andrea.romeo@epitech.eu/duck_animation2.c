/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** duck_animation2
*/

#include "my.h"

void duck_animation_dead2(all_t *all)
{
    if (all->my_int.save_choice == 2 || all->my_int.save_choice == 5
        || all->my_int.save_choice == 8)
        sfRenderWindow_drawSprite(all->window, all->sprite.dead_duck3, NULL);
    if (all->my_int.save_choice == 1 || all->my_int.save_choice == 4
        || all->my_int.save_choice == 7)
        sfRenderWindow_drawSprite(all->window, all->sprite.dead_duck2, NULL);
    if (all->my_int.save_choice == 0 || all->my_int.save_choice == 3
        || all->my_int.save_choice == 6)
        sfRenderWindow_drawSprite(all->window, all->sprite.dead_duck1, NULL);
    all->clock.time_dead = sfClock_getElapsedTime(all->clock.clock_dead);
    all->clock.seconds_dead = all->clock.time_dead.microseconds / 1000000.0;
    if (all->clock.seconds_dead >= 0.3) {
        all->my_int.shoot_check = 0;
        all->my_int.rand_check = 0;
    }
}

void duck_animation_dead(all_t *all)
{
    if (all->my_int.shoot_check == 1 && all->my_int.rand_check == 0) {
        all->my_int.save_choice = all->my_int.choice;
        all->my_int.rand_check = 1;
    }
    if (all->my_int.shoot_check2 == 1 && all->my_int.rand_check2 == 0) {
        all->my_int.save_choice2 = all->my_int.choice2;
        all->my_int.rand_check2 = 1;
    }
    if (all->my_int.shoot_check == 1)
        duck_animation_dead2(all);
    if (all->my_int.shoot_check2 == 1)
        duck_animation_dead3(all);
}

void if_duck2(all_t *all)
{
    if (all->my_int.choice2 == 0 || all->my_int.choice2 == 1 ||
        all->my_int.choice2 == 2) {
        if (all->pos.pos_duck2.x >= 850) {
            all->pos.pos_duck2.x = -120;
            all->my_int.check2 = 0;
            all->my_int.duck_spawn2++;
            all->pos.pos_duck2.y = rand() % 350;
        }
        else if (all->pos.pos_duck2.x < 850)
            all->pos.pos_duck2.x += all->my_int.x1;
        all->pos.pos_save2 = all->pos.pos_duck2;
    }
}

void if_duck_rev2(all_t *all)
{
    if (all->my_int.choice2 == 3 || all->my_int.choice2 == 4 ||
        all->my_int.choice2 == 5) {
        if (all->pos.pos_duck_rev2.x <= -50) {
            all->pos.pos_duck_rev2.x = 850;
            all->my_int.check2 = 0;
            all->my_int.duck_spawn2++;
            all->pos.pos_duck_rev2.y = rand() % 350;
        }
        else if (all->pos.pos_duck_rev2.x > -50)
            all->pos.pos_duck_rev2.x -= all->my_int.x1;
        all->pos.pos_save_rev2 = all->pos.pos_duck_rev2;
    }
}

void if_duck_bot2(all_t *all)
{
    if (all->my_int.choice2 == 6 || all->my_int.choice2 == 7 ||
        all->my_int.choice2 == 8) {
        if (all->pos.pos_duck_bot2.y <= -50) {
            all->pos.pos_duck_bot2.y = 450;
            all->my_int.check2 = 0;
            all->my_int.duck_spawn2++;
            all->pos.pos_duck_bot2.x = rand() % 740;
        }
        else if (all->pos.pos_duck_rev2.y > -50)
            all->pos.pos_duck_bot2.y -= all->my_int.x1;
        all->pos.pos_save_bot2 = all->pos.pos_duck_bot2;
    }
}