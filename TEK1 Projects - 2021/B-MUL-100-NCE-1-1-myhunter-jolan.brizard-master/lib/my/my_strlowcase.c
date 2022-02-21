/*
** EPITECH PROJECT, 2020
** strlowcase
** File description:
** low case
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
        i++;
    }
    str[i] = '\0';
    return (str);
}