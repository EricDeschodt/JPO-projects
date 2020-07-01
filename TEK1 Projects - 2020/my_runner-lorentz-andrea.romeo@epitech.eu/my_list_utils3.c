/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_list_utils3
*/

#include "my.h"

dlist_node_t *random_rect_flying(dlist_node_t *element)
{
    int i = rand() % 3;
    if (i == 0)
        element->flying.rect_flying.left = 800;
    if (i == 1)
        element->flying.rect_flying.left = 610;
    if (i == 2)
        element->flying.rect_flying.left = 420;
    return (element);
}

dlist_node_t *new_node_flying(all_t *all, int pos)
{
    dlist_node_t *element;
    element = malloc(sizeof(*element));
    element->who = 1;
    element->dead = 0;
    element->flying.sprite = sfSprite_create();
    sfSprite_setTexture(element->flying.sprite,
        all->texture.text_flying_zombie, sfTrue);
    element->flying.color = sfColor_fromRGBA(255, 255, 255, 255);
    element->flying.alpha = 255;
    element->flying.pos_flying.y = 545;
    element->flying.pos_flying.x = pos;
    element = random_rect_flying(element);
    element->flying.rect_flying.top = 940;
    element->flying.rect_flying.width = 200;
    element->flying.rect_flying.height = 300;
    sfSprite_setPosition(element->flying.sprite, element->flying.pos_flying);
    element->next = NULL, element->back = NULL;
    return (element);
}

dlist_node_t *new_node_traps_base(all_t *all, int pos)
{
    dlist_node_t *element;
    element = malloc(sizeof(*element));
    element->who = 2, element->dead = 0;
    element->traps.sprite = sfSprite_create();
    sfSprite_setTexture(element->traps.sprite, all->texture.text_traps, sfTrue);
    element->traps.pos_traps.y = 695;
    element->traps.pos_traps.x = pos;
    element->traps.rect_traps.top = 340;
    element->traps.rect_traps.left = 210;
    element->traps.rect_traps.width = 110;
    element->traps.rect_traps.height = 110;
    sfSprite_setTextureRect(element->traps.sprite, element->traps.rect_traps);
    element->traps.origin_traps.x = 0;
    element->traps.origin_traps.y = 0;
    element->traps.float_traps = 0.5 + (float)rand() / (float)(RAND_MAX / 0.7);
    sfSprite_setPosition(element->traps.sprite, element->traps.pos_traps);
    element->next = NULL;
    element->back = NULL;
    return (element);
}

dlist_t *push_back_traps_base(all_t *all, dlist_t *li, int pos)
{
    dlist_node_t *element = new_node_traps_base(all, pos);
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

dlist_t *push_back_traps_axe1(all_t *all, dlist_t *li, int pos)
{
    dlist_node_t *element = new_node_traps_axe1(all, pos);
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