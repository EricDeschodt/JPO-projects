/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** 01
*/

#include "../../include/include.h"

int	my_strcmp(char *str, char *str2)
{
    int i = 0;
    int result = 0;

    while (str[i] == str2[i] && str[i] != '\0'
    && str2[i] != '\0')
        i++;
    result = str[i] - str2[i];
    return (result);
}