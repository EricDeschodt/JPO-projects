/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** ça concatène deux chaines tkt pas mon
** reuf je sais ce que je fait mdrr
*/

#include <stdlib.h>

unsigned long long my_strlen(char const *str);

char *my_strcat(char const *dest, char const *src)
{
    int a = 0;
    int s = 0;
    char *save = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    while (dest[s] != '\0') {
        save[s] = dest[s];
        s++;
    }

    while (src[a] != '\0') {
        save[s + a] = src[a];
        a++;
    }
    save[s + a] = '\0';
    return (save);
}
