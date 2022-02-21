/*
** EPITECH PROJECT, 2020
** lower
** File description:
** harderbetterfasterstronger
*/

int my_str_islower(char const *str)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122)
            count++;
        i++;
    }
    if (count == i)
        return 1;
    return (0);
}