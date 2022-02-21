/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCE-1-1-myls-mathis.vinay
** File description:
** my_put_nstrm : puts chars from str[n] to str[m]
*/

void my_putchar(char c);

int my_put_nstrm(char const *str, int n, int m)
{
    int i = 0;
    for (int j = 0; str[j]; j++)
        if (n <= j && j <= m) {
            my_putchar(str[j]);
            i++;
        }
    return i;
}