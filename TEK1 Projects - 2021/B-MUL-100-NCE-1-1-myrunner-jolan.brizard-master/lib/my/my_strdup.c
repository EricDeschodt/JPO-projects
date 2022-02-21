/*
** EPITECH PROJECT, 2020
** my strdupp
** File description:
** malloc et free, il faut mesurer la taille de mon argument
*/

#include <string.h>

char *my_strdup(char const *src, char *string)
{
    int len = 0;
    int i = 0;

    if (src == NULL)
        return (NULL);

    while (i < len) {
        string[i] = src[i];
        i++;
    }
    string[i] = '\0';
    return (string);
}