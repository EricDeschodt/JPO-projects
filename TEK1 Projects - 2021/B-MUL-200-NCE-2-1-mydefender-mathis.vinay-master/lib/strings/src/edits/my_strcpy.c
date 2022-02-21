/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** une fonction qui copie une chaine de caractère
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
