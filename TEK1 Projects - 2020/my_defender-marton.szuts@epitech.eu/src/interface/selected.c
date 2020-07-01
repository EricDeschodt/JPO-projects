/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** selected
*/

#include "defender.h"
#include "utils.h"

int check_selected(all_t *s_all, support_t *s_support)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x > s_support->pos.x &&
        mouse_pos.x < s_support->pos.x + 120)
        && (mouse_pos.y > s_support->pos.y &&
        mouse_pos.y < s_support->pos.y + 120)) {
            return (1);
        }
    return (0);
}

void check_support_hitbox(all_t *s_all)
{
    support_t *temp;
    if (s_all->s_game.scene == 1) temp = s_all->s_map.s_support;
    if (s_all->s_game.scene == 2) temp = s_all->s_map_edit.examples;
    while (temp != NULL) {
        if (check_selected(s_all, temp) && (s_all->s_game.pause == 0 ||
        s_all->s_game.scene == 2)) {
            s_all->s_selected.pos = temp->pos;
            sfSprite_setPosition(s_all->s_selected.sprite,
            s_all->s_selected.pos);
            sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_selected.sprite, NULL);
        }
        temp = temp->next;
    }
}

void change_texture_menu(all_t *s_all)
{
    if (s_all->s_selected.type == 'O') {
        if (s_all->s_selected.sel->on != 1) {
            sfSprite_setTexture(s_all->s_side_menu.sprite,
                s_all->s_side_menu.texture2, sfTrue);
        } else {
            sfSprite_setTexture(s_all->s_side_menu.sprite,
            s_all->s_side_menu.texture3, sfTrue);
        }
    }
    else sfSprite_setTexture(s_all->s_side_menu.sprite,
        s_all->s_side_menu.texture, sfTrue);
}

int click_support_loop(all_t *s_all, support_t *temp)
{
    if (check_selected(s_all, temp) &&
    (!check_side_menu(s_all) || s_all->s_side_menu.draw == 0)) {
        s_all->s_selected.type = temp->type, s_all->s_side_menu.slide = 1;
        s_all->s_selected.sel = temp;
        change_texture_menu(s_all), s_all->s_side_menu.draw = 1;
        s_all->s_selected.on = 1, s_all->s_selected.pos2 = temp->pos;
        sfSprite_setPosition(s_all->s_selected.clicked_s, temp->pos);
        s_all->s_selected.tur = get_turret(s_all);
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
        return (1);
    } else if (my_brick(s_all)) {
            s_all->s_selected.on = s_all->s_selected.on == 1 ? 1 : 0;
            s_all->s_side_menu.draw = s_all->s_side_menu.draw == 1 ? 1 : 0;
        } else {
            s_all->s_selected.on = 0, s_all->s_side_menu.draw = 0;
            s_all->s_selected.type = ' ', s_all->s_selected.tur = NULL;
        } return (0);
}

void click_support(all_t *s_all)
{
    support_t *temp;
    if (s_all->s_game.scene == 1) temp = s_all->s_map.s_support;
    if (s_all->s_game.scene == 2) temp = s_all->s_map_edit.head;
    while (temp != NULL) {
        if (click_support_loop(s_all, temp) == 1)
            return;
        temp = temp->next;
    }
}