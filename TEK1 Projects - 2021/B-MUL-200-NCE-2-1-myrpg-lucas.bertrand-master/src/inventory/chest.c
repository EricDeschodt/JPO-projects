/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** chest
*/
#include "../../include/my.h"
#include "../../include/struct.h"

char **chest_down(object_t *chara, int *move,
                  scene_t *area, char **map)
{
    int x = (chara->pos.x - move[0] + 44) / 192;
    int y = ((chara->pos.y - move[1] + 35) / 108) + 2;

    if (map[y][x] == ':' && check_inventory(area) == 0) {
        map[y][x]++;
        time_restart(area[21].times);
        sfSound_play(area[11].sounds->sound);
        get_item(area, map, x, y);
    }
    return (map);
}

char **chest_right(object_t *chara, int *move,
                   scene_t *area, char **map)
{
    int x = (chara->pos.x - move[0] + 75) / 192;
    int y = ((chara->pos.y - move[1] + 20) / 108) + 2;

    if (map[y][x] == '>' && check_inventory(area) == 0) {
        map[y][x]++;
        time_restart(area[21].times);
        sfSound_play(area[11].sounds->sound);
        get_item(area, map, x, y);
    }
    return (map);
}

char **chest_left(object_t *chara, int *move,
                  scene_t *area, char **map)
{
    int x = (chara->pos.x - move[0]) / 192;
    int y = ((chara->pos.y - move[1] + 20) / 108) + 2;

    if (map[y][x] == '<' && check_inventory(area) == 0) {
        map[y][x]++;
        time_restart(area[21].times);
        sfSound_play(area[11].sounds->sound);
        get_item(area, map, x, y);
    }
    return (map);
}

char **chest_up(object_t *chara, int *move,
                scene_t *area, char **map)
{
    int x = (chara->pos.x - move[0] + 25) / 192;
    int y = ((chara->pos.y - move[1] - 10)  / 108) + 2;

    if (map[y][x] == '8' && check_inventory(area) == 0) {
        map[y][x]++;
        time_restart(area[21].times);
        sfSound_play(area[11].sounds->sound);
        get_item(area, map, x, y);
    }
    return (map);
}

char **chest(object_t *chara, int *move,
             scene_t *area, char **map)
{
    int top = area[1].objs->rect.top;
    int left = area[1].objs->rect.left;

    if (top == 0)
        if (left >= 0 && left <= 520)
            return (chest_down(chara, move, area, map));
        else
            return (chest_right(chara, move, area, map));
    else
        if (left >= 0 && left <= 585)
            return (chest_left(chara, move, area, map));
        else
            return (chest_up(chara, move, area, map));
}
