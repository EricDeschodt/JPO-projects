/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** transition2
*/

#include "defender.h"

lost_t *init_node(lost_t *node, all_t *s_all, float radius)
{
    sfVector2u center = sfRenderWindow_getSize(s_all->s_game.window);
    static int color = 0;

    node->circle = sfCircleShape_create();
    if (color == 0) {
        color = 1;
        sfCircleShape_setFillColor(node->circle, (sfColor){22, 22, 22, 255});
    } else {
        color = 0;
        sfCircleShape_setFillColor(node->circle,
            (sfColor){30, 31, 30, 255});
    }
    node->display = 0;
    sfCircleShape_setRadius(node->circle, radius);
    sfFloatRect bounds = sfCircleShape_getGlobalBounds(node->circle);
    sfCircleShape_setOrigin(node->circle,
        (sfVector2f){bounds.width / 2, bounds.height / 2});
    sfCircleShape_setPosition(node->circle,
        (sfVector2f){center.x / 2, center.y / 2});
    return (node);
}

lost_t *push_front_lost(lost_t *head, all_t *s_all, float radius)
{
    lost_t *node = malloc(sizeof(lost_t));

    node = init_node(node, s_all, radius);
    node->next = head;

    return (node);
}

lost_t *init_lost_screen(all_t *s_all)
{
    lost_t *head = NULL;
    int radius = 75;

    s_all->s_game.anim_clock = sfClock_create();
    for (int i = 0; i != 10; i++) {
        head = push_front_lost(head, s_all, radius);
        radius += 150;
    }

    return (head);
}