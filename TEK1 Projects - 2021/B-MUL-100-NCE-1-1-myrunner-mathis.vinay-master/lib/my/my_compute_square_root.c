/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** returns the square root
*/

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb < 1)
        return 0;
    while (i * i < nb)
        i++;
    if (i * i == nb)
        return i;
    else
        return 0;
}
