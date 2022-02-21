/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** swap the values of two integers
*/

void my_putchar(char c);

int my_put_nbr(int n);

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
