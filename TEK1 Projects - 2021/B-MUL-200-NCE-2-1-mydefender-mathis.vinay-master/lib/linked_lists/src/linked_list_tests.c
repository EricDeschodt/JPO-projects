/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** tests on linked lists
*/

#include "../include/linked_lists.h"

t_node *list_last_elem(t_node *node)
{
    t_node *expression = node;
    while (expression->next_element) {
        expression = expression->next_element;
    }
    return expression;
}