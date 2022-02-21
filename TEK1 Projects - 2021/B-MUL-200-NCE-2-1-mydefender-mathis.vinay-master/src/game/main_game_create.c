/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** a function to create and initialize the main_game struct
*/

#include "../../include/game/main_game.h"

main_game_t *main_game_create(int volume)
{
    main_game_t *game = malloc(sizeof(main_game_t));
    game->map = NULL;
    game->time = NULL;
    game->enemy_list = NULL;
    game->map_tampon = NULL;
    game->col_max = 0;
    game->row_max = 0;
    game->hp = 100;
    game->gold = 0;
    game->wave = 0;
    game->volume = volume;
    game->t_indic = sprite_create("assets/gui/turret_indicator.png",
    "", false, false);
    game->range_indicator = sprite_create("assets/gui/rayon.png", "C",
    false, true);
    game->texture_list = create_texturelist();
    game->sidebar = sidebar_create();
    return game;
}

void spritesheet_init(main_game_t *game)
{
    char *semitexturepath = my_strcat("assets/maps/spritesheet_", game->map[0]);
    char *texturepath = my_strcat(semitexturepath, ".png");
    free(semitexturepath);
    game->map_tampon = sprite_create(texturepath, "", sfFalse, sfFalse);
    free(texturepath);
    sprite_set_pos(game->map_tampon, 0, 0, (float)((1080.0 / (double)
        (get_len_array(game->map) - 1)) / 256));
    sprite_set_texturerect_size(game->map_tampon, 256, 256);
}

void init_variables(main_game_t *game)
{
    game->time = time_create();
    game->hp = 100;
    game->gold = 1000;
    game->wave = 1;
    game->homogenity = 4.0;
    game->difficulty = 0.0;
    game->nb_enemies = 3;
    game->offset = 4.0;
    game->turret_selected = -1;
}

void main_game_init(main_game_t *game, char *mappath)
{
    main_game_destroy(game, false);
    char *tabpath = my_strcat(mappath, "/tab.txt");
    char *tabctn = my_get_file_ctn(tabpath);
    free(tabpath);
    game->map = tab_create(tabctn);
    free(tabctn);
    game->row_max = get_len_array(game->map);
    game->col_max = get_greater_line(game->map);
    sprite_set_pos(game->t_indic, 0, 0, (float)((1080.0 / (double)
    (get_len_array(game->map) - 1)) / 128));
    sprite_set_texturerect_size(game->t_indic, 256 / 2, 128);
    spritesheet_init(game);
    init_variables(game);
    game->enemy_list = create_enemy_list(game);
    sidebar_init(game->sidebar, game);
    game->sidebar->turrets->selected = -1;
    game->turret_list = malloc(sizeof(turret_t *));
    game->turret_list[0] = NULL;
}
