/*
** EPITECH PROJECT, 2019
** list_utils2
** File description:
** Linked list functions
*/

#include "my.h"

dlist_t *new_list(void)
{
    return (NULL);
}

int is_empty_list(dlist_t *li)
{
    if (li == NULL)
        return (1);
    return (0);
}

dlist_node_t *random_rect_fat(dlist_node_t *element)
{
    int i = rand() % 8;
    if (i == 0)
        element->fat.rect_fat.left = 900, element->fat.rect_fat.top = 0;
    if (i == 1)
        element->fat.rect_fat.left = 600, element->fat.rect_fat.top = 0;
    if (i == 2)
        element->fat.rect_fat.left = 300, element->fat.rect_fat.top = 0;
    if (i == 3)
        element->fat.rect_fat.left = 0, element->fat.rect_fat.top = 0;
    if (i == 4)
        element->fat.rect_fat.left = 900, element->fat.rect_fat.top = 335;
    if (i == 5)
        element->fat.rect_fat.left = 600, element->fat.rect_fat.top = 335;
    if (i == 6)
        element->fat.rect_fat.left = 300, element->fat.rect_fat.top = 335;
    if (i == 7)
        element->fat.rect_fat.left = 0, element->fat.rect_fat.top = 335;
    return (element);
}

dlist_node_t *new_node_fat1(all_t *all, int pos)
{
    dlist_node_t *element;
    element = malloc(sizeof(*element));
    element->who = 0, element->dead = 0;
    element->fat.float_fat = 0.5 + (float)rand() / (float)(RAND_MAX / 0.7);
    element->fat.sprite = sfSprite_create();
    sfSprite_setTexture(element->fat.sprite,
        all->texture.text_fat_zombie, sfTrue);
    element->fat.pos_fat.y = 785, element->fat.pos_fat.x = pos;
    element->fat.origin_fat.x = 300;
    element->fat.origin_fat.y = 280;
    element->fat.scale_fat.x = element->fat.float_fat;
    element->fat.scale_fat.y = element->fat.float_fat;
    sfSprite_setPosition(element->fat.sprite, element->fat.pos_fat);
    sfSprite_setScale(element->fat.sprite, element->fat.scale_fat);
    sfSprite_setOrigin(element->fat.sprite, element->fat.origin_fat);
    element = random_rect_fat(element);
    element->fat.rect_fat.width = 300;
    element->fat.rect_fat.height = 280;
    element->next = NULL, element->back = NULL;
    return (element);
}

dlist_t *pop_anywhere(dlist_t *li, dlist_node_t *tmp)
{
    if (is_empty_list(li))
        return (new_list());
    if (li->end == li->begin) {
        free(li->begin), free(li);
        return (new_list());
    }
    if (li->end == tmp) {
        li->end = li->end->back, li->end->next = NULL, tmp->next = NULL;
        tmp->back = NULL, free(tmp);
    }
    else if (li->begin == tmp) {
        li->begin = li->begin->next, li->begin->back = NULL, tmp->next = NULL;
        tmp->back = NULL, free(tmp);
    }
    else
        tmp->back->next = tmp->next, tmp->next->back = tmp->back, free(tmp);
    li->length--;
    return (li);
}