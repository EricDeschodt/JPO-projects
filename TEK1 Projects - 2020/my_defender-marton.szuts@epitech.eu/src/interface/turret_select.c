/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_select
*/

#include "defender.h"
#include "utils.h"

void get_price(all_t *s_all, t_select_t *new, int id)
{
    new->text = sfText_create();
    sfText_setFont(new->text, s_all->s_game.font);
    switch (id) {
    case 1 :
        sfText_setString(new->text, "48"), new->price = 48;
        break;
    case 2 :
        sfText_setString(new->text, "80"), new->price = 80;
        break;
    case 3 :
        sfText_setString(new->text, "60"), new->price = 60;
        break;
    case 4 :
        sfText_setString(new->text, "80"), new->price = 80;
        break;
    } sfText_setPosition(new->text, (sfVector2f){s_all->s_utils.pos.x,
    s_all->s_utils.pos.y});
    sfText_setCharacterSize(new->text, 20);
}

t_select_t *fill_select(t_select_t *old, all_t *s_all, sfVector2f pos,
                        char *file)
{
    t_select_t *new = malloc(sizeof(t_select_t));
    new->sprite = sfSprite_create(), new->sprite_a = sfSprite_create();
    new->texture =
    sfTexture_createFromFile(file , NULL);
    new->texture_a =
    sfTexture_createFromFile("sprites/zone_g.png", NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTexture(new->sprite_a, new->texture_a, sfTrue);
    sfSprite_setPosition(new->sprite, s_all->s_utils.pos);
    sfSprite_setOrigin(new->sprite_a, (sfVector2f){255, 255});
    new->scale = pos;
    new->pos = s_all->s_utils.pos, new->type = s_all->s_utils.id;
    sfSprite_setScale(new->sprite_a, pos);
    get_price(s_all, new, s_all->s_utils.id);
    new->next = old, new->clicked = 0;
    return (new);
}

void generate_selected_turret(all_t *s_all)
{
    sfVector2f pos = s_all->s_side_menu.pos;
    pos.x += 138, pos.y = 700;
    t_select_t *select = NULL;
    char *tab_f[4] = {"sprites/turret4_select.png", "sprites/turret3_select."
    "png", "sprites/turret2_select.png", "sprites/turret1_select.png"};
    sfVector2f tab_v[4] = {{0.95, 0.95}, {0.75, 0.75}, {2, 2}, {0.95, 0.95}};
    s_all->s_utils.pos = pos, s_all->s_utils.id = 4;
    for (int i = 0; i != 4; i++, s_all->s_utils.id--) {
        select = fill_select(select, s_all, tab_v[i], tab_f[i]);
        pos.x += 122;
    }
    s_all->s_t_select = select;
}

void check_selected_turret_hitbox(all_t *s_all)
{
    t_select_t *temp = s_all->s_t_select;
    while (temp != NULL) {
        if (check_selected_turret(s_all, temp)) {
            sfSprite_setPosition(s_all->s_selected2.sprite, temp->pos);
            sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_selected2.sprite, NULL);
        }
        temp = temp->next;
    }
}

void display_selected_turret(all_t *s_all)
{
    t_select_t *temp = s_all->s_t_select;
    if (s_all->s_selected.type == 'O' && s_all->s_side_menu.draw == 1 &&
    s_all->s_selected.sel != NULL && s_all->s_selected.sel->on != 1) {
        while (temp != NULL) {
            display_targetting_buttons(s_all, s_all->s_targetting);
            sfRenderWindow_drawSprite(s_all->s_game.window,
            temp->sprite, NULL);
            sfRenderWindow_drawText(s_all->s_game.window, temp->text, NULL);
            temp = temp->next;
        }
        if (s_all->s_game.pause == 0)
            check_selected_turret_hitbox(s_all);
        display_clicked_turret(s_all);
    }
}