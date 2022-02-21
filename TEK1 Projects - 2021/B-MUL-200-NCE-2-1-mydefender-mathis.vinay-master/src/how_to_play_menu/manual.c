/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Manual from enemies
*/

#include "../../include/how_to_play.h"

void write_description(manual_t *manual)
{
    manual->e1_t = text_create("Health : 10\t\t\tSpeed : 2", "", sfWhite,
                                false);
    manual->e2_t = text_create("Health : 20\t\t\tSpeed : 3", "", sfWhite,
                                false);
    manual->e3_t = text_create("Health : 50\t\t\tSpeed : 4", "", sfWhite,
                                false);
    manual->e4_t = text_create("Health : 150\t\t\tSpeed : 3", "", sfWhite,
                                false);
    manual->e5_t = text_create("Health : 300\t\t\tSpeed : 1", "", sfWhite,
                                false);
    manual->e6_t = text_create("Health : 500\t\t\tSpeed : 2", "", sfWhite,
                                false);
    text_set_pos(manual->e1_t, 400, 150, 30);
    text_set_pos(manual->e2_t, 400, 310, 30);
    text_set_pos(manual->e3_t, 400, 470, 30);
    text_set_pos(manual->e4_t, 400, 630, 30);
    text_set_pos(manual->e5_t, 400, 790, 30);
    text_set_pos(manual->e6_t, 400, 950, 30);

}

void set_sprites(manual_t *manual)
{
    sprite_set_pos(manual->e1, 300, 160, 1);
    sprite_set_pos(manual->e2, 300, 320, 1);
    sprite_set_pos(manual->e3, 300, 480, 1);
    sprite_set_pos(manual->e4, 300, 640, 1);
    sprite_set_pos(manual->e5, 300, 800, 1);
    sprite_set_pos(manual->e6, 300, 960, 1);
    sprite_set_pos(manual->return_button, 1700, 100, 1);
}

manual_t *manual_create(void)
{
    manual_t *manual = malloc(sizeof(manual_t));
    manual->last_mode = 0;
    manual->return_button = button_create("assets/gui/return_button.png", "C");
    manual->e1 = sprite_create("assets/enemies/weak_enemy.png",
                                "C", false, true);
    manual->e2 = sprite_create("assets/enemies/normal_enemy.png",
                                "C", false, true);
    manual->e3 = sprite_create("assets/enemies/strong_enemy.png",
                                "C", false, true);
    manual->e4 = sprite_create("assets/enemies/hard_enemy.png",
                                "C", false, true);
    manual->e5 = sprite_create("assets/enemies/weak_tank.png",
                                "C", false, true);
    manual->e6 = sprite_create("assets/enemies/strong_tank.png",
                                "C", false, true);
    set_sprites(manual);
    write_description(manual);
    return manual;
}

void manual_display(manual_t *manual, sfRenderWindow *win)
{
    sprite_display(manual->e1, win);
    sprite_display(manual->e2, win);
    sprite_display(manual->e3, win);
    sprite_display(manual->e4, win);
    sprite_display(manual->e5, win);
    sprite_display(manual->e6, win);
    text_display(manual->e1_t, win);
    text_display(manual->e2_t, win);
    text_display(manual->e3_t, win);
    text_display(manual->e4_t, win);
    text_display(manual->e5_t, win);
    text_display(manual->e6_t, win);
    button_display(manual->return_button, win, true);
}

void manual_destroy(manual_t *manual)
{
    sprite_destroy(manual->e1);
    sprite_destroy(manual->e2);
    sprite_destroy(manual->e3);
    sprite_destroy(manual->e4);
    sprite_destroy(manual->e5);
    sprite_destroy(manual->e6);
    text_destroy(manual->e1_t);
    text_destroy(manual->e2_t);
    text_destroy(manual->e3_t);
    text_destroy(manual->e4_t);
    text_destroy(manual->e5_t);
    text_destroy(manual->e6_t);
    sprite_destroy(manual->return_button);
    free(manual);
}