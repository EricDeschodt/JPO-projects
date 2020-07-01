/*
** EPITECH PROJECT, 2019
** anims
** File description:
** anims
*/

#include "ducky.h"

void move_dog_rev(s_show *image)
{
    if (image->dog_rev.x > -162) {
        image->dog.time_move = sfClock_restart(image->dog.clock_move);
        image->dog_rev.x -= 0.1 *
        sfTime_asMilliseconds(image->dog_rev.time_move);
    }
    if (image->dog_rev.x <= -162) {
        image->dog_rev.x = 1920;
        image->dog.x = 0;
        image->dog_state = 0;
        image->dog.time_move = sfClock_restart(image->dog.clock_move);
    }
}

void draw_dog_rev(sfRenderWindow *window, s_show *image)
{
    sfRenderWindow_drawSprite(window, image->dog_rev.duck.sprite, NULL);
}

void load_restart_text(s_show *image)
{
    image->text.restart = sfText_create();
    sfText_setString(image->text.restart, "PRESS 'R' TO RESTART");
    sfText_setFont(image->text.restart, image->text.font);
    sfText_setColor(image->text.restart, sfBlack);
    sfText_setCharacterSize(image->text.restart, 50);
}

void save_score(s_show *image)
{
    int fd;
    image->score_size = my_strlen(image->text.number);
    if (my_strcmp(image->str, image->text.number) < 0) {
        fd = open(image->filepath, O_RDWR);
        write(fd, image->text.number, image->score_size);
        close(fd);
    }
}

void load_best_score(s_show *image)
{
    image->text.best_score = sfText_create();
    sfText_setString(image->text.best_score, "BEST SCORE: ");
    sfText_setFont(image->text.best_score, image->text.font);
    sfText_setColor(image->text.best_score, sfBlack);
    sfText_setCharacterSize(image->text.best_score, 40);
}
