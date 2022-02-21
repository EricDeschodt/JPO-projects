/*
** EPITECH PROJECT, 2020
** B-CPE-110-NCE-1-1-pushswap-mathis.vinay
** File description:
** linked list struct
*/

#ifndef B_CPE_110_NCE_1_1_PUSHSWAP_MATHIS_VINAY_LINKED_LISTS_H
#define B_CPE_110_NCE_1_1_PUSHSWAP_MATHIS_VINAY_LINKED_LISTS_H

#include <stdlib.h>
#include "../../print/include/print.h"

typedef struct s_node {
    void *element;
    struct s_node *next_element;
    struct s_node *prev_element;
} t_node;

t_node *list_print(t_node *list, char const *type);
t_node *list_pop(t_node **list, char const *type);
void list_append(t_node **list, void *new_data);
t_node *list_push(t_node **list, void *var);
void list_free(t_node **list, char const *type);
t_node *list_last_elem(t_node *list);

#endif //B_CPE_110_NCE_1_1_PUSHSWAP_MATHIS_VINAY_LINKED_LISTS_H
