/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "runner.h"

typedef struct level {
    int index_v;
    int index_h;
    int distance;
    char *map;
} level_t;

void init_map(controll_t *s_controll, char *filepath);
void get_coins(controll_t *s_controll, level_t *s_level);
char *get_map(char *filepath);
char *my_strdup(char *str);
void map_conditions(controll_t *s_controll, level_t *s_level, int i);

#endif