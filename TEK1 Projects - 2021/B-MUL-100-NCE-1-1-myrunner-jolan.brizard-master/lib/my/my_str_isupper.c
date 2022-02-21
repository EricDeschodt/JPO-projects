/*
** EPITECH PROJECT, 2020
** upper
** File description:
** up
*/

int my_str_isupper(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            count++;
        i++;
    }
    if (count == i)
        return 1;
    return (0);
}