/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** menu_buttons
*/

#include "defender.h"

list_buttons_t *new_list_buttons(void)
{
    return (NULL);
}

int is_empty_list_buttons(list_buttons_t *li)
{
    if (li == NULL)
        return (1);
    return (0);
}

node_buttons_t *new_node_buttons(all_t *s_all, int y, int who, int i)
{
    node_buttons_t *node;
    node = malloc(sizeof(*node));
    node->who = who;
    node->pos = (sfVector2f){1820, y};
    node->sprite = sfSprite_create();
    node->texture =
        sfTexture_createFromFile(s_all->s_buttons_tab.tab[i], NULL);
    node->texture2 =
        sfTexture_createFromFile(s_all->s_buttons_tab.tab2[i], NULL);
    sfSprite_setTexture(node->sprite, node->texture, sfTrue);
    sfSprite_setPosition(node->sprite, node->pos);
    node->next = NULL;
    return (node);
}

list_buttons_t *push_back_buttons(all_t *s_all, int y, int who, int i)
{
    node_buttons_t *node = new_node_buttons(s_all, y, who, i);
    if (is_empty_list_buttons(s_all->s_buttons)) {
        s_all->s_buttons = malloc(sizeof(*s_all->s_buttons));
        s_all->s_buttons->length = 0;
        s_all->s_buttons->clock = sfClock_create();
        s_all->s_buttons->time =
            sfClock_getElapsedTime(s_all->s_buttons->clock);
        s_all->s_buttons->seconds =
            s_all->s_buttons->time.microseconds / 1000000.0;
        s_all->s_buttons->begin = node;
        s_all->s_buttons->end = node;
        sfSprite_setPosition(s_all->s_menu.sp_background, (sfVector2f){0, -50});
        black_init(s_all);
    } else {
        s_all->s_buttons->end->next = node;
        s_all->s_buttons->end = node;
    } s_all->s_buttons->length++;
    return (s_all->s_buttons);
}

list_buttons_t *pop_front_buttons(list_buttons_t *li)
{
    if (is_empty_list_buttons(li))
        return (new_list_buttons());
    if (li->begin == li->end) {
        free (li->begin);
        free (li);
        return (new_list_buttons());
    }
    node_buttons_t *tmp = li->begin;
    li->begin = li->begin->next;
    tmp->next = NULL;
    free (tmp);
    li->length--;
    return (li);
}