/*
** EPITECH PROJECT, 2020
** game
** File description:
** rpg
*/

#include "../include/include.h"

void init_game(s_game *game, s_sprite *sprite)
{
    game->mode.width = 1920, game->mode.height = 1080,
    game->mode.bitsPerPixel = 32;
    game->window = sfRenderWindow_create(game->mode, "RPG",
    sfResize | sfClose | sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 30);
    init_sprite(sprite);
    game->statment = 0;
    game->inventory = 0;
    game->option = 0;
    game->sound_modif = 20;
    sprite->sprite_souris = sprite_creator("assets/cursor.png");
    sprite->rect_souris = (sfIntRect){0, 0, 40, 40};
    sfSprite_setTextureRect(sprite->sprite_souris, sprite->rect_souris);
}

int stop(s_game *game)
{
    sfMusic_stop(game->Music_game);
    sfMusic_destroy(game->Music_game);
    return (0);
}

int window(s_game *game, s_sprite *sprite)
{
    init_game(game, sprite);
    players *player = init_player();
    init_map(player, game->window, game);
    while (sfRenderWindow_isOpen(game->window)) {
        mouse(game, sprite);
        fight(game, player->mob[player->current_mob], player);
        cine(player, game);
        get_status(player, game);
        while (sfRenderWindow_pollEvent(game->window, &game->event_stat)) {
            check_statment(game, sprite, player);
            poll_event_map(game->window, player, game);
            if (game->event_stat.type == sfEvtClosed)
                sfRenderWindow_close(game->window);
        }
        if (game->statment == 4)  return (stop(game));
        draw(game, sprite, player);
        sfRenderWindow_drawSprite(game->window, sprite->sprite_souris, NULL);
        update(game->window);
    }
    return (0);
}