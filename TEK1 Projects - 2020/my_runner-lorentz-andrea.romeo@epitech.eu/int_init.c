/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** int_init
*/

#include "my.h"

void int_init2(int_t *my_int)
{
    my_int->hit_crouch = 0;
    my_int->hit_check = 0;
    my_int->up_throw = 0;
    my_int->down_throw = 0;
    my_int->hat = 0;
    my_int->check_throw = 0;
    my_int->rect_flying = 0;
    my_int->reset = 0;
    my_int->alpha = 0;
    my_int->day = 0;
    my_int->ia = 1;
    my_int->menu = 1;
    my_int->reset_menu = 0;
    my_int->level = 0;
    my_int->skull = 0;
}

void int_init(int_t *my_int)
{
    my_int->gravity[0] = 30;
    my_int->gravity[1] = 27;
    my_int->gravity[2] = 24;
    my_int->gravity[3] = 21;
    my_int->gravity[4] = 19;
    my_int->gravity[5] = 17;
    my_int->gravity[6] = 15;
    my_int->gravity[7] = 13;
    my_int->i = 0;
    my_int->energy = 0;
    my_int->jump = 0;
    my_int->high = 0;
    my_int->index = 7;
    my_int->jump_sound = 0;
    my_int->jump_count = 0;
    my_int->crouch = 0;
    my_int->hit = 0;
    my_int->hit_time = 0;
    my_int->speed = 200;
    int_init2(my_int);
}
