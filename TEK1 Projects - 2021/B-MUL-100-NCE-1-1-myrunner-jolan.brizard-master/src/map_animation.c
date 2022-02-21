/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** map function
*/

#include "../include/project.h"

void reset_blocks(t_window *window)
{
    if (window->map->minest >= 128) {
        window->map->index += 1;
        window->map->minest = 12;
    } else
        window->map->minest += 12;
}

void move_blocks(t_window *window)
{
    window->map->pos.x -= (float) window->map->minest;
    sfSprite_setPosition(window->map->obs, window->map->pos);
    idle_obs(window);
}

void place_blocks(t_window *window, int y, int x)
{
    if (window->map->tab[y][window->map->index + x] == ' ')
        return;
    else {
        sfVector2f pos = {(float) x * (float) 128,
                            (float) y * (float) 120 + (float) 88.6 };
        window->map->pos = pos;
        move_blocks(window);
        win_lose(window);
    }
}

void draw_blocks(t_window *window)
{
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 11; x++) {
            place_blocks(window, y, x);
        }
    }
}

void draw_map(t_window *window)
{
    window->map->time = sfClock_getElapsedTime(window->map->clock);
    window->map->seconds = window->map->time.microseconds / 1000000.0;
    if (window->map->seconds >= 0.016667) {
        reset_blocks(window);
        draw_blocks(window);
        sfClock_restart(window->map->clock);
    } else {
        draw_blocks(window);
    }
}