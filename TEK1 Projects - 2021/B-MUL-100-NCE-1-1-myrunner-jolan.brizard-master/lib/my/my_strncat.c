/*
** EPITECH PROJECT, 2020
** strn cat
** File description:
** nian cat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int a = 0;
    int s = 0;

    while (dest[s] != '\0')
        s++;
    while (src[a] != '\0' && a < nb) {
        dest[s + a] = src[a];
        a++;
        dest[s + a] = '\0';
    }
    return (dest);
}