/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** my_strlen
*/

#include "defender.h"
#include "utils.h"

int my_strlen_n(char *str)
{
    int i = 0;
    if (str == NULL)
        return (0);
    for (; str[i] != '\n'; i++);
    return (i);
}

int my_strlen(char *str)
{
    int i = 0;
    if (str == NULL)
        return (0);
    for (; str[i] != '\0'; i++);
    return (i);
}

int linked_len(all_t *s_all, int id)
{
    int i = 0;
    tuto_t *temp;
    if (id == 1) temp = s_all->s_wave_c.round;
    if (id == 2) temp = s_all->s_wave_c.square;
    if (id == 3) temp = s_all->s_wave_c.triangle;
    if (id == 0) temp = s_all->s_tuto;
    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    return (i);
}

char **rev_ptr(char **str)
{
    char *temp;
    int len = my_ptr_len(str) - 1;
    for (int i = 0; i < len; i++, len--) {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
    }
    return (str);
}