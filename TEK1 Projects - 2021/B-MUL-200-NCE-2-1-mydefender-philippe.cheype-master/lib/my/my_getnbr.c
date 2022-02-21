/*
** EPITECH PROJECT, 2020
** My Get Number
** File description:
** Gets any String and Outputs a Correct Integer
*/

int my_getnbr(char const *str)
{
    int number = 0;
    int sign = 1;
    int n = 0;

    for (; str[n] && (str[n] <= '0' || str[n] > '9'); n++)
        if (str[n] == '-')
            sign = -sign;
    if (!str[n]) return (0);
    for (int nbr = 0; str[n] && (str[n] <= '9' && str[n] >= '0'); n++, nbr++) {
        if (((number == 214748364 && str[n] - 48 > 7) || number > 214748364  \
                || nbr > 10) && (sign == 1 || (sign == -1 && str[n] - 48 > 8)))
            return (0);
        number = number * 10 + (str[n] - '0');
    }
    return (number * sign);
}
