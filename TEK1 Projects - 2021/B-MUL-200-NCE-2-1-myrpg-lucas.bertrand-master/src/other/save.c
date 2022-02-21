/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** save
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void change_map(char **map, char *file)
{
    int fd = open(file, O_RDWR);
    char enter = '\n';

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            write(fd, &map[i][j], 1);
        write(fd, &enter, 1);
    }
    close(fd);
}

void verif_save(sfRenderWindow *window, scene_t *area)
{
    if (my_strcmp(sfText_getString(area[16].texts->text), "") != 0) {
        sfRenderWindow_drawRectangleShape(window, area[13].buttons->rect, NULL);
        sfRenderWindow_drawText(window, area[16].texts->text, NULL);
        if (area[21].times->seconds >= 1.5)
            sfText_setString(area[16].texts->text, "");
    }
}

void map_to_change(char **map)
{
    char *code = "f123l";
    char *file[5] = {"map/field.txt", "map/crypt1.txt", "map/crypt2.txt",
        "map/crypt3.txt", "map/labo.txt"};

    for (int i = 0; code[i] != '\0'; i++)
        if (code[i] == map[0][0])
            change_map(map, file[i]);
}

void convert(protagonist_t *chara, char stat[6][10], char **map)
{
    map_to_change(map);
    int_to_str(stat[0], chara->exp, 4);
    int_to_str(stat[1], chara->pv, 2);
    int_to_str(stat[2], chara->pm, 2);
    int_to_str(stat[3], chara->pos_x, 4);
    int_to_str(stat[4], chara->pos_y, 4);
    if (chara->map_move[0] < 0)
        chara->map_move[0] *= 10;
    if (chara->map_move[1] < 0)
        chara->map_move[1] *= 10;
    int_to_str(stat[5], chara->map_move[0], 5);
    int_to_str(stat[6], chara->map_move[1], 5);
    if (chara->map_move[0] < 0)
        chara->map_move[0] /= 10;
    if (chara->map_move[1] < 0)
        chara->map_move[1] /= 10;
}

void save(protagonist_t *chara, char **map, char code)
{
    int fd = open("save/save.txt", O_RDWR);
    char stat[7][10];
    char space = ' ';
    char back_space = '\r';
    convert(chara, stat, map);
    for (int i = 0; i != 45; i++)
        write(fd, &back_space, 0);
    write(fd, &code, 1);
    for (int i = 0, j = 4; i != 7; i++) {
        write(fd, &space, 1);
        if (i == 1 || i == 2)
            write(fd, stat[i], 2);
        else if (i >= 5)
            write(fd, stat[i], 5);
        else
            write(fd, stat[i], j);
    } write(fd, &space, 1);
    for (int i = 0; i != 10; i++)
        write(fd, &chara->item[i], 1);
    close(fd);
}
