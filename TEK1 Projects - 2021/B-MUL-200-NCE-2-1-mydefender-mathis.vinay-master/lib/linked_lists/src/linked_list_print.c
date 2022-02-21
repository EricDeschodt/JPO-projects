/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** a function for prints a linked list
*/

#include "../include/linked_lists.h"
#include "../../../include/game/init_enemies.h"

//types :
//  pointeur
//  int

t_node *list_print(t_node *node, char const *type)
{
    t_node *element = node;
    my_putchar('[');
    while (element) {
        if (my_str_is_equal(type, "pointeur"))
            my_printf("%p", element->element);
        if (my_str_is_equal(type, "int"))
            my_put_nbr(element->element);
        if (element->next_element)
            my_putstr(", ");
        element = element->next_element;
    }
    my_putchar(']');
    return node;
}