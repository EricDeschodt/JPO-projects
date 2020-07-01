/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** rect_init
*/

#include "my.h"

void rect_init2(rect_t *rect)
{
    rect->laugh_dog.top = 0;
    rect->laugh_dog.left = 0;
    rect->laugh_dog.width = 118;
    rect->laugh_dog.height = 88;
    rect->red_duck.top = 0;
    rect->red_duck.left = 0;
    rect->red_duck.width = 180;
    rect->red_duck.height = 100;
    rect->ammo_rect.top = 0;
    rect->ammo_rect.left = 0;
    rect->ammo_rect.width = 54;
    rect->ammo_rect.height = 22;
}

void rect_init(rect_t *rect)
{
    rect->dog_stop.top = 0;
    rect->dog_stop.left = 360;
    rect->dog_stop.width = 120;
    rect->dog_stop.height = 100;
    rect->dog.top = 0;
    rect->dog.left = 0;
    rect->dog.width = 120;
    rect->dog.height = 100;
    rect->duck.top = 0;
    rect->duck.left = 0;
    rect->duck.width = 80;
    rect->duck.height = 66;
    rect->menu_dog.top = 0;
    rect->menu_dog.left = 0;
    rect->menu_dog.width = 225;
    rect->menu_dog.height = 175;
    rect_init2(rect);
}