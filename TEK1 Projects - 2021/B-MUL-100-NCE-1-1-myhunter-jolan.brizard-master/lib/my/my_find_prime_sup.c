/*
** EPITECH PROJECT, 2020
** my is prime sup
** File description:
** ouais
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (nb < 2)
        return (0);

    while (my_is_prime(nb) != 1)
        nb += 1;
    return (nb);
}