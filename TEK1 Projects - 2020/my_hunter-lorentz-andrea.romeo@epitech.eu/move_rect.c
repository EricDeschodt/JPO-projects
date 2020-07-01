/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** move_rect
*/

#include "my.h"

sfIntRect move_dog(sfIntRect rect)
{
    if (rect.left == 360)
        rect.left = 0;
    else
        rect.left += 120;
    return (rect);
}

sfIntRect move_duck(sfIntRect rect)
{
    if (rect.left == 160)
        rect.left = 0;
    else
        rect.left += 80;
    return (rect);
}

sfIntRect move_dog_stop(sfIntRect rect)
{
    if (rect.left == 480)
        rect.left = 360;
    else
        rect.left += 120;
    return (rect);
}

sfIntRect move_menu_dog(sfIntRect rect)
{
    if (rect.left == 215)
        rect.left = 0;
    else
        rect.left += 215;
    return (rect);
}

sfIntRect move_laugh_dog(sfIntRect rect)
{
    if (rect.left == 108)
        rect.left = 0;
    else
        rect.left += 108;
    return (rect);
}