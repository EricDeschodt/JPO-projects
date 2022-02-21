/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** parallax function
*/

#include "../include/project.h"

void move_parallax(t_window *window, int speed)
{
    window->rect->l1_rect.left += speed - 8;
    window->rect->l2_rect.left += speed - 7;
    window->rect->l3_rect.left += speed - 6;
    window->rect->l4_rect.left += speed - 5;
    window->rect->l5_rect.left += speed - 4;
    window->rect->l6_rect.left += speed - 3;
    window->rect->l7_rect.left += speed - 2;
    window->rect->l8_rect.left += speed - 1;
    window->rect->l9_rect.left += speed;
}

void set_rect(t_window *window)
{
    sfSprite_setTextureRect(window->px->layer01, window->rect->l1_rect);
    sfSprite_setTextureRect(window->px->layer02, window->rect->l2_rect);
    sfSprite_setTextureRect(window->px->layer03, window->rect->l3_rect);
    sfSprite_setTextureRect(window->px->layer04, window->rect->l4_rect);
    sfSprite_setTextureRect(window->px->layer05, window->rect->l5_rect);
    sfSprite_setTextureRect(window->px->layer06, window->rect->l6_rect);
    sfSprite_setTextureRect(window->px->layer07, window->rect->l7_rect);
    sfSprite_setTextureRect(window->px->layer08, window->rect->l8_rect);
    sfSprite_setTextureRect(window->px->layer09, window->rect->l9_rect);
}

void px_animation(t_window *window, int speed)
{
    window->px->time = sfClock_getElapsedTime(window->px->clock);
    window->px->seconds = window->px->time.microseconds / 1000000.0;
    if (window->px->seconds >= (float) 1/60) {
        move_parallax(window, speed);
        set_rect(window);
        draw_background(window);
        sfClock_restart(window->px->clock);
    } else
        draw_background(window);
}
