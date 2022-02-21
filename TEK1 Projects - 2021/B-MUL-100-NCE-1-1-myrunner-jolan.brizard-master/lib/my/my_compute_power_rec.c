/*
** EPITECH PROJECT, 2020
** my compute power recursive
** File description:
** lol
*/

int my_compute_power_rec(int nb, int p)
{
    int save = nb;
    int i = 1;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    return (my_compute_power_rec(nb, p - 1) * nb);
}