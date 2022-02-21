/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** creates an enemy
*/

#include "../../../include/game/init_enemies.h"
#include "../../../include/game/main_game.h"

bool set_enemy(enemy_t *enemy, sfTexture *texture, int health, float speed)
{
    sfSprite_setTexture(enemy->enemy, texture, sfTrue);
    enemy->health = health;
    enemy->global_speed = speed;
    return true;
}

bool prepare_enemy(main_game_t *game, enemy_t *enemy, double gen)
{
    if (gen >= 5.0 / 6.0)
        return set_enemy(enemy, game->texture_list[5], 500, 2);
    if (gen >= 4.0 / 6.0)
        return set_enemy(enemy, game->texture_list[4], 300, 1);
    if (gen >= 3.0 / 6.0)
        return set_enemy(enemy, game->texture_list[3], 150, 3);
    if (gen >= 2.0 / 6.0)
        return set_enemy(enemy, game->texture_list[2], 50, 4);
    if (gen >= 1.0 / 6.0)
        return set_enemy(enemy, game->texture_list[1], 20, 3);
    return set_enemy(enemy, game->texture_list[0], 10, 2);
}

bool choice_enemy_type(main_game_t *game, enemy_t *enemy)
{
    double gen = (((double)rand() / 2147483647.0) + game->difficulty *
    game->homogenity) / (game->homogenity + 1.0);
    prepare_enemy(game, enemy, gen);
    if (gen >= 5.0 / 6.0)
        return enemy->gold = 95;
    if (gen >= 4.0 / 6.0)
        return enemy->gold = 80;
    if (gen >= 3.0 / 6.0)
        return enemy->gold = 50;
    if (gen >= 2.0 / 6.0)
        return enemy->gold = 30;
    if (gen >= 1.0 / 6.0)
        return enemy->gold = 10;
    return enemy->gold = 5;
}