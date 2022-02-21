/*
** EPITECH PROJECT, 2020
** my_str_isint
** File description:
** check si la chaîne de caractère donnée est
** un int (uniquement opérateurs et
** nombre, dans le bon ordre) ou non
*/

int my_str_isnum(char const *str);

int is_there_int(char const *str);

int my_char_isnum(int n);

void my_putchar(char c);

int is_sign(char c)
{
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int my_str_isint(char const *str)
{
    int step_nb = 0;
    if (my_str_isnum(str))
        return 1;
    if (!is_there_int(str))
        return 0;
    for (int i = 0; str[i]; i++) {
        if (!step_nb && my_char_isnum(str[i]))
            step_nb = 1;
        if (!step_nb && !is_sign(str[i]))
            return 0;
        if (step_nb && !my_char_isnum(str[i]))
            return 0;
    }
    return 1;
}
