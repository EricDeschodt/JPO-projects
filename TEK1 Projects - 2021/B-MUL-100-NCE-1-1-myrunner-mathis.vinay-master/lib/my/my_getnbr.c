/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** retourne un str en int
*/

int my_put_nbr(int n);

void my_putchar(char c);

int my_strlen(char const *str);

int is_num(char const c)
{
    if (48 <= c && c <= 57)
        return 1;
    return 0;
}

int is_there_int(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (is_num(str[i]))
            return 1;
    return 0;
}

int is_really_null(char *str)
{
    int find_state = 0;
    int closed_state = 0;
    if (!is_there_int(str))
        return 0;
    for (int i = 0; str[i]; i++) {
        if (is_num(str[i])) {
            if (str[i] != '0')
                return 0;
            find_state = 1;
        } else if (find_state)
            return 1;
    }
    return 1;
}

int my_getnbr(char const *str)
{
    int state_sign = 1;
    int state_nb = 1;
    int sign = 1;
    int nb = 0;
    if (!is_there_int(str))
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (state_sign && str[i] == '-')
            sign = -sign;
        else if (state_nb && is_num(str[i])) {
            state_sign = 0;
            if (nb > (nb * 10) + (str[i] - 48))
                return 0;
            nb = (nb * 10) + (str[i] - 48);
        } else if (!state_sign && !is_num(str[i]))
            state_nb = 0;
    }
    nb *= sign;
    return nb;
}
