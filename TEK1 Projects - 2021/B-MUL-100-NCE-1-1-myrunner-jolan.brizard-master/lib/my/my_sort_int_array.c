/*
** EPITECH PROJECT, 2020
** sort in array
** File description:
** pupute
*/

#include "../include/my.h"

int my_putintstar(int *array, int size)
{
    for (int i = 0; i < size; i++)
        my_put_nbr(array[i]);
    return (0);
}

void my_sort_int_array(int *tab, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (tab[j + 1] <= tab[j]) {
                int tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
    my_putintstar(tab, size);
}