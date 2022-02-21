/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** update_towers
*/

#include "defender.h"

void handle_store(obj_t *temp)
{
    char path[] = "assets/textures/bomb.png";
    sfIntRect area;

    area = sfRectangleShape_getTextureRect(temp->body.rect);
    area = handle_bonus(temp, area, temp->body.index.y);
    sfTexture *texture = sfTexture_createFromFile(path, &area);
    sfRectangleShape_setTexture(temp->body.rect, texture, sfFalse);
}

void remove_tots(obj_t *temp, obj_t *opt)
{
    sfVector2f pos, pos_b;
    obj_t *tempo;

    pos = sfRectangleShape_getPosition(temp->body.rect);
    for (tempo = opt->head->next; tempo; tempo = tempo->next) {
        pos_b = sfRectangleShape_getPosition(tempo->body.rect);
        if (pos_b.x > pos.x && pos_b.x < pos.x + 320    \
        && pos_b.x > pos.y && pos_b.y < pos.y + 320) {
            if (tempo->prev) tempo->prev->next = tempo->next;
            if (tempo->next) tempo->next->prev = tempo->prev;
            tempo->stop = 1;
        }
    }
}

void save_tots(obj_t *temp, game_t *gm)
{
    sfVector2f pos, pos_b, size;
    obj_t *bds;

    pos = sfRectangleShape_getPosition(temp->body.rect);
    for (bds = gm->tw->head->next; bds; bds = bds->next) {
        pos_b = sfRectangleShape_getPosition(bds->body.rect);
        if (pos_b.x > pos.x && pos_b.x < pos.x + 320    \
        && pos_b.x > pos.y && pos_b.y < pos.y + 320) {
            size = sfRectangleShape_getSize(bds->health.background);
            size.x -= 2;
            size.y -= 2;
            sfRectangleShape_setSize(bds->health.bar, size);
        }
    }
}

void remove_bonus(obj_t *temp, float bonus, game_t *gm)
{
    int n;

    n = 6;
    if (bonus != 0.0) n = 4;
    if (temp->frame == n) {
        if (n == 6) {
            remove_tots(temp, gm->en);
            remove_tots(temp, gm->tw);
        } else
            save_tots(temp, gm);
        if (temp->prev)
            temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        temp = NULL;
    }
}

void update_towers(vars_t *va, obj_t *tw, game_t *gm)
{
    sfColor colors[3] = { {0, 0, 0, 0}, {255, 0, 0, 0}, {0, 255, 0, 0} };
    sfVector2f mouse_pos = GET_MOUSE_POS(va->window);
    sfVector2f pos;
    obj_t *temp;

    if (!tw) return;
    for (temp = tw->head->next; temp; temp = temp->next) {
        pos = sfRectangleShape_getPosition(temp->body.rect);
        if (temp && temp->body.index.x == 2 && temp->frame_clock        \
        && GET_TIME_EVERY_S(temp->frame_clock, 1, 100000)) {
            handle_store(temp);
            sfClock_restart(temp->frame_clock);
            remove_bonus(temp, temp->body.index.y, gm);
        }
        if (temp && temp->body.rect) {
            set_colors(temp, colors);
            if (CHECK_X(mouse_pos, pos, 0, 64)) check(temp, pos, mouse_pos, gm);
            draw_tower_menu(va, temp);
        }
    }
}
