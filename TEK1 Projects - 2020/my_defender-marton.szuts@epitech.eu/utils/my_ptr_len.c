/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** my_ptdr_len
*/

#include "utils.h"

void free_double_array(char **str)
{
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
}

int my_ptr_len(char **str)
{
    int counter = 0;
    for (int i = 0; str[i] != NULL; i++)
        counter++;
    return (counter);
}