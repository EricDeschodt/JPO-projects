/*
** EPITECH PROJECT, 2020
** printable
** File description:
** print
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] <= 127)
            count++;
        i++;
    }
    if (count == i)
        return 1;
    return 0;
}