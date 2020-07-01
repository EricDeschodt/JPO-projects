/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_list_utils4
*/

#include "my.h"

dlist_node_t *new_node_traps_axe1(all_t *all, int pos)
{
    dlist_node_t *element;
    element = malloc(sizeof(*element));
    element->who = 3;
    element->dead = 0;
    element->traps.sprite = sfSprite_create();
    sfSprite_setTexture(element->traps.sprite, all->texture.text_traps, sfTrue);
    element->traps.pos_traps.y = 725;
    element->traps.pos_traps.x = pos + 52;
    element->traps.origin_traps.x = 67;
    element->traps.origin_traps.y = 0;
    sfSprite_setOrigin(element->traps.sprite, element->traps.origin_traps);
    element->traps.rect_traps.top = 230;
    element->traps.rect_traps.left = 10, element->traps.rect_traps.width = 135;
    element->traps.rect_traps.height = 185;
    element->traps.rotate = rand () % 360;
    element->traps.float_traps = 0.5 + (float)rand() / (float)(RAND_MAX / 0.7);
    sfSprite_setTextureRect(element->traps.sprite, element->traps.rect_traps);
    sfSprite_setPosition(element->traps.sprite, element->traps.pos_traps);
    element->next = NULL, element->back = NULL;
    return (element);
}

dlist_node_t *new_node_traps_balls(all_t *all, int pos)
{
    dlist_node_t *element;
    element = malloc(sizeof(*element));
    element->who = 4;
    element->dead = 0;
    element->traps.sprite = sfSprite_create();
    sfSprite_setTexture(element->traps.sprite, all->texture.text_traps, sfTrue);
    element->traps.pos_traps.y = 725;
    element->traps.pos_traps.x = pos + 52;
    element->traps.origin_traps.x = 67, element->traps.origin_traps.y = 0;
    sfSprite_setOrigin(element->traps.sprite, element->traps.origin_traps);
    element->traps.rect_traps.top = 200;
    element->traps.rect_traps.left = 529;
    element->traps.rect_traps.width = 135;
    element->traps.rect_traps.height = 215;
    element->traps.rotate = rand () % 360;
    element->traps.float_traps = 0.5 + (float)rand() / (float)(RAND_MAX / 0.7);
    sfSprite_setTextureRect(element->traps.sprite, element->traps.rect_traps);
    sfSprite_setPosition(element->traps.sprite, element->traps.pos_traps);
    element->next = NULL, element->back = NULL;
    return (element);
}

dlist_t *push_back_traps_balls(all_t *all, dlist_t *li, int pos)
{
    dlist_node_t *element = new_node_traps_balls(all, pos);
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

dlist_node_t *new_node_traps_saw(all_t *all, int pos)
{
    dlist_node_t *element;
    element = malloc(sizeof(*element));
    element->who = 5, element->dead = 0;
    element->traps.sprite = sfSprite_create();
    sfSprite_setTexture(element->traps.sprite, all->texture.text_traps, sfTrue);
    element->traps.pos_traps.y = 715, element->traps.pos_traps.x = pos + 53;
    element->traps.origin_traps.x = 56, element->traps.origin_traps.y = 56;
    sfSprite_setOrigin(element->traps.sprite, element->traps.origin_traps);
    element->traps.rect_traps.top = 20;
    element->traps.rect_traps.left = 535;
    element->traps.rect_traps.width = 110;
    element->traps.rect_traps.height = 110;
    element->traps.rotate = rand () % 360;
    element->traps.scale_traps.x = 2, element->traps.scale_traps.y = 2;
    element->traps.float_traps = 0.5 + (float)rand() / (float)(RAND_MAX / 0.7);
    sfSprite_setTextureRect(element->traps.sprite, element->traps.rect_traps);
    sfSprite_setScale(element->traps.sprite, element->traps.scale_traps);
    sfSprite_setPosition(element->traps.sprite, element->traps.pos_traps);
    element->next = NULL, element->back = NULL;
    return (element);
}

dlist_t *push_back_traps_saw(all_t *all, dlist_t *li, int pos)
{
    dlist_node_t *element = new_node_traps_saw(all, pos);
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
