/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** get_random_pos
*/

#include <stdlib.h>
#include "defender.h"

sfVector2f get_random_pos(int min, int max)
{
    sfVector2f pos;

    pos.x = 1789;
    pos.y = rand() % (max + 1 - min) + min;
    return (pos);
}
