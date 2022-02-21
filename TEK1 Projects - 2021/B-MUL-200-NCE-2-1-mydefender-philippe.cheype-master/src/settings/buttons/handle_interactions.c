/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** check_mouse_pos
*/

#include "defender.h"

int handle_interactions(vars_t *va, menu_t *s_mn, menu_t *mn)
{
    sfVector2f c = GET_MOUSE_POS(va->window);
    sfVector2f hover = { BTN_HOVER, BTN_HOVER };
    sfVector2f out =   { 1, 1 };
    int check_return = -1;

    for (int i = 0; i < 4; i++) {
        set_element_state(s_mn, out, s_mn->pos[i], i);
        if ((c.x > s_mn->pos[i].x) && (c.x < s_mn->pos[i].x + 600)   \
        &&  (c.y > s_mn->pos[i].y) && (c.y < s_mn->pos[i].y + 100)) {
            set_element_state(s_mn, hover, s_mn->pos_onclick[i], i);
            check_if_sound_interacted(s_mn, mn, i, c);
            if (sfMouse_isButtonPressed(0)) return (i - 1);
        }
    }
    return (check_return);
}
