/*
** EPITECH PROJECT, 2021
** lib_include_makefile
** File description:
** prints a tab
*/

void my_putchar(char c);

int my_putstr(char const *str);

void tab_print(char **array)
{
    if (!array)
        return;
    for (int r = 0; array[r]; r++) {
        my_putstr(array[r]);
        my_putchar('\n');
    }
}