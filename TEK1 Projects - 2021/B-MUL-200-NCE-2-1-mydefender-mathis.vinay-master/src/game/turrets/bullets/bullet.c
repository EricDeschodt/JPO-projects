/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Basic functions for bullets
*/

#include "../../../../include/game/turrets.h"
#include "../../../../include/game/main_game.h"

bullet_t **bullet_add(main_game_t *g, turret_t *t, enemy_t *enemy)
{
    t->bullets = (bullet_t **)my_tab_extend((void **) t->bullets,
    bullet_create(g, t, enemy));
    return t->bullets;
}

void bullet_display(main_game_t *g, sfRenderWindow *win)
{
    for (int i = 0; g->turret_list[i]; i++) {
        for (int j = 0; g->turret_list[i]->bullets[j]; j++) {
            sfRenderWindow_drawSprite(win,
            g->turret_list[i]->bullets[j]->bullet, NULL);
        }
    }
}

void bullet_animate(main_game_t *g, int i, int vitess)
{
    for (int j = 0; g->turret_list[i]->bullets[j]; j++) {
        sfIntRect rect = sfSprite_getTextureRect
        (g->turret_list[i]->bullets[j]->bullet);
        rect.top -= vitess;
        sfSprite_setTextureRect
        (g->turret_list[i]->bullets[j]->bullet, rect);
        if (-rect.top * ((1080.0 / (double) (get_len_array(g->map) - 1)) /
        128) > g->turret_list[i]->bullets[j]->dist) {
            g->turret_list[i]->bullets[j]->e->health -= g->turret_list[i]->ad;
            if (g->turret_list[i]->bullets[j]->e->health <= 0
                && g->turret_list[i]->bullets[j]->e->health
                > g->turret_list[i]->ad * - 1)
                g->gold += g->turret_list[i]->bullets[j]->e->gold;
            bullet_destroy(g->turret_list[i]->bullets[j]);
            my_tab_rm_line((void **)g->turret_list[i]->bullets, j);
        }
    }
}

void bullets_animate(main_game_t *g, int vitess)
{
    for (int i = 0; g->turret_list[i]; i++) {
        time_update(g->turret_list[i]->time, 1);
        while (g->turret_list[i]->time->counter >= 16666) {
            g->turret_list[i]->time->counter -= 16666;
            bullet_animate(g, i, vitess);
        }
    }
}

void bullet_destroy(bullet_t *bullet)
{
    sfSprite_destroy(bullet->bullet);
    free(bullet);
}