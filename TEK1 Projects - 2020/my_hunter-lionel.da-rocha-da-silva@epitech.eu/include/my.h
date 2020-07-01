/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** mylib header
*/

#ifndef _MY_
#define _MY_

#include "mylist.h"
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_swap(int *a, int *b);
void swap_if_needed(int *nb1, int *nb2);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int power);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int nb);
char *my_revstr(char *str);
char *my_strstr(char const *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int nb);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_putnbr_base(int nbr, char const *base);
int get_value(char *str, int index);
char *add(char *str1, char *str2);
char *sub(char *str1, char *str2);
int comp(char *str1, char *str2);
int my_atoi(char *str);
l_list *my_list_add(void *data, l_list *node);
void *my_list_pop(l_list **node);
int my_list_size(l_list *begin);
char my_strchar(char *str, char c);
char *parse_exp(char **expr);
char *parse_sum(char **expr);
char *parse_product(char **expr);
char *parse_number(char **expr);
char *eval_expr(char *base, char *operators, char *str);
int is_num(char token, char *base);
int is_operator(char token, char *operators);
int is_parenthesis(char token);
int valid_expr(char *base, char *operators, char *str);
int is_op(char token);
char *parse_token();
l_list *my_rev_list(l_list *node);
char *turn(char c);
l_list *tokenize();
char *secnd_neg(char *str1, char *str2, int len1, int len2);
char *first_neg(char *str1, char *str2, int len1, int len2);
char *add_calc(char *str1, char *str2, int carry, int len);
char *sub_calc(char *str1, char *str2, int carry, int len);
char *inf_add(char *str1, char *str2);
char *inf_sub(char *str1, char *str2);
char *mul(char *str1, char *str2);
int check_negation(char **expr);
char *parse_number1(char **expr);
char *both_neg(char *str1, char *str2, int len1, int len2);
char *both_neg1(char *str1, char *str2, int len1, int len2);
char *both_pos(char *str1, char *str2, int len1, int len2);
char *both_pos1(char *str1, char *str2, int len1, int len2);
char *mult(char *str1, char *str2, char *new_res);
char *mult1(char *str1, char *str2, char *new_res);
char *mult2(char *str1, char *str2);
int my_atoi(char *str);
char *inf_mul(char *str1, char *str2);
char *mul_calc(char *str1, char *str2);
int same_ops(char *str);
int ops_in_base(char *base, char *operators);

#endif
