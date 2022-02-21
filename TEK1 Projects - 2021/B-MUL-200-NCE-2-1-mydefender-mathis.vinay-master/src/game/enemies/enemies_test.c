/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** functions to do some tests on enemies
*/

#include "../../../include/game/main_game.h"

bool is_inmap(char **map, sfVector2f position)
{
    float h = (float)(1080.0 / (float)(get_len_array(map) - 1));
    sfVector2f pos = position;
    if (pos.x > h * (float)(get_greater_line(map)) || pos.x < 0 || pos.y > h *
    (float)(get_len_array(map)- 1) || pos.y < 0)
        return false;
    return true;
}

bool is_spwnd(enemy_t **enemies)
{
    for (int i = 0; enemies[i]; i++)
        if (!enemies[i]->is_spawned) return false;
    return true;
}

bool are_all_enemies_dead(enemy_t **enemies, char **map)
{
    for (int i = 0; enemies[i]; i++)
        if (is_inmap(map, sfSprite_getPosition(enemies[i]->enemy)) &&
        enemies[i]->health > 0)
            return false;
    return true;
}