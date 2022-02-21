/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** a function that return the len of a string
*/

unsigned long long my_strlen(char const *str)
{
    unsigned long long i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
