/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** bordure
*/
#include "../../include/struct.h"
#include "../../include/my.h"

void move_update(protagonist_t *player, sfVector2f pos)
{
    player->pos_x = pos.x;
    player->pos_y = pos.y;
}

int bordure_up(object_t *chara, int *move, char **map)
{
    int x = (chara->pos.x - move[0] + 35) / 192;
    int y = ((chara->pos.y - move[1] - 10)  / 108) + 2;

    if (map[y][x] >= '8' && map[y][x] <= '@'
        || map[y][x] >= 'B' && map[y][x] <= 'D'
        || map[y][x] == ' ' || map[0][0] != 'f'
        && map[y][x] == 'A')
        return (1);
    else if (map[y][x] == '7')
        return (2);
    return (0);
}

int bordure_right(object_t *chara, int *move, char **map)
{
    int x = (chara->pos.x - move[0] + 75) / 192;
    int y = ((chara->pos.y - move[1] + 20) / 108) + 2;

    if (map[y][x] >= '8' && map[y][x] <= '@'
        || map[y][x] >= 'B' && map[y][x] <= 'D'
        || map[y][x] == ' ' || map[0][0] != 'f'
        && map[y][x] == 'A')
        return (1);
    return (0);
}

int bordure_down(object_t *chara, int *move, char **map)
{
    int x = (chara->pos.x - move[0] + 44) / 192;
    int y = ((chara->pos.y - move[1] + 35) / 108) + 2;

    if (map[y][x] >= '8' && map[y][x] <= '@'
        || map[y][x] >= 'B' && map[y][x] <= 'D'
        || map[y][x] == ' ' || map[0][0] != 'f'
        && map[y][x] == 'A')
        return (1);
    return (0);
}

int bordure_left(object_t *chara, int *move, char **map)
{
    int x = (chara->pos.x - move[0]) / 192;
    int y = ((chara->pos.y - move[1] + 20) / 108) + 2;

    if (map[y][x] >= '8' && map[y][x] <= '@'
        || map[y][x] >= 'B' && map[y][x] <= 'D'
        || map[y][x] == ' ' || map[0][0] != 'f'
        && map[y][x] == 'A')
        return (1);
    return (0);
}
