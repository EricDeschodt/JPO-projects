/*
** EPITECH PROJECT, 2020
** My Str Cmp
** File description:
** Compares two Strings and Returns According Int
*/

int my_strcmp(char const *s1 , char const *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i] && s1[i] && s2[i]; i++);
    return (s1[i] - s2[i]);
}
