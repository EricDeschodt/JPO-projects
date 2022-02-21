/*
** EPITECH PROJECT, 2020
** B-CPE-110-NCE-1-1-BSQ-mathis.vinay
** File description:
** a function for getting the number of occurences of a char in a str
*/

int my_count(char c, char const *str)
{
    int n = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            n++;
    return n;
}

int my_countn(char c, char const *str, int limit)
{
    int n = 0;
    for (int i = 0; str[i] && i < limit; i++)
        if (str[i] == c)
            n++;
    return n;
}