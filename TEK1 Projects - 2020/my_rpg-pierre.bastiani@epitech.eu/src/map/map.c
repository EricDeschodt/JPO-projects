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

int init_text_map(players *player, int nb_line, char **map,
sfRenderWindow *window)
{
    player->map_text = malloc(sizeof(sfTexture **) * (nb_line + 1));
    for (int y = 0, x; y < nb_line; y++) {
        player->map_text[y] = malloc(sizeof(sfTexture *) *
        (my_strlen(map[y]) + 1));
        for (x = 0; map[y][x] != '\0'; x++, player->current++) {
            player->map_text[y][x] = sfTexture_createFromFile("assets/map.png",
            nb_text(map[y][x]));
        }
        player->map_text[y][x] = NULL;
        draw_charg(player, window);
    }
    player->map_text[nb_line] = NULL;
    player->map_sprit = malloc(sizeof(sfSprite **) * (nb_line + 1));
    player->pos_s = malloc(sizeof(pos **) * (nb_line + 1));
    return (0);
}

void init_sprit_map(players *player, int nb_line, char **map,
sfRenderWindow *window)
{
    for (int y = 0, x; y < nb_line; y++) {
        player->pos_s[y] = malloc(sizeof(pos *) * (my_strlen(map[y]) + 1));
        player->map_sprit[y] = malloc(sizeof(sfSprite *)*(my_strlen(map[y])+1));
        for (x = 0; map[y][x] != '\0'; x++, player->current++) {
            player->pos_s[y][x] = malloc(sizeof(pos) * 2);
            player->map_sprit[y][x] = sfSprite_create();
            sfSprite_setTexture(player->map_sprit[y][x],
            player->map_text[y][x], 0);
            sfSprite_setScale(player->map_sprit[y][x], (sfVector2f){6, 6});
            sfSprite_setPosition(player->map_sprit[y][x], (sfVector2f){y * 96,
            x * 96});
            player->pos_s[y][x]->y = y * 96;
            player->pos_s[y][x]->x = x * 96;
        }
        player->map_sprit[y][x] = NULL;
        player->pos_s[y][x] = NULL;
        draw_charg(player, window);
    }
    player->map_sprit[nb_line] = NULL;
    player->pos_s[nb_line] = NULL;
}

void init_map(players *player, sfRenderWindow *window, s_game *game)
{
    int nb_line = 54;
    player->max = 0;
    player->current = 0;
    int fd = open("assets/map.txt", 0);
    char **map = malloc(sizeof(char *) * (nb_line + 1));
    for (nb_line = 0; (map[nb_line] = get_next_line(fd)) != NULL; nb_line++)
        player->max = player->max + my_strlen(map[nb_line]);
    map[nb_line] = NULL;
    init_text_map(player, nb_line, map, window);
    init_sprit_map(player, nb_line, map, window);
    init_pnj(player);
    init_mob(player);
    init_door(player);
    player->map = map;
    sfMusic_stop(player->loading);
    sfMusic_destroy(player->loading);
    game->Music_game = sfMusic_createFromFile("assets/ambiance.ogg");
    sfMusic_play(game->Music_game);
    sfMusic_setVolume(game->Music_game, game->sound_modif);
    sfMusic_setLoop(game->Music_game, sfTrue);
}

void print_map(sfRenderWindow *window, players *player, s_game *game)
{
    pos *p = pos_player(player);
    for (int y = p->y/96-6; y >= 0 && y < p->y/96+7 &&
    player->pos_s[y] != NULL; y++) {
        for (int x = p->x/96-10; x >= 0 && x < p->x/96+12 &&
        player->pos_s[y][x] != NULL; x++) {
            sfSprite_setPosition(player->map_sprit[y][x], (sfVector2f)
            {player->pos_s[y][x]->x - player->pos_x, player->pos_s[y][x]->y -
            player->pos_y});
            sfRenderWindow_drawSprite(window, player->map_sprit[y][x], NULL);
        }
    }
    print_door(window, player, game);
    for (int i = 0; player->mob[i] != NULL; i++) {
        if (player->mob[i]->state == 2 &&
        sfClock_getElapsedTime(player->mob[i]->clock_attaque).microseconds <
        5000000) {
            sfRenderWindow_drawSprite(window, player->mob[i]->sprit_win, NULL);
            sfRenderWindow_drawText(window, player->mob[i]->txt_win, NULL);
        }
    }
}