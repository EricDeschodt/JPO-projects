/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** duck_animation
*/

#include "my.h"

void duck_wing_sound(all_t *all)
{
    all->my_int.wing++;
    if (all->my_int.game_mode == 1) {
        if (all->my_int.wing == 2 && (all->my_int.duck_spawn1 != 1
            || all->my_int.duck_spawn2 != 1))
            sfSound_play(all->sound.wing);
        if (all->my_int.wing == 2)
            all->my_int.wing = 0;
    }
    else {
        if (all->my_int.wing == 2 && (all->my_int.duck_spawn1 != 1
            && all->my_int.duck_spawn2 != 1))
            sfSound_play(all->sound.wing);
        if (all->my_int.wing == 2)
            all->my_int.wing = 0;
    }
}

void if_duck(all_t *all)
{
    if (all->my_int.choice == 0 || all->my_int.choice == 1 ||
        all->my_int.choice == 2) {
        if (all->pos.pos_duck.x >= 850) {
            all->pos.pos_duck.x = -120;
            all->my_int.check = 0;
            all->my_int.duck_spawn1++;
            all->pos.pos_duck.y = rand() % 350;
        }
        else if (all->pos.pos_duck.x < 850)
            all->pos.pos_duck.x += all->my_int.x1;
        all->pos.pos_save = all->pos.pos_duck;
    }
}

void if_duck_rev(all_t *all)
{
    if (all->my_int.choice == 3 || all->my_int.choice == 4 ||
        all->my_int.choice == 5) {
        if (all->pos.pos_duck_rev.x <= -50) {
            all->pos.pos_duck_rev.x = 850;
            all->my_int.check = 0;
            all->my_int.duck_spawn1++;
            all->pos.pos_duck_rev.y = rand() % 350;
        }
        else if (all->pos.pos_duck_rev.x > -50)
            all->pos.pos_duck_rev.x -= all->my_int.x1;
        all->pos.pos_save_rev = all->pos.pos_duck_rev;
    }
}

void if_duck_bot(all_t *all)
{
    if (all->my_int.choice == 6 || all->my_int.choice == 7 ||
        all->my_int.choice == 8) {
        if (all->pos.pos_duck_bot.y <= -50) {
            all->pos.pos_duck_bot.y = 450;
            all->my_int.check = 0;
            all->my_int.duck_spawn1++;
            all->pos.pos_duck_bot.x = rand() % 740;
        }
        else if (all->pos.pos_duck_rev.y > -50)
            all->pos.pos_duck_bot.y -= all->my_int.x1;
        all->pos.pos_save_bot = all->pos.pos_duck_bot;
    }
}

void duck_animation(all_t *all)
{
    if (all->clock.seconds_dog_jump > 8) {
        all->my_int.clock_restart = 0;
        duck_wing_sound(all);
        if (all->my_int.check != 1) {
            all->my_int.choice = rand() % 9;
            all->my_int.check = 1;
        }
        if_duck(all);
        if_duck_rev(all);
        if_duck_bot(all);
        if (all->my_int.check2 != 1) {
            all->my_int.choice2 = rand() % 9;
            all->my_int.check2 = 1;
        }
        duck_overlap(all);
        if_duck2(all);
        if_duck_rev2(all);
        if_duck_bot2(all);
        all->rect.duck.left = move_duck(all->rect.duck).left;
    }
}