/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_list_utils6
*/

#include "my.h"

dlist_t *push_back_iron_spikes(all_t *all, dlist_t *li, int pos)
{
    dlist_node_t *element = new_node_iron_spikes(all, pos);
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

dlist_node_t *new_node_skull(all_t *all, int pos)
{
    dlist_node_t *element;
    element = malloc(sizeof(*element));
    element->who = 9, element->dead = 0;
    element->traps.sprite = sfSprite_create();
    sfSprite_setTexture(element->traps.sprite, all->texture.text_skull, sfTrue);
    element->traps.pos_traps.y = 380;
    element->traps.pos_traps.x = pos;
    element->traps.rect_traps.top = 0;
    element->traps.rect_traps.left = 0;
    element->traps.rect_traps.width = 62;
    element->traps.rect_traps.height = 75;
    element->traps.scale_traps.x = 0.8, element->traps.scale_traps.y = 0.8;
    sfSprite_setScale(element->traps.sprite, element->traps.scale_traps);
    sfSprite_setTextureRect(element->traps.sprite, element->traps.rect_traps);
    sfSprite_setPosition(element->traps.sprite, element->traps.pos_traps);
    element->next = NULL, element->back = NULL;
    return (element);
}

dlist_node_t *new_node_skull_down(all_t *all, int pos)
{
    dlist_node_t *element;
    element = malloc(sizeof(*element));
    element->who = 9, element->dead = 0;
    element->traps.sprite = sfSprite_create();
    sfSprite_setTexture(element->traps.sprite, all->texture.text_skull, sfTrue);
    element->traps.pos_traps.y = 670;
    element->traps.pos_traps.x = pos;
    element->traps.rect_traps.top = 0;
    element->traps.rect_traps.left = 0;
    element->traps.rect_traps.width = 62;
    element->traps.rect_traps.height = 75;
    element->traps.scale_traps.x = 0.8, element->traps.scale_traps.y = 0.8;
    sfSprite_setScale(element->traps.sprite, element->traps.scale_traps);
    sfSprite_setTextureRect(element->traps.sprite, element->traps.rect_traps);
    sfSprite_setPosition(element->traps.sprite, element->traps.pos_traps);
    element->next = NULL, element->back = NULL;
    return (element);
}

dlist_t *push_back_skull(all_t *all, dlist_t *li, int pos, int who)
{
    dlist_node_t * element;
    if (who == 9)
        element = new_node_skull(all, pos);
    else if (who == 0)
        element = new_node_skull_down(all, pos);
    else
        element = new_node_menu_skull(all);
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

dlist_node_t *new_node_menu_skull(all_t *all)
{
    dlist_node_t *element;
    element = malloc(sizeof(*element));
    element->who = -1, element->dead = 0;
    element->traps.sprite = sfSprite_create();
    sfSprite_setTexture(element->traps.sprite, all->texture.text_skull, sfTrue);
    element->traps.pos_traps.y = 35;
    element->traps.pos_traps.x = 830;
    element->traps.rect_traps.top = 0;
    element->traps.rect_traps.left = 0;
    element->traps.rect_traps.width = 62;
    element->traps.rect_traps.height = 75;
    element->traps.scale_traps.x = 1, element->traps.scale_traps.y = 1;
    sfSprite_setScale(element->traps.sprite, element->traps.scale_traps);
    sfSprite_setTextureRect(element->traps.sprite, element->traps.rect_traps);
    sfSprite_setPosition(element->traps.sprite, element->traps.pos_traps);
    element->next = NULL, element->back = NULL;
    return (element);
}