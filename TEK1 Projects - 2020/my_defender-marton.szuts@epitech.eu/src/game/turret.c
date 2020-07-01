/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret
*/

#include "defender.h"
#include "utils.h"

void get_turret_textures(int id, turret_t *new)
{
    switch (id) {
    case 1 :
        new->texture =
        sfTexture_createFromFile("sprites/turret1_base.png", NULL);
        break;
    case 2 :
        new->texture =
        sfTexture_createFromFile("sprites/turret2_base.png", NULL);
        break;
    case 3 :
        new->texture =
        sfTexture_createFromFile("sprites/turret3_base.png", NULL);
        sfText_setString(new->name, "BIG BERTHA");
        break;
    case 4 :
        new->texture =
        sfTexture_createFromFile("sprites/turret4_base.png", NULL);
        sfText_setString(new->name, "FROZEN");
        break;
    }
}

void get_canon_textures(int id, turret_t *new)
{
    switch (id) {
    case 1 :
        new->texture_c =
        sfTexture_createFromFile("sprites/turret1_canon.png", NULL);
        sfText_setString(new->name, "BASIC");
        break;
    case 2 :
        new->texture_c =
        sfTexture_createFromFile("sprites/turret2_canon.png", NULL);
        sfText_setString(new->name, "SNIPER");
        break;
    case 3 :
        new->texture_c =
        sfTexture_createFromFile("sprites/turret3_canon.png", NULL);
        break;
    case 4 :
        new->texture_c =
        sfTexture_createFromFile("sprites/turret4_canon.png", NULL);
        break;
    }
}

turret_t *fill_turret(turret_t *old, sfVector2f pos, int id, all_t *s_all)
{
    turret_t *new = malloc(sizeof(turret_t));
    new->sprite = sfSprite_create(), new->sprite_c = sfSprite_create();
    new->bullet = sfSprite_create(), new->type = id, new->pos = pos;
    new->name = sfText_create(), new->pos_xp = (sfVector2f){1450, 55};
    get_turret_textures(id, new), get_canon_textures(id, new);
    new->clock = sfClock_create(), new->next = old, new->rotate = 0;
    load_turret(new, pos), get_turret_type(new, s_all);
    sfSprite_setRotation(new->sprite_c, new->rotate);
    turret_list_targetting(new, s_all), new->locked = NULL, new->draw_stat = 1,
    new->xp = 0, sfText_setPosition(new->name, (sfVector2f)
    {s_all->s_info_text.pos_title.x, s_all->s_info_text.pos_title.y - 20});
    sfText_setFont(new->name, s_all->s_game.font);
    fill_turret_xp(new);
    new->abilities = init_abilities(s_all, id);
    return (new);
}

void place_turret(all_t *s_all)
{
    t_select_t *temp = s_all->s_t_select;
    while (temp != NULL) {
        if (check_selected_turret(s_all, temp) &&
        s_all->s_selected2.click == 1 && temp->clicked == 1 &&
        s_all->s_selected.sel->on != 1 && s_all->s_selected.sel->type == 'O' &&
        temp->price <= s_all->s_player.money) {
            if (s_all->s_settings->sound == 1)
                sfSound_play(s_all->s_sounds.build);
            s_all->s_stats.built += 1, s_all->s_player.money -= temp->price;
            s_all->s_turret = fill_turret(s_all->s_turret,
            s_all->s_selected.pos2, temp->type, s_all);
            get_turret_zone(s_all, temp), s_all->s_selected.sel->on = 1,
            s_all->s_selected.tur = s_all->s_turret;
            sfSprite_setTexture(s_all->s_side_menu.sprite,
            s_all->s_side_menu.texture3, sfTrue);
            s_all->s_player.strmoney = strnbr(s_all->s_player.money);
            sfText_setString(s_all->s_player.txt_money,
            s_all->s_player.strmoney);
        } temp = temp->next;
    }
}

void display_turret(all_t *s_all)
{
    turret_t *temp = s_all->s_turret;
    rotate_turret_maths(s_all);
    while (temp != NULL) {
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
        if (s_all->s_settings->shaders == 1) {
            sfRenderWindow_drawSprite(s_all->s_game.window,
                temp->sprite, &s_all->s_game.state);
        }
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->bullet, NULL);
        if (s_all->s_settings->shaders == 1) {
            sfRenderWindow_drawSprite(s_all->s_game.window,
                temp->bullet, &s_all->s_game.state);
        }
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite_c, NULL);
        temp = temp->next;
    }
}