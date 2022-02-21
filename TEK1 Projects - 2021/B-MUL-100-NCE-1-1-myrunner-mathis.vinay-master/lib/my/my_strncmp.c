/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** comme le vré mais avec les n premiers caractères
*/

int my_strncmp_check(char const *s1, char const *s2, int n, int i)
{
    if (i < n) {
        if ((s1[i] == '\0') && (s2[i] == '\0'))
            return 0;
        if (s1[i] == '\0')
            return -1;
        if (s2[i] == '\0')
            return 1;
        if (s1[i] == s2[i])
            return my_strncmp_check(s1, s2, n, i + 1);
        else
            return s1[i] - s2[i];
    }
    else
        return 0;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    return my_strncmp_check(s1, s2, n, 0);
}
