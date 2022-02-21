/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** center_pos
*/

#include "defender.h"

sfVector2f center_pos(sfVector2f pos)
{
    for (float i = 634.0; i <= 1789.0; i += 64.0)
        if (pos.x >= i && pos.x < i + 64.0) pos.x = i;
    for (float j = 373.0; j <= 821.0; j += 64.0)
        if (pos.y >= j && pos.y < j + 64.0) pos.y = j;
    return (pos);
}
