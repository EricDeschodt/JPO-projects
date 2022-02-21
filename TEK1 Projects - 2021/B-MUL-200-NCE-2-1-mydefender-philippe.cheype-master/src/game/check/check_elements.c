/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-mydefender-philippe.cheype
** File description:
** check_elements.c
*/

#include "defender.h"

static sfColor get_color_bt(game_t *gm, sfVector2f m_pos, int *index,  \
                                                                sfColor color)
{
    color.a = 200;
    (*index) = 0;
    if (is_a_forbiden_case(gm, m_pos) == 1) {
        color.r = 255;
        color.g = 0;
        (*index) = 1;
    }
    return (color);
}

void check_tower(vars_t *va, game_t *gm, int i, int j)
{
    sfColor color = sfRectangleShape_getFillColor(gm->it[0]->overlay[i][j]);
    sfVector2f temp = sfRectangleShape_getPosition(gm->it[0]->overlay[i][j]);
    sfVector2f m_pos = GET_MOUSE_POS(va->window);
    int index = 0;

    if (X_OK && Y_OK && i < 8 && j < 5 && gm->it[0]->temp.index.x == 0) {
        color = get_color_bt(gm, m_pos, &index, color);
        sfRectangleShape_setFillColor(gm->it[0]->overlay[i][j], color);
        sfRenderWindow_drawRectangleShape(va->window,   \
                                            gm->it[0]->overlay[i][j], NULL);
        if (sfMouse_isButtonPressed(0) && index == 0) {
            gm->it[0]->info.check.x = 0;
            gm->it[0]->info.check.y = 1;
            add_element(gm, 0);
        }
    } else
        reset_color(color, i, j, gm);
}

void check_bomb(vars_t *va, game_t *gm, int i, int j)
{
    sfColor color = sfRectangleShape_getFillColor(gm->it[0]->overlay[i][j]);
    sfVector2f temp = sfRectangleShape_getPosition(gm->it[0]->overlay[i][j]);
    sfVector2f m_pos = GET_MOUSE_POS(va->window);
    int index = 0;

    if (X_OK && Y_OK && i < 8 && j >= 5 && gm->it[0]->temp.index.x == 1) {
        color = get_color_bt(gm, m_pos, &index, color);
        sfRectangleShape_setFillColor(gm->it[0]->overlay[i][j], color);
        sfRenderWindow_drawRectangleShape(va->window,   \
                                            gm->it[0]->overlay[i][j], NULL);
        if (sfMouse_isButtonPressed(0) && index == 0) {
            gm->it[0]->info.check.x = 0;
            gm->it[0]->info.check.y = 1;
            add_element(gm, 1);
        }
    } else
        reset_color(color, i, j, gm);
}

void check_bonus(vars_t *va, game_t *gm, int i, int j)
{
    sfVector2f m_pos;
    sfVector2f temp;
    sfColor color;
    int index = 0;

    color = sfRectangleShape_getFillColor(gm->it[0]->overlay[i][j]);
    temp = sfRectangleShape_getPosition(gm->it[0]->overlay[i][j]);
    m_pos = GET_MOUSE_POS(va->window);
    if (X_OK && Y_OK && i < 5 && i > 2 && j < 16    \
    && j > 2 && gm->it[0]->temp.index.x == 2) {
        index = create_area_bonus(gm, va, i, j);
        if (sfMouse_isButtonPressed(0) && index == 0) {
            gm->it[0]->info.check.x = 0;
            gm->it[0]->info.check.y = 1;
            add_element(gm, 2);
        }
    } else {
        reset_color(color, i, j, gm);
    }
}
