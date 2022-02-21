/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** free a linked list
*/

#include "../include/linked_lists.h"

void list_free(t_node **list, char const *type)
{
    while (*list)
        list_pop(list, type);
}