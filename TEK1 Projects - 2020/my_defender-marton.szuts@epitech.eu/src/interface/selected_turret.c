/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** selected_turret
*/

#include "utils.h"
#include "defender.h"

void reset_click_list(all_t *s_all, t_select_t *temp)
{
    t_select_t *temp2 = s_all->s_t_select;
    while (temp2 != NULL) {
        if (temp2 != temp)
            temp2->clicked = 0;
        temp2 = temp2->next;
    }
}

int check_hitbox_arrows(all_t *s_all)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if (((mouse_pos.x >= 1665 && mouse_pos.x <= 1692) && (mouse_pos.y >= 419
    && mouse_pos.y <= 454)) || ((mouse_pos.x >= 1868 && mouse_pos.x <= 1893)
    && (mouse_pos.y >= 417 && mouse_pos.y <= 455)))
        return (1);
    return (0);
}

void click_selected_turret(all_t *s_all)
{
    t_select_t *temp = s_all->s_t_select;
    while (temp != NULL) {
        if (check_selected_turret(s_all, temp) &&
        s_all->s_side_menu.draw == 1 && s_all->s_selected.type == 'O' &&
        s_all->s_selected.sel->on != 1) {
            button_sound(s_all);
            sfSprite_setPosition(temp->sprite_a, (sfVector2f){s_all->s_selected
            .pos2.x + 60, s_all->s_selected.pos2.y + 60});
            sfSprite_setPosition(s_all->s_selected2.clicked_s, temp->pos);
            s_all->s_selected2.zone = temp;
            s_all->s_selected2.click = 1, temp->clicked = 1;
            break;
        }
        else if (check_pause_button(s_all) || check_side_menu(s_all)) {
            s_all->s_selected2.click = s_all->s_selected2.click == 1 ? 1 : 0;
            temp->clicked = temp->clicked == 1 ? 1 : 0;
        } else {
            s_all->s_selected2.click = 0, temp->clicked = 0;
        } temp = temp->next;
    } reset_click_list(s_all, temp);
}

void display_clicked_turret(all_t *s_all)
{
    t_select_t *temp = s_all->s_t_select;
    if (s_all->s_selected2.click == 1) {
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_selected2.clicked_s, NULL);
        while (temp != NULL) {
            sfRenderWindow_drawText(s_all->s_game.window, temp->text, NULL);
            temp = temp->next;
        }
    }
}