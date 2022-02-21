/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** move
*/
#include "../../include/struct.h"
#include "../../include/my.h"

int up(object_t *protagonist, struct_time_t *time,
       int *move, char **map)
{
    int ret = 0;
    if (protagonist->rect.left < 650)
        protagonist->rect.left = 650;
    if (time->seconds >= 0.05) {
        ret = bordure_up(protagonist, move, map);
        if (ret == 2)
            return (1);
        if (ret == 0)
            if (boundaries_up(protagonist, move) == 0)
                protagonist->pos.y -= 15;
        protagonist->rect.left += 65;
        sfClock_restart(time->clock);
    }
    if (protagonist->rect.left >= 1105)
        protagonist->rect.left = 715;
    protagonist->rect.top = 100;
    sfSprite_setTextureRect(protagonist->my_sprite, protagonist->rect);
    sfSprite_setPosition(protagonist->my_sprite, protagonist->pos);
    return (0);
}

void right(object_t *protagonist, struct_time_t *time,
           int *move, char **map)
{
    if (protagonist->rect.left < 585)
        protagonist->rect.left = 585;
    if (time->seconds >= 0.05) {
        if (bordure_right(protagonist, move, map) == 0)
            if (boundaries_right(protagonist, move) == 0)
                protagonist->pos.x += 16;
        protagonist->rect.left += 65;
        sfClock_restart(time->clock);
    }
    if (protagonist->rect.left >= 1170)
        protagonist->rect.left = 650;
    protagonist->rect.top = 0;
    sfSprite_setTextureRect(protagonist->my_sprite, protagonist->rect);
    sfSprite_setPosition(protagonist->my_sprite, protagonist->pos);
}

void down(object_t *protagonist, struct_time_t *time,
          int *move, char **map)
{
    if (protagonist->rect.left > 585)
        protagonist->rect.left = 0;
    if (time->seconds >= 0.05) {
        if (bordure_down(protagonist, move, map) == 0)
            if (boundaries_down(protagonist, move) == 0)
                protagonist->pos.y += 15;
        protagonist->rect.left += 65;
        sfClock_restart(time->clock);
    }
    if (protagonist->rect.left >= 520)
        protagonist->rect.left = 65;
    protagonist->rect.top = 0;
    sfSprite_setTextureRect(protagonist->my_sprite, protagonist->rect);
    sfSprite_setPosition(protagonist->my_sprite, protagonist->pos);
}

void left(object_t *protagonist, struct_time_t *time,
          int *move, char **map)
{
    if (protagonist->rect.left > 650)
        protagonist->rect.left = 0;
    if (time->seconds >= 0.05) {
        if (bordure_left(protagonist, move, map) == 0)
            if (boundaries_left(protagonist, move) == 0)
                protagonist->pos.x -= 16;
        protagonist->rect.left += 65;
        sfClock_restart(time->clock);
    }
    if (protagonist->rect.left >= 585)
        protagonist->rect.left = 65;
    protagonist->rect.top = 100;
    sfSprite_setTextureRect(protagonist->my_sprite, protagonist->rect);
    sfSprite_setPosition(protagonist->my_sprite, protagonist->pos);
}

int move(scene_t *area, int ret, char **map)
{
    if (ret >= 2 || ret <= 5)
        area[5].player->steps++;
    switch (ret) {
    case 2:
        return (up(area[1].objs, area[21].times,
                   area[5].player->map_move, map));
    case 3:
        right(area[1].objs, area[21].times,
              area[5].player->map_move, map);
        break;
    case 4:
        down(area[1].objs, area[21].times,
             area[5].player->map_move, map);
        break;
    case 5:
        left(area[1].objs, area[21].times,
             area[5].player->map_move, map);
        break;
    }
    return (0);
}
