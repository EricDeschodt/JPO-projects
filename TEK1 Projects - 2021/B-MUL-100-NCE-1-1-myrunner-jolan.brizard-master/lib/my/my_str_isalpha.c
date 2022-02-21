/*
** EPITECH PROJECT, 2020
** mystrisalpha
** File description:
** beta
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
            count++;
        i++;
    }
    if (count == i)
        return 1;
    return (0);
}