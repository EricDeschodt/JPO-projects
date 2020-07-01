/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** int_init
*/

#include "my.h"

void int_init3(int_t *my_int)
{
    my_int->new_round_clock = 0;
    my_int->end_round = 0;
    my_int->ammo_left = 3;
    my_int->perfect = 0;
    my_int->begin = 1;
}

void int_init2(int_t *my_int)
{
    my_int->menu_check = 0;
    my_int->spawn_count = 0;
    my_int->save_choice2 = 0;
    my_int->choice2 = 0;
    my_int->shoot2 = 0;
    my_int->check2 = 0;
    my_int->rand_check2 = 0;
    my_int->menu_dog = 0;
    my_int->duck_shoot = 0;
    my_int->duck_spawn1 = 0;
    my_int->duck_spawn2 = 0;
    my_int->laugh_dog_top = 0;
    my_int->dog_clock = 0;
    my_int->dog_clock2 = 0;
    my_int->dog_sound = 0;
    my_int->round_check = 0;
    my_int->clock_restart = 0;
    my_int->clock_round = 0;
    int_init3(my_int);
}

void int_init(int_t *my_int)
{
    my_int->x2 = 5;
    my_int->count = 0;
    my_int->wait = 0;
    my_int->choice = 0;
    my_int->check = 0;
    my_int->wing = 0;
    my_int->shoot = 0;
    my_int->shoot_check = 0;
    my_int->shoot_check2 = 0;
    my_int->intro_check = 0;
    my_int->dog_draw = 0;
    my_int->dog_draw2 = 0;
    my_int->dog_draw3 = 0;
    my_int->save_choice = 0;
    my_int->rand_check = 0;
    my_int->main_menu = 1;
    my_int->state = 0;
    my_int->gun_clock = 0;
    int_init2(my_int);
}
