/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** event2
*/

#include "my.h"

void count_event1(all_t *all)
{
    all->my_int.shoot = 1;
    all->my_int.shoot_check = 1;
    all->my_int.duck_spawn1 = 1;
    all->my_int.duck_shoot++;
    all->rect.red_duck.width += 20;
    if (all->my_int.choice == 2 || all->my_int.choice == 5
        || all->my_int.choice == 8)
        all->my_int.score_int += 1500;
    if (all->my_int.choice == 1 || all->my_int.choice == 4
        || all->my_int.choice == 7)
        all->my_int.score_int += 500;
    if (all->my_int.choice == 0 || all->my_int.choice == 3
        || all->my_int.choice == 6)
        all->my_int.score_int += 1000;
    all->write.score = my_put_nbr(all->my_int.score_int,
        all->write.score);
    sfText_setString(all->write.text6, all->write.score);
}

void count_event2(all_t *all)
{
    all->my_int.shoot2 = 1;
    all->my_int.shoot_check2 = 1;
    all->my_int.duck_spawn2 = 1;
    all->my_int.duck_shoot++;
    all->rect.red_duck.width += 20;
    if (all->my_int.choice2 == 2 || all->my_int.choice2 == 5
        || all->my_int.choice2 == 8)
        all->my_int.score_int += 1500;
    if (all->my_int.choice2 == 1 || all->my_int.choice2 == 4
        || all->my_int.choice2 == 7)
        all->my_int.score_int += 500;
    if (all->my_int.choice2 == 0 || all->my_int.choice2 == 3
        || all->my_int.choice2 == 6)
        all->my_int.score_int += 1000;
    all->write.score = my_put_nbr(all->my_int.score_int,
        all->write.score);
    sfText_setString(all->write.text6, all->write.score);
}

void menu_select(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) == 1 && all->my_int.main_menu == 1) {
        sfSound_play(all->sound.select);
        if (all->pos.pos_menu_arrow.y != 405)
            all->pos.pos_menu_arrow.y += 65;
        else
            all->pos.pos_menu_arrow.y = 340;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) == 1 && all->my_int.main_menu == 1) {
        sfSound_play(all->sound.select);
        if (all->pos.pos_menu_arrow.y == 405)
            all->pos.pos_menu_arrow.y -= 65;
        else
            all->pos.pos_menu_arrow.y = 405;
    }
}

void pause_start2(all_t *all)
{
    if (all->my_int.main_menu == 1) {
        if (all->pos.pos_menu_arrow.y == 405 && all->my_int.main_menu == 1)
            all->my_int.game_mode = 1;
        else
            all->my_int.game_mode = 0;
    }
    else if (all->my_int.main_menu == 2) {
        all->pos.pos_menu_dog_pause.y = 500;
        if (all->my_int.dog_draw3 != 1)
            sfSound_play(all->sound.menu_select);
    }
    all->my_int.main_menu = 0;
}

void pause_start(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1
        && all->clock.seconds_dog > 2) {
        if (all->my_int.main_menu != 2) {
            all->pos.pos_menu_dog_pause.y = 420;
            sfSound_play(all->sound.menu_select);
        }
        all->my_int.main_menu = 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace) == 1) {
        pause_start2(all);
    }
    menu_select(all);
}