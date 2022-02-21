/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** init_settings_menu
*/

#include <stdlib.h>
#include "defender.h"

menu_t *init_settings_menu(menu_t *mn)
{
    sfFloatRect pos_size[4] = { {180, 500, 600, 100}, {180, 630, 600, 100},  \
    {180, 760, 600, 100}, {180, 890, 600, 100} };
    char *strings[4] =        { "Sound", "How to play", "Credits", "Return"};
    sfTexture **txtr;
    menu_t *s_mn;

    s_mn = malloc(sizeof(menu_t));
    s_mn->music = NULL;
    s_mn->map = mn->map;
    calculate_button_positions(s_mn, pos_size);
    txtr = get_textures_for_buttons();
    s_mn->slide = create_slider(pos_size[0], strings[0], txtr[0], txtr[3]);
    s_mn->button = create_button_ns(pos_size[1], strings, txtr, 3);
    set_slider_sizes(s_mn, mn);
    return (s_mn);
}
