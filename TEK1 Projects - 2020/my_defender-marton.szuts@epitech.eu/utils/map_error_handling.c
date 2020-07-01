/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** map_error_handling
*/

#include "defender.h"

int map_error_handling(char **saved, all_t *s_all)
{
    int castle = 0, spawner = 0;
    for (int i = 0; saved[i] != NULL; i++) {
        for (int j = 0; saved[i][j] != '\0'; j++) {
            castle += saved[i][j] == 'C' ? 1 : 0;
            spawner += saved[i][j] == 'S' ? 1 : 0;
        }
    }
    if (castle != 1 || spawner != 1) {
        s_all->s_map_edit.error = 1;
        return (0);
    }
    s_all->s_map_edit.error = 0;
    return (1);
}