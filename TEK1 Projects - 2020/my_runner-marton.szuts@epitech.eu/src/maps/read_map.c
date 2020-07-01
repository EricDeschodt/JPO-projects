/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** read_map
*/

#include "runner.h"
#include "map.h"

int get_file_size(int fd)
{
    char c;
    int i = 0;
    for (; read(fd, &c, 1) == 1; i++);
    return (i);
}

char *get_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int file_size = get_file_size(fd);
    char *map = malloc(file_size + 1);
    close(fd);
    fd = open(filepath, O_RDONLY);
    read(fd, map, file_size);
    map[get_file_size(fd) + 1] = '\0';
    close(fd);
    return (map);
}

void map_conditions(controll_t *s_controll, level_t *s_level, int i)
{
    if (s_level->map[i] == '\n')
        s_level->index_h = 0, s_level->index_v += 1;
    if (s_level->map[i] == '1') {
        s_controll->s_coin = render_coin(s_controll->s_coin, s_level->index_v,
        (s_level->index_h * 25) + s_level->distance);
    }
    if (s_level->map[i] == '2')
        s_controll->s_monster = render_monster(s_controll->s_monster,
        s_level->index_v, (s_level->index_h * 25) + s_level->distance);
    if (s_level->map[i] == 'O')
        s_controll->s_obstacle = render_obstacle(s_controll->s_obstacle,
        s_level->index_v, (s_level->index_h * 25) + s_level->distance);
    s_level->index_h += 1;
    if (s_level->map[i] == 'Z')
        s_level->index_h = 0, s_level->index_v = 0, s_level->distance += 1920;
}

void get_coins(controll_t *s_controll, level_t *s_level)
{
    s_controll->s_monster = NULL, s_controll->s_coin = NULL;
    s_controll->s_obstacle = NULL;
    for (int i = 0; s_level->map[i] != 'E'; i++) {
        map_conditions(s_controll, s_level, i);
    }
    free(s_level->map);
}

void init_map(controll_t *s_controll, char *filepath)
{
    level_t s_level;
    s_level.map = get_map(filepath);
    s_level.index_h = 0, s_level.index_v = 1, s_level.distance = 0;
    get_coins(s_controll, &s_level);
}