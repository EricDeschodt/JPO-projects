/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** retourne le premier nombre premier égal ou sup au nombre donné
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    while (1 == 1) {
        if (my_is_prime(nb) == 1)
            return nb;
        else
            nb++;
    }
}
