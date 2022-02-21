/*
** EPITECH PROJECT, 2021
** bootstrap minishell
** File description:
** splits str into array, separator can be indicated by passing as parameter.
*/

#include <stdbool.h>
#include <stdlib.h>
#include "../include/tabs.h"

bool is_char_alphanum(char c)
{
    if (c != '\n')
        return true;
    else
        return false;
}

char const *get_string_after(char const *str)
{
    int i = 0;

    for (; !(is_char_alphanum(str[i])); i++) {
        if (str[i + 1] == '\0')
            return NULL;
    }
    str = &str[i];
    return str;
}

int get_nb_separators(char const *str)
{
    int count = 1;
    int i = 0;

    for (; str[i]; i++) {
        if (!(is_char_alphanum(str[0])) && get_string_after(&str[i]) != NULL) {
            str = get_string_after(&str[i]);
            i = 0;
        }
        if (!(is_char_alphanum(str[i])) && get_string_after(&str[i]) != NULL) {
            count++;
            str = get_string_after(&str[i]);
            i = 0;
        }
    }
    return count;
}

int get_size_first_sep(char const *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (!(is_char_alphanum(str[i])))
            break;
    }
    return i;
}

char **tab_create(char *str)
{
    int nb_row_max = get_nb_separators(str);
    char **array = malloc(sizeof(char *) * (nb_row_max + 1));
    int row = 0;
    int col = 0;
    int size_cols = 0;
    str = get_string_after(str);

    for (; row < nb_row_max; row++) {
        size_cols = get_size_first_sep(str);
        array[row] = malloc(sizeof(char) * size_cols + 1);
        for (col = 0; col < size_cols; col++) {
            array[row][col] = str[col];
        }
        array[row][col] = '\0';
        str = get_string_after(&str[size_cols]);
    }
    array[row] = NULL;
    return array;
}