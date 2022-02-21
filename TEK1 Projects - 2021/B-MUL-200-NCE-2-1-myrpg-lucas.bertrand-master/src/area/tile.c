/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** tile
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int boundaries_up(object_t *protagonist, int *move)
{
    if (protagonist->pos.y < 300) {
        move[1] += 15;
        return (1);
    }
    return (0);
}

int boundaries_right(object_t *protagonist, int *move)
{
    if (protagonist->pos.x > 1250) {
        move[0] -= 16;
        return (1);
    }
    return (0);
}

int boundaries_left(object_t *protagonist, int *move)
{
    if (protagonist->pos.x < 500) {
        move[0] += 15;
        return (1);
    }
    return (0);
}

int boundaries_down(object_t *protagonist, int *move)
{
    if (protagonist->pos.y > 500) {
        move[1] -= 16;
        return (1);
    }
    return (0);
}
