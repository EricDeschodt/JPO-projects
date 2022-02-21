/*
** EPITECH PROJECT, 2020
** bootstrap graphique lourd
** File description:
** clocks
*/
#ifndef BOOTSTRAP_GRAPHIQUE_LOURD_CLOCKS_H
#define BOOTSTRAP_GRAPHIQUE_LOURD_CLOCKS_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

typedef struct {
    sfClock *clock;
    long long moove_microseconds;
    long long anime_microseconds;
} _time_t;

_time_t *create_time();

void destroy_time(_time_t *time);

void add_elapsed_time(_time_t *time);

#endif //BOOTSTRAP_GRAPHIQUE_LOURD_CLOCKS_H
