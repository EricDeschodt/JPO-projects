/*
** EPITECH PROJECT, 2020
** mystrisnum
** File description:
** ero
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57)
            count++;
        i++;
    }
    if (count == i)
        return 1;
    return (0);
}