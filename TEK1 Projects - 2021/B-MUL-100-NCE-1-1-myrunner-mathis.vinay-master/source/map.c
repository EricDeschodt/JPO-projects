/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** fnc to handle the map structure
*/

#include "../include/map.h"

void *free_null(void *obj)
{
    free(obj);
    return NULL;
}

map_t *create_map(char const *filename, const char *textures)
{
    map_t *map = malloc(sizeof(map_t));
    map->str = my_get_file_ctn(filename);
    if (!map->str)
        return free_null(map);
    map->tab = malloc(sizeof(char *) * 7);
    map->tab[0] = map->str;
    for (int i = 1; i < 7; i++)
        map->tab[i] = &map->str[my_indexn(map->str, '\n', i) + 1];
    map->x = 160;
    map->offset = 0;
    map->rang = 0;
    map->texture = sfTexture_createFromFile(textures, NULL);
    map->sprite = sfSprite_create();
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    sfIntRect rect = {0, 0, 999, 999};
    sfSprite_setTextureRect(map->sprite, rect);
    float n = (float)(((double)((double)(1080)/7))/999);
    sfVector2f scale = {n, n};
    sfSprite_setScale(map->sprite, scale);
    return map;
}

bool display_block(sfRenderWindow *win, map_t *map, int y, int x)
{
    if (('A' > map->tab[y][x + map->rang] || map->tab[y][x + map->rang] > 'S')
    && x + map->rang < map->x)
        return false;
    if (x + map->rang >= map->x && y < 6)
        return false;
    short sup_j = (map->tab[y][x + map->rang] > 'J') ? 1 : 0;
    sfIntRect rect = {(map->tab[y][x + map->rang] - 'A') * 999 - (sup_j
    * 9990), (sup_j) ? 999 : 0, 999, 999};
    if (x + map->rang >= map->x && y == 6) {
        rect.left = 999;
        rect.top = 0;
    }
    sfSprite_setTextureRect(map->sprite, rect);
    double t = (double)((double)(1080)/7);
    sfVector2f pos = {(float)(t * (double)x) + map->offset, (float)
        (t * (double)y)};
    sfSprite_setPosition(map->sprite, pos);
    sfRenderWindow_drawSprite(win, map->sprite, NULL);
    return true;
}

map_t *display_map(sfRenderWindow *win, map_t *map)
{
    for (int y = 0; y < 7; y++)
        for (int x = 0; x < 14; x++)
            display_block(win, map, y, x);
    return map;
}

void destroy_map(map_t *map)
{
    sfTexture_destroy(map->texture);
    sfSprite_destroy(map->sprite);
    free(map->str);
    free(map->tab);
    free(map);
}