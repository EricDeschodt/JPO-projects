/*
** EPITECH PROJECT, 2020
** my copy strn
** File description:
** stop when dest = \0
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int s = 0;

    while (src[i] != '\0')
        i++;
    while (s < n) {
        dest[s] = src[s];
        s++;
    }
    if (n > i)
        dest[s] = '\0';
    return (dest);
}