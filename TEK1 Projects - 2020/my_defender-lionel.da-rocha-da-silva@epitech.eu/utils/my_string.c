/*
** EPITECH PROJECT, 2020
** my_string
** File description:
** my_string
*/

#include "my_string.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void my_strcpy(char *s1, char *s2)
{
    int i = 0;
    for (; s2[i] != 0; i++) {
        s1[i] = s2[i];
    }
    s1[i] = '\0';
}

void my_strcat(char *s1, char *s2)
{
    int i = 0, len = my_strlen(s1);
    for (; s2[i] != '\0'; i++) {
        s1[len + i] = s2[i];
    }
    s1[len + i] = '\0';
}

void swap(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

void reverse(char *str)
{
    int start = 0;
    char c;
    int end = my_strlen(str) -1;
    while (start < end) {
        c = *(str + start);
        *(str +start) = *(str + end);
        *(str + end) = c;
        start++;
        end--;
    }
}

char *my_itoa(int n)
{
    int i = 0, rem = 0;
    char *str = malloc(sizeof(char) * 100);
    bool isNegative = false;
    if (n == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (n < 0) {
        isNegative = true;
        n = -n;
    }
    while (n != 0) {
        rem = n % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        n = n / 10;
    } if (isNegative)
        str[i++] = '-';
    str[i] = '\0', reverse(str);
    return str;
}