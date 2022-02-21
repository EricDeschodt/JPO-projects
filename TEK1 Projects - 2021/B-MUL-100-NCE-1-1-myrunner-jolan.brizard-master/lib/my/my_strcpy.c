/*
** EPITECH PROJECT, 2020
** my str copy
** File description:
** copie d'un str d'une source a une destination
*/

char *my_strcpy(char *dest, char const *src)
{
    int s = 0;

    while (src[s] != '\0') {
        dest[s] = src[s];
        s++;
    }
    dest[s] = '\0';
    return (dest);
}