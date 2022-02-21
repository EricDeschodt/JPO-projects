/*
** EPITECH PROJECT, 2020
** My Compute Factorial Rec
** File description:
** Recursive Function That Return Factorial of Number
*/

int my_compute_factorial_rec(int nb)
{
    int facto;

    if (nb == 0)
        return (1);
    if (nb < 0)
        return (0);
    facto = nb * my_compute_factorial_rec(nb - 1);
    return (facto);
}
