/*
** EPITECH PROJECT, 2020
** utils
** File description:
** colli
*/

#include "../../include/include.h"

int is_solid(char c)
{
    if (c == 'A') return (1);
    if (c == 'T') return (1);
    if (c == 'R') return (1);
    if (c == 'r') return (1);
    if (c == 'o') return (1);
    if (c == 'L') return (1);
    if (c == 'a') return (1);
    if (c == 'z') return (1);
    if (c == 'e') return (1);
    if (c == 'q') return (1);
    if (c == 's') return (1);
    if (c == 'd') return (1);
    if (c == 'w') return (1);
    if (c == 'x') return (1);
    if (c == ')') return (1);
    if (c == '@') return (1);
    if (c == '!') return (1);
    return (0);
}

int is_collide_y_dec(players *player)
{
    pos *p = pos_player(player);
    p->x = p->x + 10;
    int y = p->y/96;
    int x = p->x/96;
    if (is_solid(player->map[y][x]) == 1)
        return (1);
    if (player->inv->key == false && check_in(player,
    convert_pos(6000, 2900), convert_pos(6450, 3000)) == 1)
        return (1);
    return (0);
}

int is_collide_x_dec(players *player)
{
    pos *p = pos_player(player);
    int y = p->y/96 + 1;
    int x = p->x/96;
    if (is_solid(player->map[y][x]) == 1)
        return (1);
    if ((player->inv->troph == false || player->state != 20) && check_in(player,
    convert_pos(4800, 4600), convert_pos(4896, 4800)) == 1)
        return (1);
    return (0);
}

int is_collide_y_inc(players *player)
{
    pos *p = pos_player(player);
    p->x = p->x - 10;
    int y = p->y/96 + 1;
    int x = p->x/96 + 1;
    if (is_solid(player->map[y][x]) == 1)
        return (1);
    if (player->inv->pick == false && check_in(player,
    convert_pos(7900, 3790), convert_pos(8100, 3800)) == 1)
        return (1);
    if (player->inv->map == false && check_in(player,
    convert_pos(4850, 3000), convert_pos(5000, 3050)) == 1)
        return (1);
    return (0);
}

int is_collide_x_inc(players *player)
{
    pos *p = pos_player(player);
    int y = p->y/96 + 1;
    int x = p->x/96 + 1;
    if (is_solid(player->map[y][x]) == 1)
        return (1);
    return (0);
}