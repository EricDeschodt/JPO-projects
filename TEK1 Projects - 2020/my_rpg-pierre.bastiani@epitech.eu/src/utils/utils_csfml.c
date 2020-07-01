/*
** EPITECH PROJECT, 2020
** print
** File description:
** map
*/

#include "../../include/include.h"
#include "../../include/get_next_line.h"
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Graphics.h>

void update(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

void mouse(s_game *game, s_sprite *sprite)
{
    game->mouse.y = sfMouse_getPositionRenderWindow(game->window).y;
    game->mouse.x = sfMouse_getPositionRenderWindow(game->window).x;
    sfSprite_setPosition(sprite->sprite_souris, game->mouse);
}