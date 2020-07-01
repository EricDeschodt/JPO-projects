/*
** EPITECH PROJECT, 2019
** list_utils1
** File description:
** Linked list functions
*/

#include "my.h"

dlist_t *push_back_fat1(all_t *all, dlist_t *li, int pos)
{
    dlist_node_t *element = new_node_fat1(all, pos);
    if (is_empty_list(li)) {
        li = malloc(sizeof(*li));
        li->length = 0;
        li->begin = element;
        li->end = element;
    }
    else {
        li->end->next = element;
        element->back = li->end;
        li->end = element;
    }
    li->length++;
    return (li);
}

dlist_t *push_back_flying(all_t *all, dlist_t *li, int pos)
{
    dlist_node_t *element = new_node_flying(all, pos);
    if (is_empty_list(li)) {
        li = malloc(sizeof(*li));
        li->length = 0;
        li->begin = element;
        li->end = element;
    }
    else {
        li->end->next = element;
        element->back = li->end;
        li->end = element;
    }
    li->length++;
    return (li);
}

dlist_t *pop_front_list(dlist_t *li)
{
    if (is_empty_list(li))
        return (new_list());
    if (li->begin == li->end) {
        free (li->begin);
        free (li);
        return (new_list());
    }
    dlist_node_t *tmp = li->begin;
    li->begin = li->begin->next;
    li->begin->back = NULL;
    tmp->next = NULL;
    tmp->back = NULL;
    free (tmp);
    li->length--;
    return (li);
}

dlist_t *pop_back_list(dlist_t *li)
{
    if (is_empty_list(li))
        return (new_list());
    if (li->end == li->begin) {
        free (li->begin);
        free (li);
        return (new_list());
    }
    dlist_node_t *tmp = li->end;
    li->end = li->end->back;
    li->end->next = NULL;
    tmp->next = NULL;
    tmp->back = NULL;
    free (tmp);
    li->length--;
    return (li);
}

dlist_t *clear_list(dlist_t *li)
{
    while (!is_empty_list(li))
        li = pop_front_list(li);
    return (new_list());
}
