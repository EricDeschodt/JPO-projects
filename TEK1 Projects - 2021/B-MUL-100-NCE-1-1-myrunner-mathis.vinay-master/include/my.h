/*
** EPITECH PROJECT, 2020
** my
** File description:
** header for my lib
*/

#ifndef MY_
#define MY_

#include <stdbool.h>
#include <stdlib.h>

int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_find_prime_sup(int);
int my_getnbr(char const *);
int my_isneg(int);
int my_is_prime(int);
void my_putchar(char);
int my_putstr(char const *);
int my_put_nbr(int);
char *my_revstr(char *);
int my_showmem(char const *, int);
int my_showstr(char const *);
void my_sort_int_array(int *, int);
char *my_strcapitalize(char *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
unsigned long long my_strlen(char const *);
int is_upper_letter(char);
char lower_this(char);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
char *my_strncpy(char *, char *, int);
char *my_strstr(char *, char const *);
int is_lower_letter(char);
char upper_this(char);
char *my_strupcase(char *);
void my_swap(int *, int *);
int is_really_null(char *);
int is_there_int(char const *);
int my_char_isnum(char);
int is_sign(char);
int my_str_isint(char const *);
char *my_strdup(char const *);
bool my_is_char_in_str(char c, const char *str);
bool my_is_char_in_strn(char c, const char *str, int limit);
int my_get_nb_char_in_str(char c, char const *str);
int my_get_nb_char_in_strn(char c, char const *str, int limit);
void my_put_bool(bool b);
int my_put_nstrm(char const *str, int n, int m);
int my_printf(char const *str, ...);
bool my_is_file_valid(char const *adress);
char *my_get_file_ctn(char const *file_adress);
int my_index(char const *str, char c);
int my_indexn(char const *str, char c, int i);

#endif
