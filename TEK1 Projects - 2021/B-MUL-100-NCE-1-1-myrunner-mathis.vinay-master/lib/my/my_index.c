/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** fonction pour récupérer l'index d'un char
*/

int my_index(char const *str, char c)
{
    int i = 0;
    while (str[i] && str[i] != c)
        i++;
    if (str[i] == c)
        return i;
    return 0;
}

int my_indexn(char const *str, char c, int n)
{
    if (n < 1)
        return 0;
    int i = 0;
    for (; n > 0; n--, i++) {
        while (str[i] && str[i] != c)
            i++;
        if (!str[i])
            return 0;
    }
    i--;
    return i;
}