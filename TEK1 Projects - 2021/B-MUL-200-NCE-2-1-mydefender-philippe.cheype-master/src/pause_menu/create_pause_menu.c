/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** init_pause_menu
*/

#include <stdlib.h>
#include "defender.h"

static button_t *init_buttons(void)
{
    char *strings[] = { "", "Resume", "Restart", "Exit" };
    sfFloatRect pos_size = {660, 360, 600, 100};
    sfTexture **textures;
    button_t *buttons;

    textures = get_button_textures(3);
    buttons = create_button_ns(pos_size, strings, textures, 3);
    return (buttons);
}

menu_t *create_pause_menu(void)
{
    menu_t *p_mn;

    p_mn = malloc(sizeof(menu_t));
    p_mn->button = init_buttons();
    return (p_mn);
}
