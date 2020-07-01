/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** pause
*/

#include "runner.h"

void init_pause(controll_t *s_controll)
{
    buttons_t *s_pause = NULL;
    int x = 880, y = 200;
    char const *file[4] = {"sprites/buttons/resume_button.png",
    "sprites/buttons/restart.png",
    "sprites/buttons/menu.png", "sprites/buttons/quit_button.png"};
    char const *file_on[4] = {"sprites/buttons/resume_on.png",
    "sprites/buttons/restart_on.png",
    "sprites/buttons/menu_on.png", "sprites/buttons/quit_on.png"};
    for (int i = 0; i < 4; i++) {
        s_pause = render_buttons(s_pause, file[i], (sfVector2f){x, y}, i);
        s_pause->texture_on = sfTexture_createFromFile(file_on[i], NULL);
        y += 100;
    }
    s_controll->s_pause = s_pause;
}

void display_pause(controll_t *s_controll)
{
    buttons_t *temp = s_controll->s_pause;
    while (temp != NULL) {
        sfRenderWindow_drawSprite(s_controll->s_game.window,
        temp->sprite, NULL);
        temp = temp->next;
    }
}