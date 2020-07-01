/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** rect
*/

#include "runner.h"

void move_rect_runner(controll_t *s_controll, int offset, int max_value)
{
    if (s_controll->s_runner.rect.left < max_value - offset) {
        s_controll->s_runner.rect.left += offset;
    }
    else
        s_controll->s_runner.rect.left = 0;
}

void move_rect_slide(controll_t *s_controll, int offset, int max_value)
{
    if (s_controll->s_slide.rect.left < max_value - offset) {
        s_controll->s_slide.rect.left += offset;
    }
    else
        s_controll->s_slide.rect.left = 0;
}

void move_rect_coin(coin_t *s_coin, int offset, int max_value)
{
    if (s_coin->rect.left < max_value - offset) {
        s_coin->rect.left += offset;
    }
    else
        s_coin->rect.left = 0;
}

void move_rect_jelly(controll_t *s_controll, int offset, int max_value)
{
    if (s_controll->s_jelly.rect.left < max_value - offset) {
        s_controll->s_jelly.rect.left += offset;
    }
    else
        s_controll->s_jelly.rect.left = 0;
}

void move_rect_monster(monster1_t *s_monster, int offset, int max_value)
{
    if (s_monster->rect.left < max_value - offset) {
        s_monster->rect.left += offset;
    }
    else
        s_monster->rect.left = 0;
}