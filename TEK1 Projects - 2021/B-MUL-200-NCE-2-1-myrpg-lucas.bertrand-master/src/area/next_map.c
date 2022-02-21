/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** next_map
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int init_boss_fight(sfRenderWindow *window, scene_t *area, char next_code)
{
    int pos[2] = {0, 0};
    char *code = "123l";

    for (int i = 0; i != 4; i++)
        if (next_code == code[i]) {
            pos[0] = i * 400;
            pos[1] = i * 100;
            if (create_boss(window, code[i], 640 * i) == 1
                || create_boss_fight_one(window, pos, i + 1, area[5].player) == 1
                || code[i] != 'l' && create_after_boss(window, code[i], 640 * i) == 1
                || code[i] == 'l' &&
                (create_before_ultimate_boss(window, area[5].player) == 1
                 || create_ending(window) == 1 || end(window) == 1))
                return (1);
        }
}

void modif_save_boss(sfRenderWindow *window, scene_t *area,
                     char **map, char next_code)
{
    char *code = "23l";
    int pos_x[3] = {1256, 1188, 912};
    int pos_y[3] = {511, 511, 400};
    int move_x[3] = {-3580, -3664, -1248};
    int move_y[3] = {-2484, -2699, -3025};

    for (int i = 0; i != 3; i++)
        if (next_code == code[i]) {
            area[5].player->pos_x = pos_x[i];
            area[5].player->pos_y = pos_y[i];
            area[5].player->map_move[0] = move_x[i];
            area[5].player->map_move[1] = move_y[i];
            save(area[5].player, map, next_code);
            open_save(window);
        }
}

void next_map_boss(sfRenderWindow *window, scene_t *area,
                   char code, char **map)
{
    char next_code[4] = "123l";

    sfSound_pause(area[6].sounds->sound);
    for (int i = 0; i != 4; i++)
        if (next_code[i] == code)
            modif_save_boss(window, area, map, next_code[i + 1]);
}

int modif_save(sfRenderWindow *window, scene_t *area,
                int i, char **map)
{
    char next_code[5] = "f123l";
    if (i == 0) {
        area[5].player->pos_x = 520;
        area[5].player->pos_y = 492;
        area[5].player->map_move[0] = -288;
        area[5].player->map_move[1] = -2389;
        save(area[5].player, map, '1');
        open_save(window);
        return (1);
    }
    else {
        if (init_boss_fight(window, area, next_code[i]) == 1)
            return (1);
        else
            next_map_boss(window, area, next_code[i], map);
        return (1);
    }
    return (0);
}

int next_map(sfRenderWindow *window, scene_t *area, char code, char **map)
{
    char next_code[5] = "f123l";

    sfSound_pause(area[6].sounds->sound);
    for (int i = 0; i != 5; i++)
        if (next_code[i] == code)
            return (modif_save(window, area, i, map));
}
