/*
** EPITECH PROJECT, 2020
** main
** File description:
** rpg
*/

#include "include/include.h"

int main(void)
{
    s_game *game = malloc(sizeof(s_game));
    s_sprite *sprite = malloc(sizeof(s_sprite));
    window(game, sprite);
}