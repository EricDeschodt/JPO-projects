/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** a map structure
*/
#ifndef B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_MAP_H
#define B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_MAP_H

#include "graphical_funcs.h"
#include "my.h"

typedef struct {
    char *str;
    char **tab;
    int x;
    float offset;
    int rang;
    sfTexture *texture;
    sfSprite *sprite;
} map_t;

map_t *create_map(char const *filename, const char *textures);
map_t *display_map(sfRenderWindow *win, map_t *map);
void destroy_map(map_t *map);
void *free_null(void *obj);

#endif //B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_MAP_H
