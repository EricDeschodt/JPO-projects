/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Detect if an enemy as come in range
*/

#include "../../../include/game/turrets.h"
#include "../../../include/game/main_game.h"

double calculate(turret_t *t, sfVector2f e_pos)
{
    sfVector2f t_pos = sfSprite_getPosition(t->turret);
    double x = pow((double) e_pos.x - ((double) t_pos.x), 2);
    double y = pow((double) e_pos.y - ((double) t_pos.y), 2);
    double xy = x + y;
    double res_len = fabs(sqrt(xy));
    return res_len;
}

int get_nearest_index(main_game_t *g, turret_t *t)
{
    int index = -1;
    double range;
    double mem = t->range;
    for (int j = 0; g->enemy_list[j]; j++) {
        if (g->enemy_list[j]->health > 0 && is_inmap(g->map,
        sfSprite_getPosition(g->enemy_list[j]->enemy))) {
            range = calculate(t, sfSprite_getPosition(g->enemy_list[j]->enemy));
            if (range <= mem) {
                mem = range;
                index = j;
            }
        }
    }
    return index;
}

sfVector2f get_nearest_coords(main_game_t *g, turret_t *t, int index)
{
    sfVector2f t_pos = sfSprite_getPosition(t->turret);
    if (g->enemy_list[index]->health <= 0 || !is_inmap(g->map,
    sfSprite_getPosition(g->enemy_list[index]->enemy)))
        return t_pos;
    sfVector2f e_pos = sfSprite_getPosition(g->enemy_list[index]->enemy);
    return e_pos;
}

void aim_nearest(main_game_t *g, turret_t *t, sfVector2f pos)
{
    sfVector2f t_pos = sfSprite_getPosition(t->turret);
    if (t_pos.x == pos.x && t_pos.y == pos.y) {
        return;
    }
    else {
        double x = pos.x - t_pos.x;
        double y = pos.y - t_pos.y;
        int dist = (int) calculate(t, sfSprite_getPosition
        (g->enemy_list[get_nearest_index(g, t)]->enemy));
        double decal = (double)dist / (30.0 * ((1080.0 / (double)
        (get_len_array(g->map) - 1)) / 128));
        x += g->enemy_list[get_nearest_index(g, t)]->speed_x * decal;
        y += g->enemy_list[get_nearest_index(g, t)]->speed_y * decal;
        float angle = get_angle(0, -5, (float)x, (float)y);
        sfSprite_setRotation(t->turret, angle);
    }
}

void turret_trigger(main_game_t *g)
{
    int n = 0;
    for (int i = 0; g->turret_list[i]; i++) {
        n = get_nearest_index(g, g->turret_list[i]);
        if (n != -1) {
            sfVector2f m = get_nearest_coords(g, g->turret_list[i], n);
            aim_nearest(g, g->turret_list[i], m);
            turret_fire(g, g->turret_list[i], g->enemy_list[n]);
        }
    }
}