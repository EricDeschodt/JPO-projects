/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Creates the turrets
*/

#include "../../../include/game/turrets.h"
#include "../../../include/game/main_game.h"

float check_volume_value(float volume, int max);

turret_t **turret_add(main_game_t *g, sfVector2i mouse_pos, int mode)
{
    sfVector2f t_pos = {(float) mouse_pos.x, (float) mouse_pos.y};
    g->turret_list = (turret_t **)my_tab_extend((void **) g->turret_list,
    turret_create(g, t_pos, mode));
    return g->turret_list;
}

void turret_set_sound(main_game_t *g)
{
    float current_volume = (float) g->volume;
    current_volume = check_volume_value((float) current_volume, 100);
    for (int i = 0; g->turret_list[i]; i++)
        sound_set_volume(g->turret_list[i]->gunfire, current_volume);
}

void turret_display(main_game_t *game, sfRenderWindow *win)
{
    if (!game->turret_list)
        return;
    for (int i = 0; game->turret_list[i]; i++)
        sfRenderWindow_drawSprite(win, game->turret_list[i]->turret, NULL);
}

void turret_animate(main_game_t *game)
{
    if (!game->turret_list)
        return;
    turret_set_sound(game);
    time_update(game->time, 2);
    while (game->time->counter_4 >= 16666) {
        game->time->counter_4 -= 16666;
        turret_trigger(game);
    }
}

void turrets_destroy(turret_t **turret_list)
{
    for (int i = 0; turret_list[i]; i++) {
        sfSprite_destroy(turret_list[i]->turret);
        time_destroy(turret_list[i]->time);
        for (int j = 0; turret_list[i]->bullets[j]; j++)
            bullet_destroy(turret_list[i]->bullets[j]);
        free(turret_list[i]->bullets);
        sound_destroy(turret_list[i]->gunfire);
        free(turret_list[i]);
    }
    free(turret_list);
}
