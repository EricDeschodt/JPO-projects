/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** statistics
*/

#include "defender.h"
#include "utils.h"

void load_statistics(all_t *s_all)
{
    int fd = open("statistics/stats", O_RDONLY);
    if (fd < 0)
        return;
    char *str = get_next_line(fd);
    for (int i = 0; str != NULL; str = get_next_line(fd), i++) {
        if (i == 0) s_all->s_stats.coins = my_atoi(str);
        if (i == 1) s_all->s_stats.killed = my_atoi(str);
        if (i == 2) s_all->s_stats.passed = my_atoi(str);
        if (i == 3) s_all->s_stats.defeated = my_atoi(str);
        if (i == 4) s_all->s_stats.score = my_atoi(str);
        if (i == 5) s_all->s_stats.built = my_atoi(str);
        if (i == 6) s_all->s_stats.sold = my_atoi(str);
        if (i == 7) s_all->s_stats.started = my_atoi(str);
        free(str);
    }
    close(fd);
}

void actualize_stats(all_t *s_all)
{
    s_all->s_stats.score = s_all->s_stats.killed * s_all->s_stats.coins;
    sfText_setString(s_all->s_stats.coins_tx, strnbr(s_all->s_stats.coins));
    sfText_setString(s_all->s_stats.killed_tx, strnbr(s_all->s_stats.killed));
    sfText_setString(s_all->s_stats.passed_tx, strnbr(s_all->s_stats.passed));
    sfText_setString(s_all->s_stats.defeated_tx,
        strnbr(s_all->s_stats.defeated));
    sfText_setString(s_all->s_stats.score_tx, strnbr(s_all->s_stats.score));
    sfText_setString(s_all->s_stats.built_tx, strnbr(s_all->s_stats.built));
    sfText_setString(s_all->s_stats.sold_tx, strnbr(s_all->s_stats.sold));
    sfText_setString(s_all->s_stats.started_tx,
        strnbr(s_all->s_stats.started));
}

void init_stats_text2(all_t *s_all)
{
    sfText_setPosition(s_all->s_stats.coins_tx, (sfVector2f){900, 295});
    sfText_setPosition(s_all->s_stats.killed_tx, (sfVector2f){900, 355});
    sfText_setPosition(s_all->s_stats.passed_tx, (sfVector2f){900, 420});
    sfText_setPosition(s_all->s_stats.defeated_tx, (sfVector2f){900, 485});
    sfText_setPosition(s_all->s_stats.score_tx, (sfVector2f){900, 560});
    sfText_setPosition(s_all->s_stats.built_tx, (sfVector2f){900, 622});
    sfText_setPosition(s_all->s_stats.sold_tx, (sfVector2f){900, 688});
    sfText_setPosition(s_all->s_stats.started_tx, (sfVector2f){900, 750});
    actualize_stats(s_all);
}

void init_stats_text(all_t *s_all)
{
    s_all->s_stats.coins_tx = sfText_create();
    s_all->s_stats.killed_tx = sfText_create();
    s_all->s_stats.passed_tx = sfText_create();
    s_all->s_stats.defeated_tx = sfText_create();
    s_all->s_stats.score_tx = sfText_create();
    s_all->s_stats.built_tx = sfText_create();
    s_all->s_stats.sold_tx = sfText_create();
    s_all->s_stats.started_tx = sfText_create();
    sfText_setFont(s_all->s_stats.coins_tx, s_all->s_game.font);
    sfText_setFont(s_all->s_stats.killed_tx, s_all->s_game.font);
    sfText_setFont(s_all->s_stats.passed_tx, s_all->s_game.font);
    sfText_setFont(s_all->s_stats.defeated_tx, s_all->s_game.font);
    sfText_setFont(s_all->s_stats.score_tx, s_all->s_game.font);
    sfText_setFont(s_all->s_stats.built_tx, s_all->s_game.font);
    sfText_setFont(s_all->s_stats.sold_tx, s_all->s_game.font);
    sfText_setFont(s_all->s_stats.started_tx, s_all->s_game.font);
    init_stats_text2(s_all);
}

void display_statistics(all_t *s_all)
{
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_stats.coins_tx, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_stats.killed_tx, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_stats.passed_tx, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_stats.defeated_tx, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_stats.score_tx, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_stats.built_tx, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_stats.sold_tx, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_stats.started_tx, NULL);
}