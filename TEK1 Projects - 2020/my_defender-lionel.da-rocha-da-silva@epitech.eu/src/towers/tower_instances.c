/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tower_instances.c
*/

#include "defender.h"

void on_dam_tower(void *data)
{
    s_game *g = (s_game *)data;
    t_tower_menu *tower_m = &g->tower_m;
    t_tower *t = tower_m->t_tower_dam;
    tower_m->slot->tower = t;
    tower_m->slot->is_tower = 1;
    sfSprite_setTexture(tower_m->slot->sprite_tower,
    sfSprite_getTexture(tower_m->button_dam->sprite), 1);
    tower_m->slot->range = t->range;
    sfCircleShape_setRadius(tower_m->slot->area, tower_m->slot->range);
    sfCircleShape_setOrigin(tower_m->slot->area,
    (v2){tower_m->slot->range, tower_m->slot->range});
    sfCircleShape_setPosition(tower_m->slot->area, tower_m->slot->pos);
    sfCircleShape_setOutlineColor(tower_m->slot->area, t->color);
    sfCircleShape_setFillColor(tower_m->slot->area, t->f_color);
    g->hud->gold->gold -= t->price;
    update_gold(g);
}

void on_slow_tower(void *data)
{
    s_game *g = (s_game *)data;
    t_tower_menu *tower_m = &g->tower_m;
    t_tower *s = tower_m->t_tower_slow;
    tower_m->slot->tower = s;
    tower_m->slot->is_tower = 1;
    sfSprite_setTexture(tower_m->slot->sprite_tower,
    sfSprite_getTexture(tower_m->button_slow->sprite), 1);
    tower_m->slot->range = s->range;
    sfCircleShape_setRadius(tower_m->slot->area, tower_m->slot->range);
    sfCircleShape_setOrigin(tower_m->slot->area,
    (v2){tower_m->slot->range, tower_m->slot->range});
    sfCircleShape_setPosition(tower_m->slot->area, tower_m->slot->pos);
    sfCircleShape_setOutlineColor(tower_m->slot->area, s->color);
    sfCircleShape_setFillColor(tower_m->slot->area, s->f_color);
    g->hud->gold->gold -= s->price;
    update_gold(g);
}

void on_dot_tower(void *data)
{
    s_game *g = (s_game *)data;
    t_tower_menu *tower_m = &g->tower_m;
    t_tower *d = tower_m->t_tower_dot;
    tower_m->slot->tower = d;
    tower_m->slot->is_tower = 1;
    sfSprite_setTexture(tower_m->slot->sprite_tower,
    sfSprite_getTexture(tower_m->button_dot->sprite), 1);
    tower_m->slot->range = d->range;
    sfCircleShape_setRadius(tower_m->slot->area, tower_m->slot->range);
    sfCircleShape_setOrigin(tower_m->slot->area,
    (v2){tower_m->slot->range, tower_m->slot->range});
    sfCircleShape_setPosition(tower_m->slot->area, tower_m->slot->pos);
    sfCircleShape_setOutlineColor(tower_m->slot->area, d->color);
    sfCircleShape_setFillColor(tower_m->slot->area, d->f_color);
    g->hud->gold->gold -= d->price;
    update_gold(g);
}

void on_freez_tower(void *data)
{
    s_game *g = (s_game *)data;
    t_tower_menu *tower_m = &g->tower_m;
    t_tower *f = tower_m->t_tower_freez;
    tower_m->slot->tower = f;
    tower_m->slot->is_tower = 1;
    sfSprite_setTexture(tower_m->slot->sprite_tower,
    sfSprite_getTexture(tower_m->button_freez->sprite), 1);
    tower_m->slot->range = f->range;
    sfCircleShape_setRadius(tower_m->slot->area, tower_m->slot->range);
    sfCircleShape_setOrigin(tower_m->slot->area,
    (v2){tower_m->slot->range, tower_m->slot->range});
    sfCircleShape_setPosition(tower_m->slot->area, tower_m->slot->pos);
    sfCircleShape_setOutlineColor(tower_m->slot->area, f->color);
    sfCircleShape_setFillColor(tower_m->slot->area, f->f_color);
    g->hud->gold->gold -= f->price;
    update_gold(g);
}

Button *set_tower(t_tower *t, v2 pos)
{
    static int idx = 0;
    char *paths[4] = {
        "sprites/tower-canon.png", "sprites/tower-ice.png",
        "sprites/tower-magic.png", "sprites/tower-tesla.png"};
    void (*p_on_towers[4])(void *) = {
        &on_dam_tower, &on_slow_tower,
        &on_dot_tower, &on_freez_tower};
    ++idx;
    return button_create("", (v2){pos.x + (120 * (idx)), pos.y + 90},
        p_on_towers[idx - 1], paths[idx - 1]);
}