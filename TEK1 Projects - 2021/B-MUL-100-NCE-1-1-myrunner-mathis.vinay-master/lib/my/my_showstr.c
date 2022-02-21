/*
** EPITECH PROJECT, 2020
** my_showstr
** File description:
** jsp
*/

void my_putchar(char c);

int my_put_nbr(int n);

int my_char_isprintable(char c);

void my_put_hex_char(unsigned char c)
{
    int n = c;
    if (n < 0)
        n = -n + 127;
    int div = 16;
    while (div != 0) {
            if (n / div < 10)
                my_putchar((n / div) + 48);
            else
                my_putchar((n / div) - 10 + 97);
            n = n % div;
        div = (div != 1) ? div / 16 : 0;
    }
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (my_char_isprintable(str[i]))
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            my_put_hex_char(str[i]);
        }
    }
}
