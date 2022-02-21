/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** define, set up, draw the map
*/

#include "../include/project.h"

void idle_obs(t_window *window)
{
    window->map->time_obs = sfClock_getElapsedTime(window->map->clock_obs);
    window->map->seconds_obs = window->map->time_obs.microseconds / 1000000.0;
    if (window->map->seconds_obs >= 0.15) {
        window->map->rct_obs = move_rect(window->map->rct_obs, 31, 127, 2);
        sfSprite_setTextureRect(window->map->obs,
                                window->map->rct_obs);
        sfRenderWindow_drawSprite(window->window, window->map->obs, sfFalse);
        sfClock_restart(window->map->clock_obs);
    } else
        sfRenderWindow_drawSprite(window->window, window->map->obs, sfFalse);
}

void load_map(t_map *map)
{
    for (int r = 0; r < 6; r++)
        map->tab[r] = &map->buf[241 * r];
    map->tab[6] = NULL;
}

t_map *define_map(t_map *map)
{
    map->clock = sfClock_create();
    map->clock_obs = sfClock_create();
    map->obs_texture = sfTexture_createFromFile("./img/slime.png",
                                                        NULL);
    map->obs = sfSprite_create();
    map->buf = malloc(sizeof(char) * 1446);
    map->tab = malloc(sizeof(char *) * 7);
    sfVector2f scale_p = {(float) 3.7, (float) 4};
    sfSprite_setScale(map->obs, scale_p);
    sfSprite_setTexture(map->obs, map->obs_texture, sfFalse);
    map->rct_obs.left = 2;
    map->rct_obs.top  = 0;
    map->rct_obs.height = 25;
    map->rct_obs.width = 29;
    map->minest = 0;
    sfSprite_setTextureRect(map->obs, map->rct_obs);
    load_map(map);
    return map;
}
