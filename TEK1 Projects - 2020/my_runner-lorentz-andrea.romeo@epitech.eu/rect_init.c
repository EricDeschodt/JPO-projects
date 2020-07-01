/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** rect_init
*/

#include "my.h"

void rect_ini2(rect_t *rect)
{
    rect->rect_up_throw.top = 0;
    rect->rect_up_throw.left = 0;
    rect->rect_up_throw.width = 155;
    rect->rect_up_throw.height = 273;
    rect->rect_down_throw.top = 0;
    rect->rect_down_throw.left = 0;
    rect->rect_down_throw.width = 130;
    rect->rect_down_throw.height = 160;
}

void rect_init(rect_t *rect)
{
    rect->rect_michael.top = 0;
    rect->rect_michael.left = 0;
    rect->rect_michael.width = 120;
    rect->rect_michael.height = 273;
    rect->rect_jump.top = 0;
    rect->rect_jump.left = 0;
    rect->rect_jump.width = 140;
    rect->rect_jump.height = 273;
    rect->rect_hit.top = 0;
    rect->rect_hit.left = 0;
    rect->rect_hit.width = 110;
    rect->rect_hit.height = 273;
    rect->rect_crouch_hit.top = 0;
    rect->rect_crouch_hit.left = 0;
    rect->rect_crouch_hit.width = 150;
    rect->rect_crouch_hit.height = 160;
    rect_ini2(rect);
}