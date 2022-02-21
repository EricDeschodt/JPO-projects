/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw_area
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void draw_inventory(sfRenderWindow *window, char *inventory,
                    object_t *item)
{
    if (inventory[0] == ' ')
        return;
    item->pos.y = 270;
    item->pos.x = 745;
    sfSprite_setPosition(item->my_sprite, item->pos);
    for (int i = 0; inventory[i - 1] != ' '; i++) {
        sfRenderWindow_drawSprite(window, item->my_sprite, NULL);
        item->rect.top = (inventory[i] - 48) * 50;
        sfSprite_setTextureRect(item->my_sprite, item->rect);
        sfSprite_setPosition(item->my_sprite, item->pos);
        item->pos.y += 75;
        if (i == 4) {
            item->pos.x = 1110;
            item->pos.y = 270;
        }
    }
}

void draw_pause(sfRenderWindow *window, scene_t *area)
{
    char text[6][10];
    int pv_max = ((area[5].player->lvl - 1) * 10) + 20;
    int pm_max = ((area[5].player->lvl - 1) * 5) + 10;
    sfRenderWindow_drawSprite(window, area[2].objs->my_sprite, NULL);
    int_to_str(text[0], area[5].player->lvl, 2);
    int_to_str(text[1], area[5].player->exp, 4);
    int_to_str(text[2], area[5].player->pv, 2);
    int_to_str(text[3], area[5].player->pm, 2);
    int_to_str(text[4], pv_max, 2);
    int_to_str(text[5], pm_max, 2);
    for (int i = 17, j = 0; i != 21; i++, j++) {
        sfText_setString(area[i].texts->text, text[j]);
        sfRenderWindow_drawText(window, area[i].texts->text, NULL);
    }
    for (int i = 25, j = 4; i != 27; i++, j++)
        sfText_setString(area[i].texts->text, text[j]);
    for (int i = 23; i != 27; i++)
        sfRenderWindow_drawText(window, area[i].texts->text, NULL);
    sfRenderWindow_drawSprite(window, area[22].objs->my_sprite, NULL);
    draw_inventory(window, area[5].player->item, area[3].objs);
}

void draw_tile(sfRenderWindow *window, char **map,
               object_t *tile, int *move)
{
    for (int i = 1; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++)
            if (map[i][j] != ' ') {
                tile->pos.x = j * 192 + move[0];
                tile->pos.y = (i - 1) * 108 + move[1];
                tile->rect.left = (map[i][j] - 48) * 192;
                sfSprite_setPosition(tile->my_sprite, tile->pos);
                sfSprite_setTextureRect(tile->my_sprite, tile->rect);
                sfRenderWindow_drawSprite(window, tile->my_sprite, NULL);
            }
}

int draw_area_two(sfRenderWindow *window, scene_t *area,
                   char **map, int ret)
{
    time_increase(area[21].times);
    if (verif_fight(area, map) != 7 &&
        ret >= 2 && ret <= 5 && area[4].objs->rect.left == 0
        && my_strcmp(sfText_getString(area[16].texts->text), "") == 0
        && my_strcmp(sfText_getString(area[15].texts->text), "") == 0) {
        if (move(area, ret, map) == 1 && next_map(window, area, map[0][0], map) == 1)
            return (1);
        move_update(area[5].player, area[1].objs->pos);
    }
    if (ret == 6) {
        map = chest(area[1].objs, area[5].player->map_move, area, map);
        entry(window, area, map);
    }
    if (area[4].objs->rect.left > 0)
        if (transition(window, area, map) == 1)
            return (1);
    return (0);
}

void draw_area_one(sfRenderWindow *window, scene_t *area, char **map)
{
    sfEvent event;
    int ret = 0;
    while (1) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        if (area[4].objs->rect.left == 0)
            ret = analyse_events_area(window, event, area, map);
        draw_tile(window, map, area[0].objs, area[5].player->map_move);
        if (ret == 1 || draw_area_two(window, area, map, ret) == 1)
            break;
        sfRenderWindow_drawSprite(window, area[1].objs->my_sprite, NULL);
        if (my_strcmp(sfText_getString(area[15].texts->text), "") != 0) {
            sfRenderWindow_drawRectangleShape(window, area[14].buttons->rect, NULL);
            sfRenderWindow_drawText(window, area[15].texts->text, NULL);
        }
        if (area[21].times->pause == true && area[4].objs->rect.left == 0)
            draw_pause(window, area);
        sfRenderWindow_drawSprite(window, area[4].objs->my_sprite, NULL);
        verif_save(window, area);
    }
}
