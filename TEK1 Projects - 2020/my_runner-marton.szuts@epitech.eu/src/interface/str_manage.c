/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** str_manage
*/

#include "runner.h"

void free_previous_txt(char *str)
{
    if (str != NULL)
        free(str);
}