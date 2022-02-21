/*
** EPITECH PROJECT, 2021
** lib_include_makefile
** File description:
** free the ressources
*/

#include <stdlib.h>

int tab_free(char **tab)
{
    if (!tab) return 0;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
    return 0;
}