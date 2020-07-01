/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** menu
*/

#include "runner.h"
#include "map.h"

void render_title(controll_t *s_controll)
{
    s_controll->s_title.texture =
    sfTexture_createFromFile("sprites/buttons/title.png", NULL);
    s_controll->s_title.sprite = sfSprite_create();
    sfSprite_setTexture(s_controll->s_title.sprite,
    s_controll->s_title.texture, sfTrue);
    sfSprite_setPosition(s_controll->s_title.sprite, (sfVector2f){765, 50});
}

int is_button(buttons_t *s_button, controll_t *s_controll)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_controll->s_game.window);
    return (mouse_pos.x > s_button->pos.x &&
    mouse_pos.x < s_button->pos.x + 155)
    && (mouse_pos.y > s_button->pos.y &&
    mouse_pos.y < s_button->pos.y + 42);
}

void check_play(buttons_t *s_button, controll_t *s_controll)
{
    if (is_button(s_button, s_controll)) {
        if (s_button->id == 0) {
            s_controll->s_game.scene = 1, s_controll->s_game.speed = 1;
            s_controll->current_map = my_strdup(s_controll->arg_map);
            render_sprites(s_controll, s_controll->arg_map);
            s_controll->s_state.lose = 0;
            sfClock_restart(s_controll->s_background.clock);
            s_controll->s_interface.nb_coin_int = 0;
            sfText_setString(s_controll->s_interface.nb_coin, "0");
            s_controll->s_interface.distance_int = 0;
            sfText_setString(s_controll->s_interface.nb_dist, "0");
        }
        if (s_button->id == 1)
            s_controll->s_game.scene = 3;
        if (s_button->id == 2)
            sfRenderWindow_close(s_controll->s_game.window);
    }
}

void check_pause(buttons_t *s_button, controll_t *s_controll)
{
    if (is_button(s_button, s_controll)) {
        if (s_button->id == 0 && s_controll->s_game.scene != 4)
            s_controll->s_game.scene = 1, s_controll->s_game.speed = 1;
        restart_button(s_button, s_controll);
        if (s_button->id == 2) {
            set_final_score(s_controll);
            s_controll->s_game.scene = 0;
            s_controll->s_game.infinite = 0;
        }
        if (s_button->id == 3)
            sfRenderWindow_close(s_controll->s_game.window);
    }
}

void button_hitbox(controll_t *s_controll)
{
    buttons_t *temp;
    if (s_controll->s_game.scene == 3) {
        temp = s_controll->s_levels;
        while (temp != NULL)
            check_levels(temp, s_controll), temp = temp->next;
    }
    if (s_controll->s_game.scene == 0) {
        temp = s_controll->s_button;
        while (temp != NULL)
            check_play(temp, s_controll), temp = temp->next;
    }
    if (s_controll->s_game.scene == 2 || s_controll->s_game.scene == 4 ||
    s_controll->s_game.scene == 5) {
        temp = s_controll->s_pause;
        while (temp != NULL)
            check_pause(temp, s_controll), temp = temp->next;
    }
}