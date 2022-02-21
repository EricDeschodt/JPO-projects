/*
** EPITECH PROJECT, 2020
** my_computer_power_rec
** File description:
** en gros ça fait une puissance mais récursivement
*/

int my_compute_power_rec(int nb, int p)
{
    if (nb < 1 || p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p > 1) {
        if (my_compute_power_rec(nb, p - 1) * nb < nb)
            return my_compute_power_rec(nb, p - 1) * nb;
        else
            return 0;
    }
    else
        return nb;
}
