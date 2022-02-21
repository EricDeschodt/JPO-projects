/*
** EPITECH PROJECT, 2021
** lib_include_makefile
** File description:
** functions concerning arrays
*/

#ifndef LIB_INCLUDE_MAKEFILE_TAB_H
#define LIB_INCLUDE_MAKEFILE_TAB_H

#include <stdbool.h>
#include "../../strings/include/strings.h"

void tab_print(char **array);
char **tab_create(char *str);
int get_greater_line(char **array);
int get_len_array(char **array);
int tab_free(char **tab);
void **my_tabcat(void **dest, void **src);
void **my_tab_extend(void **dest, void *src);
void **my_tab_rm_line(void **dest, int i);

#endif //LIB_INCLUDE_MAKEFILE_TAB_H
