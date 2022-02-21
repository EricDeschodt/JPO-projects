/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

void my_putchar(char);
int my_strlen(const char *);
int my_putstr(const char *);
int my_putnbr(const int);
char *my_revstr(char *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1 , char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);

int my_put_tbl(const char **);
char *my_get_str(int nb);

int my_lprintf(char const *expr, ...);

#endif /* MY_H_ */
