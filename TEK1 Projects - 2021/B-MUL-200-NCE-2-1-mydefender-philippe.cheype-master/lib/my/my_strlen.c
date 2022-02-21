/*
** EPITECH PROJECT, 2020
** My String Length
** File description:
** Counts String Length
*/

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
