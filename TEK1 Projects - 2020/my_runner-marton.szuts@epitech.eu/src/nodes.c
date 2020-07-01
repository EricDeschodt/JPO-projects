/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** nodes
*/

#include "runner.h"

void free_map(controll_t *s_controll)
{
    free_monsters(s_controll);
    free_obstacles(s_controll);
    free_coins(s_controll);
}

void free_monster(monster1_t *s_monster, controll_t *s_controll)
{
    monster1_t *temp = s_controll->s_monster;
    if (s_controll->s_monster != s_monster) {
        while (temp->next != s_monster)
            temp = temp->next;
        temp->next = s_monster->next;
        destroy_monster(s_monster);
        free(s_monster);
    }
    else {
        s_controll->s_monster = s_monster->next;
        destroy_monster(s_monster);
        free(s_monster);
    }
}

void free_coin(coin_t *s_coin, controll_t *s_controll)
{
    coin_t *temp = s_controll->s_coin;
    if (s_controll->s_coin != s_coin) {
        while (temp->next != s_coin)
            temp = temp->next;
        temp->next = s_coin->next;
        destroy_coin(s_coin);
        free(s_coin);
    }
    else {
        s_controll->s_coin = s_coin->next;
        destroy_coin(s_coin);
        free(s_coin);
    }
}

void free_obstacle(obstacle_t *s_obstacle, controll_t *s_controll)
{
    obstacle_t *temp = s_controll->s_obstacle;
    if (s_controll->s_obstacle != s_obstacle) {
        while (temp->next != s_obstacle)
            temp = temp->next;
        temp->next = s_obstacle->next;
        destroy_obstacle(s_obstacle);
        free(s_obstacle);
    }
    else {
        s_controll->s_obstacle = s_obstacle->next;
        destroy_obstacle(s_obstacle);
        free(s_obstacle);
    }
}

buttons_t *get_last_node(buttons_t *s_button)
{
    buttons_t *temp = s_button;
    while (temp->next->next != NULL)
        temp = temp->next;
    return (temp);
}