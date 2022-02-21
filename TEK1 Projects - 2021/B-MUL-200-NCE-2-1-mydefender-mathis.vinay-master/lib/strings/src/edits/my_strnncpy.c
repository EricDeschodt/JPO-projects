/*
** EPITECH PROJECT, 2020
** my_strnncpy
** File description:
** copie les caractères de la chaineé à
** partir de l'index donné dans la chaine1
*/

int my_strlen(char *str);

char *my_strnncpy(char *dest, char const *src, int n)
{
    for (int i = 0; src[n]; i++, n++) {
        dest[i] = src[n];
    }
    return dest;
}
