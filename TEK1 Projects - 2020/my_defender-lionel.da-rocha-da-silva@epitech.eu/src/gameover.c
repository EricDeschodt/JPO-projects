/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** gameover
*/

#include "defender.h"

s_go *create_gameover(s_game *game)
{
    char *str = malloc(sizeof(char) * 50);
    str[0] = '\0';
    for (int i = 0; i < 3; i++) {
        my_strcat(str, my_itoa(game->bestscores[i]));
        my_strcat(str, "\n");
    }
    s_go *obj = malloc(sizeof(*obj));
    obj->texture = sfTexture_createFromFile("res/menu-bg.jpg", NULL);
    obj->sprite = sfSprite_create(), obj->gameover = init_text();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->font = sfFont_createFromFile("res/fonts/pondesora.ttf");
    put_text(&obj->gameover, "GAMEOVER", (v2){610, 100}, 100);
    obj->best_scores_t = init_text();
    put_text(&obj->best_scores_t, "BEST SCORES:", (v2){710, 300}, 48);
    obj->best_scores = init_text();
    put_text(&obj->best_scores, str, (v2){910, 400}, 32);
    obj->restart = button_create("RESTART", (v2){920, 700}, &on_menu, NULL);
    obj->quit = button_create("QUIT", (v2){920, 800}, &on_quit, NULL);
    obj->check_score = sfFalse;
    return (obj);
}

void get_scores(s_game *game)
{
    int fd = open("maps/scores.txt", O_RDONLY), i = 0;
    char *s = get_next_line(fd);
    while (s) {
        game->bestscores[i] = my_atoi(s);
        free(s);
        s = get_next_line(fd);
        i++;
    }
    free(s);
    close(fd);
}

void compare_scores(s_game *game)
{
    if (game->score > game->bestscores[0]) {
        game->bestscores[2] = game->bestscores[1];
        game->bestscores[1] = game->bestscores[0];
        game->bestscores[0] = game->score;
        return;
    }
    if (game->score <= game->bestscores[0] &&
    game->score > game->bestscores[1]) {
        game->bestscores[2] = game->bestscores[1];
        game->bestscores[1] = game->score;
        return;
    }
    if (game->score <= game->bestscores[1] &&
    game->score > game->bestscores[2]) {
        game->bestscores[2] = game->score;
        return;
    }
}

void save_score(s_game *game)
{
    int len = my_strlen(game->best);
    int fd = open("maps/scores.txt", O_RDWR);
    write(fd, game->best, len);
    close(fd);
}

void gameover_update(s_game *game)
{
    if (game->gameover->check_score == sfFalse) {
        compare_scores(game);
        for (int i = 0; i < 3; i++) {
            my_strcat(game->best, my_itoa(game->bestscores[i]));
            my_strcat(game->best, "\n");
        }
        sfText_setString(game->gameover->best_scores, game->best);
        save_score(game);
        game->gameover->check_score = sfTrue;
    }
}