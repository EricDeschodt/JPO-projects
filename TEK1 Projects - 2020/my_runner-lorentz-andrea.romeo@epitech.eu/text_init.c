/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** text_init
*/

#include "my.h"

void write_init2(all_t *all)
{
    all->write.game_over = sfText_create();
    sfText_setFont(all->write.game_over, all->write.font);
    sfText_setString(all->write.game_over, "GAME OVER MICHAEL IS DEAD");
    sfText_setCharacterSize(all->write.game_over, 50);
    sfVector2f message;
    message.x = 660, message.y = 150;
    sfText_setPosition(all->write.game_over, message);
    all->write.victory = sfText_create();
    sfText_setFont(all->write.victory, all->write.font);
    sfText_setString(all->write.victory, "YOU SURVIVED THE THRILLER");
    sfText_setCharacterSize(all->write.victory, 50);
    sfText_setPosition(all->write.victory, message);
}

void write_init(all_t *all)
{
    all->write.skull = malloc(sizeof(char) * 10);
    all->write.font = sfFont_createFromFile("font/leaderson.ttf");
    all->write.text = sfText_create();
    sfText_setFont(all->write.text, all->write.font);
    all->write.top_score = open_read();
    sfText_setString(all->write.text, all->write.top_score);
    sfText_setCharacterSize(all->write.text, 60);
    sfVector2f top_score, skull_score;
    top_score.x = 920, top_score.y = 35;
    sfText_setPosition(all->write.text, top_score);
    all->write.skull_txt = sfText_create();
    sfText_setFont(all->write.skull_txt, all->write.font);
    all->write.skull[0] = '0';
    all->write.skull[1] = '\0';
    sfText_setString(all->write.skull_txt, all->write.skull);
    sfText_setCharacterSize(all->write.skull_txt, 60);
    skull_score.x = 920, skull_score.y = 35;
    sfText_setPosition(all->write.skull_txt, skull_score);
    write_init2(all);
}
