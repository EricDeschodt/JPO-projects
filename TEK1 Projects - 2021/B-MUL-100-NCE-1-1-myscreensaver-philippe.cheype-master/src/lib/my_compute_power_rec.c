/*
** EPITECH PROJECT, 2020
** My Compute Power Rec
** File description:
** Raises a Given Variable to a Given Power
*/

double my_compute_power_rec(double nb, int p)
{
    int pow = 1;

    if (p < 0)
        return (0);
    if (p < 1)
        return (pow);
    pow = nb * my_compute_power_rec(nb, p - 1);
    return (pow);
}
