/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** selected2
*/

#include "defender.h"
#include "utils.h"

void init_selected(all_t *s_all)
{
    s_all->s_selected.on = 0;
    s_all->s_selected.sprite = sfSprite_create();
    s_all->s_selected.clicked_s = sfSprite_create();
    s_all->s_selected.texture =
    sfTexture_createFromFile("sprites/selected.png", NULL);
    s_all->s_selected.clicked =
    sfTexture_createFromFile("sprites/clicked.png", NULL);
    sfSprite_setTexture(s_all->s_selected.sprite,
    s_all->s_selected.texture, sfTrue);
    sfSprite_setTexture(s_all->s_selected.clicked_s,
    s_all->s_selected.clicked, sfTrue);
    s_all->s_selected.pos2 = (sfVector2f){0, 0};
    s_all->s_selected.type = ' ';
}

void init_selected_turret(all_t *s_all)
{
    s_all->s_selected2.on = 0;
    s_all->s_selected2.sprite = sfSprite_create();
    s_all->s_selected2.texture =
    sfTexture_createFromFile("sprites/selected2.png", NULL);
    sfSprite_setTexture(s_all->s_selected2.sprite,
    s_all->s_selected2.texture, sfTrue);
    s_all->s_selected2.type = 0, s_all->s_selected2.click = 0;
    sfSprite_setScale(s_all->s_selected2.sprite, (sfVector2f){1.13, 1.13});
    s_all->s_selected2.clicked_s = sfSprite_create();
    s_all->s_selected2.clicked =
    sfTexture_createFromFile("sprites/clicked3.png", NULL);
    sfSprite_setTexture(s_all->s_selected2.clicked_s,
    s_all->s_selected2.clicked, sfTrue);
}

int check_selected_turret(all_t *s_all, t_select_t *s_turret)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x > s_turret->pos.x &&
        mouse_pos.x < s_turret->pos.x + 120)
        && (mouse_pos.y > s_turret->pos.y &&
        mouse_pos.y < s_turret->pos.y + 120)) {
            return (1);
        }
    return (0);
}

int my_brick(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if (((mouse_pos.x >= s_all->s_hard_buttons.pos.x && mouse_pos.x
    <= s_all->s_hard_buttons.pos.x + 85) && (mouse_pos.y >= s_all->
    s_hard_buttons.pos.y && mouse_pos.y <= s_all->s_hard_buttons.pos.y
    + 85)) || ((mouse_pos.x >= s_all->s_side_menu.pos.x + 134 &&
    mouse_pos.x <= s_all->s_side_menu.pos.x + 700) && (mouse_pos.y >=
    s_all->s_side_menu.pos.y && mouse_pos.y <= s_all->s_side_menu.pos.y +
    1080)) || ((mouse_pos.x >= s_all->s_hard_arrow.pos.x - 40
    && mouse_pos.x <= s_all->s_hard_arrow.pos.x + 90)
    && (mouse_pos.y >= s_all->s_hard_arrow.pos.y - 40)
    && (mouse_pos.y <= s_all->s_hard_arrow.pos.y + 140)))
        return (1);
    return (0);
}

int check_side_menu(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= s_all->s_side_menu.pos.x + 134 &&
    mouse_pos.x <= s_all->s_side_menu.pos.x + 700) && (mouse_pos.y >=
    s_all->s_side_menu.pos.y && mouse_pos.y <= s_all->s_side_menu.pos.y +
    1080))
        return (1);
    return (0);
}