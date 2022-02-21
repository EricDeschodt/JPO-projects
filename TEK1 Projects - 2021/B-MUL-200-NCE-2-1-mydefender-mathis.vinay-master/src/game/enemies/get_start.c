/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Handles the map
*/

#include "../../../include/game/main_game.h"
#include "stdlib.h"

int *get_start_pos(char **map)
{
    int *pos = malloc(sizeof(int) * 2 + 1);
    pos[0] = 0;
    pos[1] = 0;

    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] == 'Q' || map[i][j] == 'R') {
                pos[0] = i;
                pos[1] = j;
                return pos;
            }
        }
    }
    return pos;
}