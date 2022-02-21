/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** edits a linked list
*/

#include "../include/linked_lists.h"
#include "../../graphical/include/sprites.h"
#include "../../../include/game/init_enemies.h"

t_node *list_push(t_node **node, void *var)
{
    t_node *element = malloc(sizeof(t_node));
    element->element = var;
    element->next_element = *node;
    *node = element;
    return *node;
}

void list_append(t_node **list, void *new_data)
{
    t_node *new_elem = malloc(sizeof(t_node));
    t_node *last = (*list);
    new_elem->element = new_data;
    new_elem->next_element = NULL;

    if ((*list) == NULL) {
        new_elem->prev_element = NULL;
        (*list) = new_elem;
        return;
    }
    while (last->next_element)
        last = last->next_element;
    last->next_element = new_elem;
    new_elem->prev_element = last;
}

t_node *list_pop(t_node **node, char const *type)
{
    if (my_str_is_equal(type, "free"))
        free((*node)->element);
    if (my_str_is_equal(type, "sprite")) {
        sprite_destroy((*node)->element);
    }
    t_node *next_element = (*node)->next_element;
    free(*node);
    *node = next_element;
    return next_element;
}