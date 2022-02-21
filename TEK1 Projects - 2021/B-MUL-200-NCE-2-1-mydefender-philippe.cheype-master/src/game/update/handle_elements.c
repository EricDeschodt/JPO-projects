/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** handle_player_health_bar
*/

#include "defender.h"
#include "elements.h"
#include "my.h"

void handle_player_health_bar(sfRenderWindow *win, game_t *gm)
{
    sfVector2f pos = {520, 320}, size_a = {32, 450};

    sfRectangleShape_setSize(gm->life->bar, gm->life->points);
    sfRectangleShape_setSize(gm->life->background, size_a);
    gm->life_percent = ((100 * gm->life->points.y) / 450);
    gm->life_percent_t = create_text(pos , my_get_str(gm->life_percent),    \
                                                                50, sfBlack);
    sfRenderWindow_drawRectangleShape(win, gm->life->background, NULL);
    sfRenderWindow_drawRectangleShape(win, gm->life->bar, NULL);
    sfRenderWindow_drawText(win, gm->life_percent_t, NULL);
}

void handle_skip_button(sfRenderWindow *win, wave_t *wave)
{
    sfVector2f mouse_pos = GET_MOUSE_POS(win);
    sfVector2f pos = { wave->skip_timer->pos_size.left, \
                        wave->skip_timer->pos_size.top };
    sfVector2f size = { wave->skip_timer->pos_size.width, \
                        wave->skip_timer->pos_size.height };

    if (CHECK_X(mouse_pos, pos, 0, size.x)) {
        if (CHECK_Y(mouse_pos, pos, 0, size.y) && sfMouse_isButtonPressed(0)) {
            wave->skip = 1;
        }
    }
}

int handle_upgrade_tower(obj_t *tw, sfIntRect temp, sfTexture *texture)
{
    char tower_path[] = "assets/textures/towers_ss.png";
    char trap_path[] = "assets/textures/traps_ss.png";

    if (tw->stats.level < 4) {
        (tw->stats.level == 1) ? (temp.left += 64) : (temp.left += 128);
        temp.top = 64 * tw->body.index.y;
        if (tw->body.index.x == 0)
            texture = sfTexture_createFromFile(tower_path, &temp);
        else
            texture = sfTexture_createFromFile(trap_path, &temp);
        sfRectangleShape_setTexture(tw->body.rect, texture, sfFalse);
        tw->stats.level += 1;
        WAIT_FOR_BUTTON_RELEASE;
        return ((tw->body.index.y + 1) * 100);
    }
    return (-1);
}

int handle_hover_buttons(obj_t *tw, sfVector2f m_pos,   \
                            sfVector2f pos, sfColor colors[3])
{
    sfTexture *texture = NULL;
    sfIntRect temp = {0, 0, 64, 64};

    if (CHECK_X(m_pos, pos, 0, 32)) {
        sfRectangleShape_setFillColor(tw->action[0], colors[1]);
        if (sfMouse_isButtonPressed(0)) {
            tw->prev->next = tw->next;
            if (tw->next) tw->next->prev = tw->prev;
            return ((tw->body.index.y + 1) * 50 * -1);
        }
    } else if (CHECK_X(m_pos, pos, 31, 64)) {
        sfRectangleShape_setFillColor(tw->action[1], colors[2]);
        if (sfMouse_isButtonPressed(0)) {
            int v = handle_upgrade_tower(tw, temp, texture);
            if (v != -1) return (v);
        }
    }
    if (sfMouse_isButtonPressed(0)) set_colors(tw, colors);
    return (0);
}

int handle_button(menu_t *p_mn, sfRenderWindow *win)
{
    sfVector2f hover = { BTN_HOVER, BTN_HOVER };
    sfVector2f c = GET_MOUSE_POS(win);
    sfVector2f out =  { 1, 1 };
    int return_code = 1;

    for (int i = 0; i < 3; i++) {
        set_button(p_mn, out, 0, i);
        if ((c.x > p_mn->pos[i].x) && (c.x < p_mn->pos[i].x + 600)   \
        &&  (c.y > p_mn->pos[i].y) && (c.y < p_mn->pos[i].y + 100)) {
            set_button(p_mn, hover, 1, i);
            return_code = (i > 0 ? i + 1 : i);
            if (sfMouse_isButtonPressed(0)) return (return_code);
        }
        return_code = 1;
    }
    return (return_code);
}
