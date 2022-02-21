/*
** EPITECH PROJECT, 2020
** tek1
** File description:
** header for myprintf
*/
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef PRINT_H
#define PRINT_H

int my_compute_power_rec(int nb, int power);

void my_put_binary(int nb);

char *binary(int nb, char *str);

unsigned long long convert_octal(unsigned long long nb);

void my_put_ll_unsigned_nbr(unsigned long long nb);

void my_put_unsigned_nbr(unsigned nb);

void my_put_unsigned_octal(unsigned nb);

void my_put_hexa_cap(void *ptr);

void my_put_hexa_low(void *ptr);

char *convert_hex(void *ptr, char *str);

void my_show_ptr(void *ptr);

char *my_strupcase(char *str);

char *my_strcat(char const *dest, char const *src);

int my_strlen(char const *str);

char *my_revstr(char *str);

void my_putchar(char c);

void my_put_nbr(int nb);

int my_putstr(char const *str);

int my_strcmp(char const *s1, char const *s2);

void my_put_octal(char const *str);

int my_printf(const char *format, ...);

#endif /* PRINT_H */