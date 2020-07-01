/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** list_utils_targetting
*/

#include "defender.h"

int is_empty_list_targetting(list_targetting_t *li)
{
    if (li == NULL)
        return (1);
    return (0);
}

void string_init(targetting_t *node, int k)
{
    node->str = sfText_create();
    node->text_pos = (sfVector2f){1947, 430};
    sfText_setPosition(node->str, node->text_pos);
    node->font = sfFont_createFromFile("font/arial.ttf");
    sfText_setFont(node->str, node->font);
    sfText_setCharacterSize(node->str, 24);
    if (k == 0) sfText_setString(node->str, "FIRST");
    if (k == 1) sfText_setString(node->str, "LAST");
    if (k == 2) sfText_setString(node->str, "WEAKEST");
    if (k == 3) sfText_setString(node->str, "STRONGEST");
    if (k == 4) sfText_setString(node->str, "NEAREST");
}

targetting_t *new_node_targetting(int x, char *tab, int i)
{
    static int k = 0;
    targetting_t *node = malloc(sizeof(*node));
    string_init(node, k);
    node->show = 1;
    node->pos = (sfVector2f){x, 445}, node->sprite = sfSprite_create();
    node->texture = sfTexture_createFromFile(tab, NULL), node->next = NULL;
    sfSprite_setTexture(node->sprite, node->texture, sfTrue);
    sfSprite_setPosition(node->sprite, node->pos), node->back = NULL, k++;
    sfSprite_setOrigin(node->sprite, (sfVector2f){50, 48});
    sfSprite_setScale(node->sprite, (sfVector2f){0.75, 0.75});
    if (i == 1) { sfSprite_setScale(node->sprite, (sfVector2f){1, 1});
        node->big = 1;
    } else node->big = 0;
    return (node);
}

list_targetting_t *push_back_targetting(all_t *s_all, int x, char *tab)
{
    static int i = 1;
    targetting_t *node = new_node_targetting(x, tab, i);
    if (is_empty_list_targetting(s_all->s_targetting)) {
        s_all->s_targetting = malloc(sizeof(*s_all->s_targetting));
        s_all->s_targetting->length = 0;
        s_all->s_targetting->clock = sfClock_create();
        s_all->s_targetting->time =
            sfClock_getElapsedTime(s_all->s_targetting->clock);
        s_all->s_targetting->seconds =
            s_all->s_targetting->time.microseconds / 1000000.0;
        s_all->s_targetting->begin = node;
        s_all->s_targetting->end = node;
    } else {
        s_all->s_targetting->end->next = node;
        node->back = s_all->s_targetting->end;
        s_all->s_targetting->end = node;
    } s_all->s_targetting->length++;
    i = 0, s_all->s_targetting->size = 50;
    return (s_all->s_targetting);
}

targetting_t *new_node_turret_targetting(int x, char *tab, int i)
{
    static int k = 0;
    targetting_t *node = malloc(sizeof(*node));
    string_init(node, k);
    node->show = 1;
    node->pos = (sfVector2f){x, 965}, node->sprite = sfSprite_create();
    node->texture = sfTexture_createFromFile(tab, NULL), node->next = NULL;
    sfSprite_setTexture(node->sprite, node->texture, sfTrue);
    sfSprite_setPosition(node->sprite, node->pos), node->back = NULL, k++;
    sfSprite_setOrigin(node->sprite, (sfVector2f){50, 48});
    sfSprite_setScale(node->sprite, (sfVector2f){0.75, 0.75});
    if (i == 1) { sfSprite_setScale(node->sprite, (sfVector2f){1, 1});
        node->big = 1;
    } else node->big = 0;
    return (node);
}