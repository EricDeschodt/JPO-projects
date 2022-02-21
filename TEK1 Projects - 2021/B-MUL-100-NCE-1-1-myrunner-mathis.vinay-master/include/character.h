/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** struct for character
*/
#ifndef BOOTSTRAP_GRAPHIQUE_LOURD_DUCK_H
#define BOOTSTRAP_GRAPHIQUE_LOURD_DUCK_H

#include <stdbool.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "map.h"

typedef struct {
    bool is_jumping;
    float pos;
    sfSprite *sprite;
    sfTexture *texture;
} character_t;

character_t *create_character(char const *filename);
bool change_frame(character_t *chr);
void destroy_character(character_t *chr);
float round_coord(float n);

#endif //BOOTSTRAP_GRAPHIQUE_LOURD_DUCK_H
