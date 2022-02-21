/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** concatène deux chaînes à partir de n jcrois
*/

unsigned long long my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    unsigned long long len = my_strlen(dest);
    int i = 0;

    for (i = 0; nb > i && src[i] != '\0'; i++) {
        dest[i + len] = src[i];
    }
    dest[i + len] = '\0';
    return dest;
}
