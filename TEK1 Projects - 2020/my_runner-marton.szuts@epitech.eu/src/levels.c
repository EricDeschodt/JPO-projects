/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** levels
*/

#include "runner.h"
#include "map.h"

void init_levels(controll_t *s_controll)
{
    buttons_t *s_button = NULL;
    int x = 880, y = 300;
    char const *file_on[5] = {"sprites/buttons/infinite_on.png",
    "sprites/buttons/level1_on.png", "sprites/buttons/level2_on.png",
    "sprites/buttons/level3_on.png", "sprites/buttons/menu_on.png"};
    char const *file[5] = {"sprites/buttons/infinite.png",
    "sprites/buttons/level1.png", "sprites/buttons/level2.png",
    "sprites/buttons/level3.png", "sprites/buttons/menu.png"};
    for (int i = 0; i < 5; i++) {
        s_button = render_buttons(s_button, file[i], (sfVector2f){x, y}, i);
        s_button->texture_on = sfTexture_createFromFile(file_on[i], NULL);
        y += 100;
    }
    s_controll->s_levels = s_button;
}

void display_levels(controll_t *s_controll)
{
    buttons_t *temp = s_controll->s_levels;
    while (temp != NULL) {
        sfRenderWindow_drawSprite(s_controll->s_game.window,
        temp->sprite, NULL);
        temp = temp->next;
    }
}

void check_levels3(buttons_t *s_button, controll_t *s_controll)
{
    if (s_button->id == 3) {
        if (s_controll->current_map != NULL) free(s_controll->current_map);
        s_controll->current_map = my_strdup("maps/map3");
        s_controll->s_game.scene = 1, s_controll->s_game.speed = 1;
        render_sprites(s_controll, s_controll->current_map);
        s_controll->s_state.lose = 0;
        sfClock_restart(s_controll->s_background.clock);
        s_controll->s_interface.nb_coin_int = 0;
        sfText_setString(s_controll->s_interface.nb_coin, "0");
        s_controll->s_interface.distance_int = 0;
        sfText_setString(s_controll->s_interface.nb_dist, "0");
    }
}

void check_levels2(buttons_t *s_button, controll_t *s_controll)
{
    if (s_button->id == 2) {
        if (s_controll->current_map != NULL) free(s_controll->current_map);
        s_controll->current_map = my_strdup("maps/map2");
        s_controll->s_game.scene = 1, s_controll->s_game.speed = 1;
        render_sprites(s_controll, s_controll->current_map);
        s_controll->s_state.lose = 0;
        sfClock_restart(s_controll->s_background.clock);
        s_controll->s_interface.nb_coin_int = 0;
        sfText_setString(s_controll->s_interface.nb_coin, "0");
        s_controll->s_interface.distance_int = 0;
        sfText_setString(s_controll->s_interface.nb_dist, "0");
    }
}

void check_levels(buttons_t *s_button, controll_t *s_controll)
{
    if (is_button(s_button, s_controll)) {
        check_infinite(s_button, s_controll);
        if (s_button->id == 1) {
            s_controll->s_game.scene = 1, s_controll->s_game.speed = 1;
            if (s_controll->current_map != NULL) free(s_controll->current_map);
            s_controll->current_map = my_strdup("maps/map1");
            render_sprites(s_controll, s_controll->current_map);
            s_controll->s_state.lose = 0;
            s_controll->s_interface.nb_coin_int = 0;
            sfClock_restart(s_controll->s_background.clock);
            sfText_setString(s_controll->s_interface.nb_coin, "0");
            s_controll->s_interface.distance_int = 0;
            sfText_setString(s_controll->s_interface.nb_dist, "0");
        }
        check_levels2(s_button, s_controll);
        check_levels3(s_button, s_controll);
        if (s_button->id == 4)
            s_controll->s_game.scene = 0;
    }
}