/*
** EPITECH PROJECT, 2020
** defender
** File description:
** map
*/

#include "defender.h"

s_map *create_map_object(char *filepath, v2 pos, e_type type)
{
    s_map *obj = malloc(sizeof(*obj));
    obj->pos = pos;
    obj->type = type;
    obj->texture = sfTexture_createFromFile(filepath, NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setOrigin(obj->sprite, (v2){24, 24});
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setPosition(obj->sprite, obj->pos);
    return (obj);
}

int find_flag(char c)
{
    char map_flags[] = "LcCTBrlgGRfhkjyt";
    int i = 0;
    while (map_flags[i] != '\0') {
        if (c == map_flags[i])
            return (i);
        i++;
    }
    return (-1);
}

void create_map(s_game *game, char *path[], char *maps[], char *slots[])
{
    int fd = 0, i = 0;
    s_var tmp;
    tmp.x = 24, tmp.y = 24, tmp.k = 0, tmp.n = 0, tmp.j = 0;
    for (; tmp.j < 5; tmp.j++) {
        fd = open(maps[tmp.j], O_RDONLY), tmp.x = 24, tmp.y = 24, tmp.n = 0,
        tmp.k = 0;
        while (read(fd, &tmp.c, 1) > 0) {
            if (tmp.c == '\n') {
                tmp.x = 24, tmp.y += 48, tmp.n = 0, tmp.k++;
                continue;
            }
            create_map_back(game, &tmp, slots, path);
            i = find_flag(tmp.c);
            create_grid(game, &tmp, i);
            tmp.x += 48, tmp.n++;
        }
        close(fd);
    }
}

void create_grid(s_game *game, s_var *tmp, int i)
{
    if (i < 9) {
        game->grid[tmp->j][tmp->k][tmp->n].move = PREV;
        game->grid[tmp->j][tmp->k][tmp->n].pos = (v2){tmp->x, tmp->y};
    }
    else if (i > 8 && i < 15){
        game->grid[tmp->j][tmp->k][tmp->n].move = NEXT;
        game->grid[tmp->j][tmp->k][tmp->n].pos = (v2){tmp->x, tmp->y};
    }
}

void draw_map(s_game *game)
{
    for (l_list *tmp = game->maps[game->levels];
    tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(game->window, tmp->map->sprite, NULL);
    }
    sfRenderWindow_drawSprite(game->window, game->hud->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->hud->gold->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->hud->waves->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->hud->life->sprite, NULL);
    sfRenderWindow_drawText(game->window, game->hud->gold->text, NULL);
    sfRenderWindow_drawText(game->window, game->hud->waves->text, NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->hud->life->hp, NULL);
    sfText_setString(game->hud->score->text, my_itoa(game->score));
    sfRenderWindow_drawText(game->window, game->hud->score->text, NULL);
    draw_map_slot(game);
}