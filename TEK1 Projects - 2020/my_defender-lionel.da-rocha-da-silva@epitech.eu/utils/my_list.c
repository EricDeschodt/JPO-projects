/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** my_list
*/

#include "defender.h"

void push_back1(t_list **list, s_slot *data[], tw_type type)
{
    while (*list)
        list = &(*list)->next;

    *list = malloc(sizeof(**list));
    for (int i = 0; i < 5; i++) {
        (*list)->tower[i] = data[i];
    }
    (*list)->type = type;
    (*list)->next = NULL;
}

void push_back(l_list **list, s_map *data)
{
    while (*list)
        list = &(*list)->next;

    *list = malloc(sizeof(**list));
    (*list)->map = data;
    (*list)->next = NULL;
}

l_list *pop_front(l_list *head)
{
    l_list *tmp;

    if (head == NULL)
        return NULL;

    tmp = head;
    head = head->next;
    free(tmp);

    return head;
}

l_list *pop_back(l_list *head)
{
    l_list *tmp;

    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    tmp = head;
    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;

    return (head);
}

void create_wave(s_game *game, int l, int k, char **path[])
{
    int t = 0, n = 0, j = 0;
    game->enemies[l][k] = malloc(sizeof(s_wave *) * (game->wave_nbs[0] + 1));
    game->enemies[l][k] = malloc(sizeof(s_wave *) * (game->wave_nbs[0] + 1));
    for (int i = 0; i < 3; i++) {
        j = game->wave_nbs[i + 1];
        for (; j > 0; j--, t -= 100, n++) {
            game->enemies[l][k][n] = create_grid_struct
            (create_mob_object(path, (v2){-100 + t, 312}, i),
            game->grid[l], l);
            game->b_enemies[l][k][n] = create_grid_struct
            (create_mob_object(path, (v2){-100 + t, 312}, i),
            game->grid[l], l);
        }
        game->w_len[k] = n;
    }
}
