/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** list_utils_settings
*/

#include "defender.h"

int is_empty_list_settings(list_settings_t *li)
{
    if (li == NULL)
        return (1);
    return (0);
}

node_settings_t *new_node_settings(int y, int x, int id)
{
    node_settings_t *node;
    node = malloc(sizeof(*node));
    node->id = id;
    node->pos = (sfVector2f){x, y};
    node->sprite = sfSprite_create();
    if (id < 4) {
        node->on = sfTexture_createFromFile("sprites/buttons/on.png", NULL);
        node->off = sfTexture_createFromFile("sprites/buttons/off.png", NULL);
    } else {
        node->on = sfTexture_createFromFile("sprites/buttons/ok.png", NULL);
        node->off =
            sfTexture_createFromFile("sprites/buttons/not_ok.png", NULL);
    } if (id == 0 || id == 4 || id == 6)
        sfSprite_setTexture(node->sprite, node->off, sfTrue);
    else
        sfSprite_setTexture(node->sprite, node->on, sfTrue);
    sfSprite_setPosition(node->sprite, node->pos);
    node->next = NULL;
    return (node);
}

list_settings_t *push_back_settings(all_t *s_all, int x, int y, int id)
{
    node_settings_t *node = new_node_settings(y, x, id);
    if (is_empty_list_settings(s_all->s_settings)) {
        s_all->s_settings = malloc(sizeof(*s_all->s_settings));
        s_all->s_settings->length = 0;
        s_all->s_settings->eric = 0;
        s_all->s_settings->shaders = 1;
        s_all->s_settings->sound = 1;
        s_all->s_settings->music = 1;
        s_all->s_settings->begin = node;
        s_all->s_settings->end = node;
        sfSprite_setPosition(s_all->s_menu.sp_background, (sfVector2f){0, -50});
        black_init(s_all);
    } else {
        s_all->s_settings->end->next = node;
        s_all->s_settings->end = node;
    } s_all->s_settings->length++;
    return (s_all->s_settings);
}

list_settings_t *pop_front_settings(list_settings_t *li)
{
    if (is_empty_list_settings(li))
        return (NULL);
    if (li->begin == li->end) {
        free (li->begin);
        free (li);
        return (NULL);
    }
    node_settings_t *tmp = li->begin;
    li->begin = li->begin->next;
    tmp->next = NULL;
    free (tmp);
    li->length--;
    return (li);
}

list_settings_t *clear_list_settings(list_settings_t *li)
{
    while (!is_empty_list_settings(li))
        li = pop_front_settings(li);
    return (NULL);
}