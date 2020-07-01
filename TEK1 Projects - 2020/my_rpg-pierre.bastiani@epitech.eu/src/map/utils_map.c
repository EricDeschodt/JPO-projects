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

sfIntRect *get_rect(int left, int top, int hidth, int width)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    rect->left = left;
    rect->top = top;
    rect->height = hidth;
    rect->width = width;
    return (rect);
}

void poll_event_map2(players *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && is_collide_y_dec(player) == 0) {
            player->pos_y = player->pos_y - 16;
            rot_player(player, 0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && is_collide_x_dec(player) == 0) {
            player->pos_x = player->pos_x - 16;
            rot_player(player, 2);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && is_collide_x_inc(player) == 0) {
            player->pos_x = player->pos_x + 16;
            rot_player(player, 3);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && is_collide_y_inc(player) == 0) {
            player->pos_y = player->pos_y + 16;
            rot_player(player, 1);
    }
}

void poll_event_map(sfRenderWindow *window, players *player, s_game *game)
{
    while (sfRenderWindow_pollEvent(window, &player->event)) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
                    game->inventory = (game->inventory == 0)? 1 : 0;
        if (sfClock_getElapsedTime(player->move_player).microseconds > 2000 &&
        player->state != 0){
                poll_event_map2(player);
        }
        if (player->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}