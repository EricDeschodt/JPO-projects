/*
** EPITECH PROJECT, 2020
** tek1
** File description:
** my_printf functions
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

#ifndef PRINT_H
#define PRINT_H

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
void my_put_octal(char const *str);
int my_printf(char const *str, ...);

#endif /* PRINT_H */