/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** my_str_to_word_array
*/
#include "../../include/my.h"

bool is_separator(char c)
{
    if (c == '\n')
        return true;
    else
        return false;
}

int get_word_number(char const *str)
{
    int res = 0;
    bool is_checking = false;
    for (int i = 0; str[i]; i++) {
        if (is_separator(str[i]) == false && !is_checking) {
            res += 1;
            is_checking = true;
        }
        else if (is_checking && is_separator(str[i]) == true) {
            is_checking = false;
        }
    }
    return (res);
}

int get_wordlen(char const *str, int i)
{
    int len = 0;
    while (str[i]) {
        while (is_separator(str[i]) == false) {
            len++;
            i += 1;
        }
        if (is_separator(str[i]) == true && len != 0)
            return (len);
        i += 1;
    }
    return (len);
}

char *fill_tab(char const *str, int *pos)
{
    int wordlen = get_wordlen(str, *pos);
    char *result = malloc(sizeof(char) * wordlen + 1);
    int i = 0;
    while (str[*pos]) {
        while (is_separator(str[*pos]) == false) {
            result[i] = str[*pos];
            i++;
            *pos += 1;
        }
        if (i != 0) {
            break;
        }
        *pos += 1;
    }
    result[i] = '\0';
    return (result);
}

char **my_str_to_word_array(char const *str)
{
    int nb_word = get_word_number(str);
    char **tab = malloc(sizeof(char *) * (nb_word + 1));
    int pos = 0;
    for (int j = 0; j != nb_word; j++) {
        tab[j] = fill_tab(str, &pos);
    }
    tab[nb_word] = NULL;
    return (tab);
}
