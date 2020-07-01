/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** move_rect2
*/

#include "my.h"

sfIntRect move_red_duck(sfIntRect rect)
{
    if (rect.left == 360)
        rect.left = 0;
    else
        rect.left += 120;
    return (rect);
}