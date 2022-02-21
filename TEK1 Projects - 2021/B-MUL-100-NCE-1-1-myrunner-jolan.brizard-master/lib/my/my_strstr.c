/*
** EPITECH PROJECT, 2020
** My strsrt
** File description:
** reproduce the behavior of the str function
*/

#include <string.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int u = 0;
    int c = 0;

    if (str[i] == '\0' && to_find[u] == '\0')
        return (str);
    while (str[i] != '\0') {
        c = i;
        u = 0;
        while (str[i] == to_find[u] && to_find[u] != '\0') {
            u++;
            i++;
        }
        if (to_find[u] == '\0')
            return (&str[c]);
        i = c + 1;
    }
    return (NULL);
}
