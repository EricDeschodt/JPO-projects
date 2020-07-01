/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** button_init
*/

#include "defender.h"

void button_tab_init(char **tab)
{
    tab[0] = "sprites/buttons/continue.png";
    tab[1] = "sprites/buttons/new_game.png";
    tab[2] = "sprites/buttons/custom_maps.png";
    tab[3] = "sprites/buttons/statistics.png";
    tab[4] = "sprites/buttons/settings.png";
    tab[5] = "sprites/buttons/handbook.png";
    tab[6] = "sprites/buttons/about.png";
    tab[7] = "sprites/buttons/quit.png";
    tab[8] = "sprites/buttons/continue.png";
    tab[9] = "sprites/buttons/restart.png";
    tab[10] = "sprites/buttons/end_game.png";
    tab[11] = "sprites/buttons/main_menu.png";
}

void button_tab2_init(char **tab2)
{
    tab2[0] = "sprites/buttons/continue2.png";
    tab2[1] = "sprites/buttons/new_game2.png";
    tab2[2] = "sprites/buttons/custom_maps2.png";
    tab2[3] = "sprites/buttons/statistics2.png";
    tab2[4] = "sprites/buttons/settings2.png";
    tab2[5] = "sprites/buttons/handbook2.png";
    tab2[6] = "sprites/buttons/about2.png";
    tab2[7] = "sprites/buttons/quit2.png";
    tab2[8] = "sprites/buttons/continue2.png";
    tab2[9] = "sprites/buttons/restart2.png";
    tab2[10] = "sprites/buttons/end_game2.png";
    tab2[11] = "sprites/buttons/main_menu2.png";
}

int check_pause_button(all_t *s_all)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= s_all->s_hard_buttons.pos.x
    && mouse_pos.x <= s_all->s_hard_buttons.pos.x + 85)
    && (mouse_pos.y >= s_all->s_hard_buttons.pos.y
    && mouse_pos.y <= s_all->s_hard_buttons.pos.y + 85))
        return (1);
    return (0);
}