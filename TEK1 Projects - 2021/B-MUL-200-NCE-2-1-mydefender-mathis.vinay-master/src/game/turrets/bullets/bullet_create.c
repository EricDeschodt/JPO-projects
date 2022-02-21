/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** creates the bullets
*/

#include "../../../../include/game/turrets.h"
#include "../../../../include/game/main_game.h"
#include <math.h>

float get_angle_b(float x, float y, float x1, float y1)
{
    float angle = (float) to_degrees(atan2f(x - x1, y1 - y));
    return angle;
}

void bullet_set_rotation(main_game_t *g, turret_t *t, bullet_t *b, double v)
{
    sfVector2f e_pos = get_nearest_coords(g, t, get_nearest_index(g, t));
    sfVector2f t_pos = sfSprite_getPosition(t->turret);
    double x = e_pos.x - t_pos.x;
    double y = e_pos.y - t_pos.y;
    b->dist = (int) calculate(t, sfSprite_getPosition
    (g->enemy_list[get_nearest_index(g, t)]->enemy));
    double decal = (double)b->dist / (30.0 * ((1080.0 / (double)
    (get_len_array(g->map) - 1)) / 128));
    float h =  (float)(1080.0 / (float)(get_len_array(g->map) - 1));
    x += g->enemy_list[get_nearest_index(g, t)]->speed_x * decal * h * v;
    y += g->enemy_list[get_nearest_index(g, t)]->speed_y * decal * h * v;
    sfVector2f n_pos = {(float)(g->enemy_list[get_nearest_index(g, t)
    ]->speed_x * decal) + e_pos.x, (float)(g->enemy_list[get_nearest_index(g,
    t)]->speed_y * decal) + e_pos.y};
    b->dist = (int) calculate(t, n_pos);
    float angle = get_angle_b(0, 5, (float)x, (float)y);
    sfSprite_setRotation(b->bullet, angle);
}

void bullet_setpos(main_game_t *g, turret_t *t, bullet_t *b)
{
    sfVector2f t_pos = sfSprite_getPosition(t->turret);
    sfVector2u size = sfTexture_getSize(g->texture_list[10]);
    sfIntRect rect = sfSprite_getTextureRect(b->bullet);
    rect.height = 10000;
    sfSprite_setTextureRect(b->bullet, rect);
    sfVector2f origin = {(float)size.x / 2, (float)size.x / 2};
    sfSprite_setOrigin(b->bullet, origin);
    sfSprite_setPosition(b->bullet, t_pos);
    sfVector2f scale = {(float)((1080.0 / (double)(get_len_array(g->map)))
    / 128), (float)((1080.0 /
    (double)(get_len_array(g->map))) / 128)};
    sfSprite_setScale(b->bullet, scale);
    bullet_set_rotation(g, t, b, 0.015);
}

bullet_t *bullet_create(main_game_t *g, turret_t *t, enemy_t *enemy)
{
    bullet_t *bullet = malloc(sizeof(bullet_t));
    bullet->bullet = sfSprite_create();
    sfSprite_setTexture(bullet->bullet, g->texture_list[t->mode + 10], sfFalse);
    bullet->e = enemy;
    bullet_setpos(g, t, bullet);
    return bullet;
}