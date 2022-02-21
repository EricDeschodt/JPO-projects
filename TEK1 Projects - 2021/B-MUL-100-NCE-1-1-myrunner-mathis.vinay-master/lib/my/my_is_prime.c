/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** vérifie si le nombre est premier
*/

int my_is_prime(int nb)
{
    int i;
    int is_prime = 1;

    if (nb < 2)
        return 0;
    for (i = 2 ; i < nb ; i++) {
        if ((nb / i) * i == nb)
            is_prime = 0;
    }
    return is_prime;
}
