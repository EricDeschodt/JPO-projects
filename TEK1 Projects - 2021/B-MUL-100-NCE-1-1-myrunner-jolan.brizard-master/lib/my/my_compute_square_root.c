/*
** EPITECH PROJECT, 2020
** my compute square root
** File description:
** Faire la racine carré d'un nombre
*/

int my_compute_square_root(int nb)
{
    int i;

    if (nb < 0 || nb == 0)
        return (0);
    for (i = 0; i * i != nb; i++) {
        if (i * i > nb)
            return (0);
    }
    return (i);
}