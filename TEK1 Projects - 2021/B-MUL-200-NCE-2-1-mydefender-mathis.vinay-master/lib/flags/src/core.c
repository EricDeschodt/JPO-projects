/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** core flags fncs handler
*/

#include "../include/flags.h"

bool is_flag(int argc, char **argv, char const *flag, char const *alias)
{
    for (int i = 0; i < argc; i++)
        if (my_strcmp(argv[i], flag) == 0 || my_strcmp(argv[i], alias) == 0)
            return true;
    return false;
}

char *flag_get_value(int argc, char **argv, char const *flag, char const *alias)
{
    int i = 0;
    for (; i < argc; i++)
        if (my_strcmp(argv[i], flag) == 0 || my_strcmp(argv[i], alias) == 0)
            break;
    if (i < argc - 1)
        return argv[++i];
    return NULL;
}