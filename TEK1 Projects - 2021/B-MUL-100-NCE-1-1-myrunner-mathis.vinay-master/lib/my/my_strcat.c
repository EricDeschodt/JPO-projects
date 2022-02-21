/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** ça concatène deux chaines tkt pas mon
** reuf je sais ce que je fait mdrr
*/

unsigned long long my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    unsigned long long len = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i + len] = src[i];
    }
    dest[i + len] = '\0';
    return dest;

}
