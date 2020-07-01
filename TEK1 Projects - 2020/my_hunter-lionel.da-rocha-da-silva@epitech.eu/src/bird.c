/*
** EPITECH PROJECT, 2019
** bird
** File description:
** bird
*/

#include "ducky.h"

void update_best_score(s_show *image)
{
    image->text.best_number = sfText_create();
    sfText_setString(image->text.best_number, image->str);
    sfText_setFont(image->text.best_number, image->text.font);
    sfText_setColor(image->text.best_number, sfBlack);
    sfText_setCharacterSize(image->text.best_number, 40);
}

void read_best_score(s_show *image)
{
    struct stat filestat;
    stat(image->filepath, &filestat);
    int bytes = filestat.st_size;
    int fd = open(image->filepath, O_RDWR);
    image->str = malloc(bytes + 1);
    read(fd, image->str, bytes);
    image->str[bytes] = '\0';
    close(fd);
}

void start_game(s_show *image)
{
    image->duck.time_move = sfClock_restart(image->duck.clock_move);
    image->duck_rev.time_move = sfClock_restart(image->duck_rev.clock_move);
}

void check_bird(sfRenderWindow *window, s_show *image)
{
    if (image->func == 0) {
        sfSprite_setPosition(image->duck.duck.sprite,
        (sfVector2f){image->duck.x, image->duck.y});
        sfRenderWindow_drawSprite(window, image->duck.duck.sprite, NULL);
    }
    if (image->func == 1) {
        sfSprite_setPosition(image->duck_rev.duck.sprite,
        (sfVector2f){image->duck_rev.x, image->duck_rev.y});
        sfRenderWindow_drawSprite(window, image->duck_rev.duck.sprite, NULL);
    }
}

void display_text(sfRenderWindow *window, s_show *image)
{
    sfText_setPosition(image->text.gameover, (sfVector2f){600, 100});
    sfRenderWindow_drawText(window, image->text.gameover, NULL);
    sfText_setPosition(image->text.text, (sfVector2f){820, 250});
    sfRenderWindow_drawText(window, image->text.text, NULL);
    sfText_setPosition(image->text.score, (sfVector2f){1000, 250});
    sfRenderWindow_drawText(window, image->text.score, NULL);
    sfText_setPosition(image->text.best_score, (sfVector2f){730, 300});
    sfRenderWindow_drawText(window, image->text.best_score, NULL);
    sfText_setPosition(image->text.best_number, (sfVector2f){1050, 300});
    sfRenderWindow_drawText(window, image->text.best_number, NULL);
    sfText_setPosition(image->text.restart, (sfVector2f){640, 400});
    sfRenderWindow_drawText(window, image->text.restart, NULL);
    sfText_setPosition(image->text.exit, (sfVector2f){640, 500});
    sfRenderWindow_drawText(window, image->text.exit, NULL);
}
