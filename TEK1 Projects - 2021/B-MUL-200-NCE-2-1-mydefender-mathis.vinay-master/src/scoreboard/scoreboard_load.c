/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Load the scoreboard file, and bubble sort it
*/

#include "../../include/scoreboard.h"

void scoreboard_load(scoreboard_t *score, char *path)
{
    char *scorepath = my_strcat(path, "/score.txt");
    if (!my_is_file_valid(scorepath)) return;
    char *ctn = my_get_file_ctn(scorepath);
    sfText_setString(score->board_text->text, ctn);
    free(scorepath);
    free(ctn);
}