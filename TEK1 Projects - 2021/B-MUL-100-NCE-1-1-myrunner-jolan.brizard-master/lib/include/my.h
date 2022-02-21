/*
** EPITECH PROJECT, 2020
** my dot ashe
** File description:
** all function from lib.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#ifndef MY
#define MY

typedef struct s_bag {
    int i;
    int res;
    int sign;
    int max;
    int nb;
    char *str;
} t_bag;

void my_putchar(char c);
void my_put_nbr(int nb);
int my_putstr(char const *str);

int my_isneg(int nb);
void my_swap(int *a, int *b);
int my_strlen(char const *str);

int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);

char *my_strcpy(char *dest, char const *str);
char *my_strncpy(char *dest, char const *str, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char const *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);

char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);

#endif /* MY */
