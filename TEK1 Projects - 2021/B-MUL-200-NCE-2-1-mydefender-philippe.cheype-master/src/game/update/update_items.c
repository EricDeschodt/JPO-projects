/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** update_items.c
*/

#include "defender.h"

int is_a_forbiden_case(game_t *gm, sfVector2f m_pos)
{
    sfVector2f temp;

    if (gm->it[0]->info.check.y != 1)
        return (0);
    if (!gm->tw->head->next) return (0);
    for (gm->tw = gm->tw->head->next; gm->tw->next; gm->tw = gm->tw->next) {
        temp = sfRectangleShape_getPosition(gm->tw->body.rect);
        if (X_OK && Y_OK)
            return (1);
    }
    return (0);
}

void reset_color(sfColor color, int i, int j, game_t *gm)
{
    if (color.a != 50 || color.g == 0) {
        color.a = 50;
        color.r = 0;
        color.g = 255;
        sfRectangleShape_setFillColor(gm->it[0]->overlay[i][j], color);
    }
}

static void fill_colors(sfRenderWindow *win, game_t *gm,    \
                            sfColor color, sfIntRect temp)
{
    sfColor color_b = {0, 255, 0, 50};

    if (temp.left <= temp.width - 2 || temp.left >= temp.width + 2  \
    || temp.top <= temp.height - 2 || temp.top >= temp.height + 2)
        sfRectangleShape_setFillColor(gm->it[0]->overlay[temp.left][temp.top], \
                                                        color_b);
    else
        sfRectangleShape_setFillColor(gm->it[0]->overlay[temp.left][temp.top], \
                                                                        color);
    sfRenderWindow_drawRectangleShape(win,   \
                                gm->it[0]->overlay[temp.left][temp.top], NULL);
}

int create_area_bonus(game_t *gm, vars_t *va, int i, int j)
{
    sfVector2f m_pos = GET_MOUSE_POS(va->window);
    sfColor color = sfRectangleShape_getFillColor(gm->it[0]->overlay[i][j]);
    color.a = 200;
    int index = 0;

    if (is_a_forbiden_case(gm, m_pos) == 1)
        color.r = 255, color.g = 0, index = 1;
    for (int k = i - 3; k <= i + 3; k++) {
        for (int b = j - 3; b <= j + 3; b++) {
            sfIntRect temp = {k, b, i, j};
            fill_colors(va->window, gm, color, temp);
        }
    }
    return (index);
}

void update_items(sfVector2f m_pos, game_t *gm, vars_t *va)
{
    sfRectangleShape_setPosition(gm->it[0]->temp.rect, m_pos);
    for (int i = 0; gm->it[0]->overlay[i]; i++) {
        for (int j = 0; gm->it[0]->overlay[i][j]; j++) {
            check_tower(va, gm, i, j);
            check_bomb(va, gm, i, j);
            check_bonus(va, gm, i, j);
        }
    }
}
