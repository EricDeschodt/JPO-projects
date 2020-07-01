/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** event
*/

#include "my.h"

void shoot_duck3(sfEvent event, all_t *all)
{
    if ((event.mouseButton.x >= all->pos.pos_duck_bot2.x && event.mouseButton.x
        <= all->pos.pos_duck_bot2.x + 80) && (event.mouseButton.y >=
        all->pos.pos_duck_bot2.y && event.mouseButton.y <=
        all->pos.pos_duck_bot2.y + 70)) {
        all->pos.pos_duck_bot2.y = 460;
        all->pos.pos_duck_bot2.x = 50 + rand() % 700;
        count_event2(all);
    }
}

void shoot_duck2(sfEvent event, all_t *all)
{
    if (all->my_int.game_mode == 1) {
        if ((event.mouseButton.x >= all->pos.pos_duck2.x &&
            event.mouseButton.x <=
            all->pos.pos_duck2.x + 80) && (event.mouseButton.y >= all->pos
            .pos_duck2.y && event.mouseButton.y <= all->pos.pos_duck2.y + 70)) {
            all->pos.pos_duck2.x = -130;
            all->pos.pos_duck2.y = rand() % 350;
            count_event2(all);
        }
        if ((event.mouseButton.x >= all->pos.pos_duck_rev2.x &&
            event.mouseButton.x
            <= all->pos.pos_duck_rev2.x + 80) &&
            (event.mouseButton.y >= all->pos.
            pos_duck_rev2.y && event.mouseButton.y <=
            all->pos.pos_duck_rev2.y + 70)) {
            all->pos.pos_duck_rev2.x = 860;
            all->pos.pos_duck_rev2.y = rand() % 350, count_event2(all);
        }
        shoot_duck3(event, all);
    }
}

void shoot_duck1(sfEvent event, all_t *all)
{
    if ((event.mouseButton.x >= all->pos.pos_duck_bot.x && event.mouseButton.x
        <= all->pos.pos_duck_bot.x + 80) && (event.mouseButton.y >= all->pos
        .pos_duck_bot.y && event.mouseButton.y <=
        all->pos.pos_duck_bot.y + 70)) {
        all->pos.pos_duck_bot.y = 460;
        all->pos.pos_duck_bot.x = 50 + rand() % 700;
        count_event1(all);
    }
}

void shoot_duck(sfEvent event, all_t *all)
{
    if ((event.mouseButton.x >= all->pos.pos_duck.x && event.mouseButton.x <=
    all->pos.pos_duck.x + 80) && (event.mouseButton.y >= all->pos.pos_duck.y &&
    event.mouseButton.y <= all->pos.pos_duck.y + 70)) {
        all->pos.pos_duck.x = -130;
        all->pos.pos_duck.y = rand() % 350;
        count_event1(all);
    }
    if ((event.mouseButton.x >= all->pos.pos_duck_rev.x && event.mouseButton.x
    <= all->pos.pos_duck_rev.x + 80) && (event.mouseButton.y >= all->pos
    .pos_duck_rev.y && event.mouseButton.y <= all->pos.pos_duck_rev.y + 70)) {
        all->pos.pos_duck_rev.x = 860;
        all->pos.pos_duck_rev.y = rand() % 350;
        count_event1(all);
    }
    shoot_duck1(event, all);
}

void analyse_events(sfEvent event, all_t *all)
{
    while (sfRenderWindow_pollEvent(all->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(all->window);
            if (my_atoi(all->write.score) > my_atoi(open_read()))
                open_write(all->write.score);
        }
        if (event.type == sfEvtMouseButtonPressed &&
            all->clock.seconds_dog_jump > 8 && (all->my_int.ammo_left >= 1 ||
            all->my_int.main_menu == 2) && all->my_int.main_menu != 1) {
            sfSound_play(all->sound.shoot);
            if (all->my_int.main_menu != 2) {
                shoot_duck(event, all), all->rect.ammo_rect.width -= 18;
                all->my_int.ammo_left--;
                sfSprite_setTextureRect(all->sprite2.ammo, all->rect.ammo_rect);
                shoot_duck2(event, all);
            }
        }
        pause_start(all);
    }
}
