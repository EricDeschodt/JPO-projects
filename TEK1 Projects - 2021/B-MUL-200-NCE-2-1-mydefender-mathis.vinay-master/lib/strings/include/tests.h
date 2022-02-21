/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** a set of functions to pass tests on strings
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TESTS_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TESTS_H

int my_strcmp(char const *, char const *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
unsigned long long my_strlen(char const *);
int my_strncmp(char const *, char const *, int);
bool my_str_is_equal(char const *s1, char const *s2);
int my_str_isint(char const *);
bool my_is_char_in_str(char c, const char *str);
bool my_is_char_in_strn(char c, const char *str, int limit);
int my_count(char c, char const *str);
int my_countn(char c, char const *str, int limit);
int my_index(char const *str, char c);
int my_indexn(char const *str, char c, int i);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TESTS_H
