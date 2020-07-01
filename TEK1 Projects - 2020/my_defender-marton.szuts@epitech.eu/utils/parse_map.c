/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** parse_map
*/

#include "utils.h"
#include "defender.h"

support_t *element_tree(char *map, support_t *s_support, parsor_t *s_parsor)
{
    if (map[s_parsor->i] == 'O') {
        s_support = fill_support(s_support,
        s_parsor->pos, "sprites/turret_support.png", 'O');
        s_parsor->pos.x += 120;
    } if (map[s_parsor->i] == 'S') {
        s_support = fill_support(s_support,
        s_parsor->pos, "sprites/spawner.png", 'S'), s_parsor->pos.x += 120;
    } if (map[s_parsor->i] == 'C') {
        s_support = fill_support(s_support, s_parsor->pos,
        "sprites/castle.png", 'C'), s_parsor->pos.x += 120;
    } if (map[s_parsor->i] == 'G') {
        s_support = fill_support(s_support, s_parsor->pos,
        "sprites/ground.png", 'G'), s_parsor->pos.x += 120;
    } if (map[s_parsor->i] == '@') {
        s_support = fill_support(s_support, s_parsor->pos,
        "sprites/case.png", '@'), s_parsor->pos.x += 120;
    } if (map[s_parsor->i] == '\n') {
        s_parsor->pos.y += 120, s_parsor->pos.x = 0;
    } return (s_support);
}

support_t *parse_map(char *map)
{
    parsor_t s_parsor = {0};
    support_t *s_support = NULL;
    s_parsor.pos.y = 30;
    for (; map[s_parsor.i] != '#'; s_parsor.i += 1) {
        if (map[s_parsor.i] == ' ') {
            s_parsor.pos.x += 120;
        }
        else s_support = element_tree(map, s_support, &s_parsor);
    }
    return (s_support);
}