/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** init the enemies
*/

#include "../../../include/game/init_enemies.h"
#include "../../../include/game/main_game.h"

void enemy_set_pos_scale(main_game_t *game, enemy_t *enemy, int const *start)
{
    float h =  (float)(1080.0 / (float)(get_len_array(game->map) - 1));
    if (start[1] == 0 || start[1] == get_len_array(game->map)) {
        sfVector2f pos = {(float)start[1] * h,
        (float)(start[0] - 1) * h + (h / 2)};
        sfSprite_setPosition(enemy->enemy, pos);
    } else {
        sfVector2f pos = {(float)start[1] * h + (h / 2),
        (float)(start[0] - 1) * h};
        sfSprite_setPosition(enemy->enemy, pos);
    }
    sfVector2f scale = {(float)((1080.0 / (double)(get_len_array(game->map)))
    / 128), (float)((1080.0 / (double)(get_len_array(game->map))) / 128)};
    sfSprite_setScale(enemy->enemy, scale);
    sfVector2u size = sfTexture_getSize(game->texture_list[0]);
    sfVector2f origin = {(float) size.x / 2, (float) size.y / 2};
    sfSprite_setOrigin(enemy->enemy, origin);
}

void create_life(enemy_t *enemy, main_game_t *g)
{
    float h =  (float)(1080.0 / (float)(get_len_array(g->map) - 1));
    enemy->max_health = enemy->health;
    enemy->life_front = sfSprite_create();
    enemy->life_back = sfSprite_create();
    sfSprite_setTexture(enemy->life_front, g->texture_list[15], sfTrue);
    sfSprite_setTexture(enemy->life_back, g->texture_list[14], sfTrue);
    sfVector2u size_f = sfTexture_getSize(g->texture_list[15]);
    sfVector2u size_b = sfTexture_getSize(g->texture_list[14]);
    sfVector2f origin_f = {(float) size_f.x / 2, (float) size_f.y / 2};
    sfVector2f origin_b = {(float) size_b.x / 2, (float) size_b.y / 2};
    sfSprite_setOrigin(enemy->life_front, origin_f);
    sfSprite_setOrigin(enemy->life_back, origin_b);
    sfVector2f scale = {(float)((1080.0 / (double)(get_len_array(g->map) - 1))
    / 128), (float)((1080.0 / (double)(get_len_array(g->map) - 1)) / 128)};
    sfSprite_setScale(enemy->life_front, scale);
    sfSprite_setScale(enemy->life_back, scale);
    sfVector2f pos = sfSprite_getPosition(enemy->enemy);
    pos.y += h / 2;
    sfSprite_setPosition(enemy->life_front, pos);
    sfSprite_setPosition(enemy->life_back, pos);
}

enemy_t *create_enemy(main_game_t *game)
{
    enemy_t *enemies = malloc(sizeof(enemy_t));
    enemies->enemy = sfSprite_create();
    choice_enemy_type(game, enemies);
    int *start = get_start_pos(game->map);
    enemies->is_spawned = false;
    enemies->speed_x = 0;
    enemies->speed_y = 0;
    enemies->last_y = start[0];
    enemies->last_x = start[1];
    enemy_set_pos_scale(game, enemies, start);
    create_life(enemies, game);
    free(start);
    return enemies;
}

enemy_t **create_enemy_list(main_game_t *game)
{
    int i = 0;
    enemy_t **enemy_list = malloc(sizeof(enemy_t *) * (game->nb_enemies + 1));
    for (; i < game->nb_enemies; i++) {
        enemy_list[i] = create_enemy(game);
    }
    enemy_list[i] = NULL;
    add_difficulty(game, 1.0);
    return enemy_list;
}

void free_enemy(enemy_t **enemy)
{
    for (int i = 0; enemy[i]; i++) {
        sfSprite_destroy(enemy[i]->enemy);
        sfSprite_destroy(enemy[i]->life_front);
        sfSprite_destroy(enemy[i]->life_back);
        free(enemy[i]);
    }
    free(enemy);
}
