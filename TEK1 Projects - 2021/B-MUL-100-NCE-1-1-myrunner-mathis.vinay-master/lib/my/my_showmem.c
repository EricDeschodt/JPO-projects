/*
** EPITECH PROJECT, 2020
** my_showstr
** File description:
** jsp
*/

void my_putchar(char c);

void my_put_hex_char(unsigned char c);

int my_put_nbr(int n);

int my_char_isprintable(char c);

void my_put_hex_ligne(int n)
{
    int div = 0x10000000;
    while (div != 0) {
            if (n / div < 10)
                my_putchar((char)((n / div) + 48));
            else
                my_putchar((char)((n / div) - 10 + 97));
            n = n % div;
        div = (div != 1) ? div / 16 : 0;
    }
    my_putchar(':');
}

void my_put_hex_values(char const *str, int limit)
{
    for (int i = 0; i < limit && i < 16; i++) {
        if (i % 2 == 0)
            my_putchar(' ');
        my_put_hex_char(str[i]);
    }
}

void my_put_required_blanks(int limit)
{
    for (int i = 0; i < (16 - limit) * 2 + ((16 - limit) / 2); i++)
        my_putchar(' ');
}

void my_put_char_values(char const *str, int limit)
{
    my_putchar(' ');
    for (int i = 0; i < limit && i < 16; i++) {
        if (my_char_isprintable(str[i]))
            my_putchar(str[i]);
        else
            my_putchar('.');
    }
}

int my_showmem(char const *str, int size)
{
    for (int i = 0; i < size; i += 16) {
        my_put_hex_ligne(i);
        my_put_hex_values(str + i, size - i);
        my_put_required_blanks(size - i);
        my_put_char_values(str + i, size - i);
        my_putchar('\n');
    }
}
