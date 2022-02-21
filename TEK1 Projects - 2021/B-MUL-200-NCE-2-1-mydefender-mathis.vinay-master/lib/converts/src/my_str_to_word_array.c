/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** converti une chaine de carac en liste
*/

#include <stdlib.h>
#include <stdbool.h>

bool is_char_alphanum2(char c)
{
    if (c != ' ')
        return true;
    else
        return false;
}

char const *get_string_after2(char const *str)
{
    int i = 0;

    for (; !(is_char_alphanum2(str[i])); i++) {
        if (str[i + 1] == '\0')
            return NULL;
    }
    str = &str[i];
    return str;
}

int get_nb_separators2(char const *str)
{
    int count = 1;
    int i = 0;

    for (; str[i]; i++) {
        if (!(is_char_alphanum2(str[0])) && get_string_after2(&str[i]) !=
        NULL) {
            str = get_string_after2(&str[i]);
            i = 0;
        }
        if (!(is_char_alphanum2(str[i])) && get_string_after2(&str[i]) !=
        NULL) {
            count++;
            str = get_string_after2(&str[i]);
            i = 0;
        }
    }
    return count;
}

int get_size_first_sep2(char const *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (!(is_char_alphanum2(str[i])))
            break;
    }
    return i;
}

char **my_str_to_word_array(char *str)
{
    int nb_row_max = get_nb_separators2(str);
    char **array = malloc(sizeof(char *) * (nb_row_max + 1));
    int row = 0;
    int col = 0;
    int size_cols = 0;
    str = get_string_after2(str);

    for (; row < nb_row_max; row++) {
        size_cols = get_size_first_sep2(str);
        array[row] = malloc(sizeof(char) * size_cols + 1);
        for (col = 0; col < size_cols; col++) {
            array[row][col] = str[col];
        }
        array[row][col] = '\0';
        str = get_string_after2(&str[size_cols]);
    }
    array[row] = NULL;
    return array;
}