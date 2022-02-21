/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** init_buttons
*/

#include <stdlib.h>
#include "defender.h"

void calculate_button_positions(menu_t *s_mn, sfFloatRect pos_size[2])
{
    sfVector2f size = { pos_size[0].width, pos_size[0].height };

    s_mn->pos_onclick = malloc(sizeof(sfVector2f) * 3);
    s_mn->pos = malloc(sizeof(sfVector2f) * 3);
    s_mn->size = size;
    for (int i = 1; i >= 0; i--) {
        sfVector2f pos =  { pos_size[i].left, pos_size[i].top };
        s_mn->pos[i] = pos;
        s_mn->pos_onclick[i] = GET_POS_ON_CLICK(pos, s_mn->size, BTN_HOVER);
    }
}

sfTexture **get_textures_for_buttons(void)
{
    sfIntRect btn[2] = { {0, 150, 500, 150}, {0, 0, 500, 150} };
    sfIntRect slider = { 0, 0, 25, 100 };
    sfTexture **txtr;

    txtr = malloc(sizeof(sfTexture *) * 4);
    txtr[0] = sfTexture_createFromFile("assets/textures/buttons.jpg", &btn[0]);
    txtr[1] = sfTexture_createFromFile("assets/textures/buttons.jpg", &btn[1]);
    txtr[2] = sfTexture_createFromFile("assets/textures/buttons.jpg", &btn[0]);
    txtr[3] = sfTexture_createFromFile("assets/textures/menu_ss.png", &slider);
    return (txtr);
}
