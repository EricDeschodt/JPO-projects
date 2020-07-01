/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** my_strdup
*/

#include "defender.h"
#include "utils.h"

char *my_strdup(char *str)
{
    int size = my_strlen(str);
    char *result = malloc(size + 1);
    for (int i = 0; i < size; i++)
        result[i] = str[i];
    result[size] = '\0';
    return (result);
}