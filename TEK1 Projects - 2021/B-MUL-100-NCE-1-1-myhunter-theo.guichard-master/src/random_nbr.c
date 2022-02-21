/*
** EPITECH PROJECT, 2020
** Project Name
** File description:
** return a nbr between 0 and limit given in param.
*/

#include "../include/myhunter.h"

float random_coords(int limit)
{
    srand(time(NULL));
    return (rand() % limit);
}