/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** sort the int in an array
*/

#include <stdlib.h>

int my_put_nbr(int n);

void my_putchar(char c);

int my_getnbr(char *str);

void my_sort_int_array(int *tab, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (tab[j + 1] >= tab[j]) {
                int tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}