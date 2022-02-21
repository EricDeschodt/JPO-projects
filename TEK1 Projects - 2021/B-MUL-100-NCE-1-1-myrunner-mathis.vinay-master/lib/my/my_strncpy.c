/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** en gros ça copie les n premier carac d'une chaine à l'autre
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;
    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    return dest;
}
