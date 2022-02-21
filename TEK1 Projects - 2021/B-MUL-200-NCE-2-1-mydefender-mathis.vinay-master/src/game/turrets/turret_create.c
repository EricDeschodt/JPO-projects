/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Create turrets
*/

#include "../../../include/game/turrets.h"
#include "../../../include/game/main_game.h"

void set_infos(turret_t *t, int ad, int range, int dps)
{
    t->ad = ad;
    t->range = range;
    t->dps = dps;
}

void setup_mode(main_game_t *g, turret_t *t, int mode)
{
    float h =  (float)(1080.0 / (float)(get_len_array(g->map) - 1));
    sfSprite_setTexture(t->turret, g->texture_list[mode + 6], sfFalse);
    if (mode == 0) {
        set_infos(t, 2, (int) (2 * h), 650000);
        t->cost = 45;
    }
    if (mode == 1) {
        set_infos(t, 4, (int) (2.5 * h), 900000);
        t->cost = 75;
    }
    if (mode == 2) {
        set_infos(t, 50, (int) (4 * h), 2500000);
        t->cost = 450;
    }
    if (mode == 3) {
        set_infos(t, 40, (int) (8 * h), 2000000);
        t->cost = 350;
    }
    t->upgraded = false;
    t->mode = mode;
}

turret_t *turret_create(main_game_t *g, sfVector2f pos, int mode)
{
    turret_t *turret = malloc(sizeof(turret_t));
    turret->turret = sfSprite_create();
    turret->bullets = malloc(sizeof(bullet_t));
    turret->bullets[0] = NULL;
    turret->time = time_create();
    turret_set(g, turret, pos);
    setup_mode(g, turret, mode);
    turret->gunfire = sound_create("assets/audio/gunfire.ogg", false,
                                    g->volume);
    return turret;
}

void turret_destroy(turret_t *turret)
{
    sfSprite_destroy(turret->turret);
    time_destroy(turret->time);
    for (int j = 0; turret->bullets[j]; j++)
        bullet_destroy(turret->bullets[j]);
    free(turret->bullets);
    sound_destroy(turret->gunfire);
    free(turret);
}