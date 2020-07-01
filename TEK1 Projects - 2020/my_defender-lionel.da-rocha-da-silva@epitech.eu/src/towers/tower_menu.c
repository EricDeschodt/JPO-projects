/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tower_menu.c
*/

#include "defender.h"

void initializer(t_tower_menu *m, v2 pos)
{
    m->coins = sfSprite_create();
    sfSprite_setTexture(m->coins,
    sfTexture_createFromFile("sprites/gold.png", NULL), 1);
    sfSprite_setPosition(m->coins, (v2){(1920 / 1.5f)+20, (1080 / 1.4f)+145});
    m->t_tower_dam = NULL;
    m->t_tower_dot = NULL;
    m->t_tower_freez = NULL;
    m->t_tower_slow = NULL;
    m->price_dam = init_text(), m->price_slow = init_text();
    m->price_dot = init_text(), m->price_freez = init_text();
    m->button_dam = set_tower(create_dam_tower(&m->t_tower_dam), pos);
    m->button_slow = set_tower(create_slow_tower(&m->t_tower_slow), pos);
    m->button_dot = set_tower(create_dot_tower(&m->t_tower_dot), pos);
    m->button_freez = set_tower(create_freez_tower(&m->t_tower_freez), pos);
}

void init_tower_details(t_tower_menu *m)
{
    m->text_atk = init_text();
    m->text_slow = init_text();
    m->text_dot = init_text();
    m->text_freez = init_text();
}

void tower_upgrade_init(t_tower_menu m, v2 pos, s_game *g)
{
    sfSprite_setTexture(m.sprite_bg,
        sfTexture_createFromFile("res/tower_menu.png", NULL), 1);
    sfSprite_setPosition(m.sprite_bg, pos);
    g->b_tower_upgrade = button_create("UPGRADE", (v2){pos.x+400,  pos.y},
    &on_upgrade_tower, NULL);
    g->tower_m = m;
}

void tower_menu_init(s_game *g)
{
    t_tower_menu m;
    v2 pos = (v2){1920 / 1.5f, 1080 / 1.4f};
    v2 p_dam = (v2){pos.x + 90, pos.y + 150};
    v2 p_slow = (v2){pos.x + 210, pos.y + 150};
    v2 p_dot = (v2){pos.x + 333, pos.y + 150};
    v2 p_frez = (v2){pos.x + 453, pos.y + 150};
    initializer(&m, pos);
    init_tower_details(&m);
    m.slot = malloc(sizeof(s_slot));
    m.slot->is_tower = 0;
    m.is_active = sfFalse;
    m.slot_id = -1;
    m.sprite_bg = sfSprite_create();
    m.title = init_text();
    m.sel_tower = NULL;
    put_text(&m.price_dam, to_string(m.t_tower_dam->price), p_dam, 24);
    put_text(&m.price_slow, to_string(m.t_tower_slow->price), p_slow, 24);
    put_text(&m.price_dot, to_string(m.t_tower_dot->price), p_dot, 24);
    put_text(&m.price_freez, to_string(m.t_tower_freez->price), p_frez, 24);
    tower_upgrade_init(m, pos, g);
}

void tower_menu_update(s_game *g)
{
    return;
}