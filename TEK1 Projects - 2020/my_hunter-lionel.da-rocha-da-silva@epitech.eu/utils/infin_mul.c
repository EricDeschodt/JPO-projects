/*
** EPITECH PROJECT, 2019
** infin_mul
** File description:
** infin_mul
*/

#include "my.h"

char *add_zero(char *str, int i, int len1, char *str2)
{
    int len2 = my_strlen(str2) - 1;
    int len = len1 + len2 + 3;
    char *zero = "0";
    char *new_res = malloc(sizeof(char) * len + 1);
    my_strcpy(new_res, str);
    while (i > 0) {
        my_strcat(new_res, zero);
        i--;
    }
    return (new_res);
}

char *mul_calc1(char *str1, char b, char *res)
{
    int i = my_strlen(str1) - 1;
    int k = 0;
    int carry = 0;

    while (i >= 0) {
        char a = str1[i--] - 48;
        int mul = (a * b) + carry;
        if (mul < 10)
            carry = 0;
        else if (mul > 9) {
            carry = mul / 10;
            mul = mul % 10;
        }
        res[k++] = mul + 48;
        res[k] = carry + 48;
    }
    res[k + 1] = '\0';
    my_revstr(res);
    return (res);
}

char *mul_calc(char *str1, char *str2)
{
    int len1 = my_strlen(str1) - 1;
    int j = my_strlen(str2) - 1;
    int t = 0;
    char *res = malloc(sizeof(char) * (len1 + j) + 2);
    char *result = malloc(sizeof(char) * (len1 + j) + 1);
    char *new_res = malloc(sizeof(char) * (len1 + j) + 1);
    char *save = malloc(sizeof(char) * (len1 + j) + 1);
    new_res = "0";

    while (j >= 0) {
        char b = str2[j--] - 48;
        res = mul_calc1(str1, b, res);
        save = add_zero(res, t++, len1, str2);
        result = inf_add(new_res, save);
        new_res = result;
    }
    while (new_res[0] == '0') {
        new_res++;
    }
    return (new_res);
}

char *inf_mul(char *str1, char *str2)
{
    int len1 = my_strlen(str1) - 1;
    int len2 = my_strlen(str2) - 1;
    char *new_res = malloc(sizeof(char) * (len1 + len2) + 1);
    char *zero = "0";

    if (str1[0] == '0' && str1[1] == '\0')
            return (zero);
    if (str2[0] == '0' && str2[1] == '\0')
            return (zero);
    if (str1[0] == '-' && str2[0] != '-')
        return (mult(str1, str2, new_res));
    if (str2[0] == '-' && str1[0] != '-')
        return (mult1(str1, str2, new_res));
    else
        return (mult2(str1, str2));
}
