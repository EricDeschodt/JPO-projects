/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** my_list_1
*/

#include "defender.h"

int list_size(l_list *list)
{
    int i = 0;
    for (l_list *tmp = list; tmp != NULL; tmp = tmp->next, i++);
    return (i);
}

l_list *free_list(l_list *head)
{
    while (head != NULL) {
        head = pop_front(head);
    }
    return (head);
}

int my_atoi(char *str)
{
    int res = 0;
    if (str == NULL)
        return (-1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        res = res * 10 + (str[i] - 48);
    }
    return (res);
}

void create_map_back(s_game *game, s_var *tmp, char *slots[], char *path[])
{
    int i = find_flag(tmp->c);
    if (i < 9) {
        push_back(&game->maps[tmp->j], create_map_object(path[i],
        (v2){tmp->x, tmp->y}, LAND));
    }
    else if (i > 8 && i < 15) {
        push_back(&game->maps[tmp->j], create_map_object(path[i],
        (v2){tmp->x, tmp->y}, ROAD));
    }
    else {
        push_back1(&game->slots[tmp->j],
        create_slot_object(slots, (v2){tmp->x, tmp->y}), NONE);
        push_back1(&game->b_slots[tmp->j],
        create_slot_object(slots, (v2){tmp->x, tmp->y}), NONE);
        push_back(&game->maps[tmp->j], create_map_object("sprites/land_1.png",
        (v2){tmp->x, tmp->y}, LAND));
    }
}

char ***enemies_path(void)
{
    char *path_devil[] = {"sprites/devil_up.png", "sprites/devil_down.png",
    "sprites/devil_left.png", "sprites/devil_right.png"};
    char *path_knight[] = {"sprites/knight_up.png", "sprites/knight_down.png",
    "sprites/knight_left.png", "sprites/knight_right.png"};
    char *path_assasin[] = {"sprites/assasin_up.png",
    "sprites/assasin_down.png", "sprites/assasin_left.png",
    "sprites/assasin_right.png"};
    char **path[] = {path_devil, path_knight, path_assasin};
    char ***tmp = malloc(sizeof(char **) * 4);
    for (int i = 0; i < 3; i++) {
        tmp[i] = malloc(sizeof(char *) * 5);
        for (int j = 0; j < 4; j++) {
            tmp[i][j] = malloc(sizeof(char) * 50);
            my_strcpy(tmp[i][j], path[i][j]);
        }
    }
    return (tmp);
}