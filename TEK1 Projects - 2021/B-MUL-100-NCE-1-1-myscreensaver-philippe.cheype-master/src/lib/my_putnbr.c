/*
** EPITECH PROJECT, 2020
** My Put Nbr
** File description:
** Puts Numbers
*/

void my_putchar(char const c);

int my_putstr(char const *str);

int my_putnbr(int nb)
{
    long long_nb = nb;
    int n = 0;

    if (long_nb < -2147483648)
        long_nb = 2147483647 - long_nb;
    if (long_nb > 2147483647)
        long_nb = -2147483648 + long_nb;
    if (long_nb < 0) {
        my_putchar('-');
        long_nb = -long_nb;
    }
    if (long_nb > 9)
        my_putnbr(long_nb / 10);
    n = long_nb % 10;
    my_putchar(n + '0');
    return (0);
}
