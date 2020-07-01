/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** event
*/

#include "my.h"

void sound_random(all_t *all)
{
    if (all->my_int.menu == 0) {
        all->my_int.jump_sound = rand() % 5;
        if (all->my_int.jump_sound == 0)
            sfSound_play(all->sound.heehee);
        if (all->my_int.jump_sound == 1)
            sfSound_play(all->sound.whosbad);
        if (all->my_int.jump_sound == 2)
            sfSound_play(all->sound.da);
        if (all->my_int.jump_sound == 3)
            sfSound_play(all->sound.ouw);
        if (all->my_int.jump_sound == 4)
            sfSound_play(all->sound.shamone);
    }
}

void analyse_event_inside_crouch(all_t *all)
{
    if (all->my_int.crouch != 1)
        sound_random(all);
    all->my_int.crouch = 1;
    if (sfKeyboard_isKeyPressed(sfKeyRight) == 1 && all->my_int.down_throw != 1
        && all->my_int.hit_check != 1 && all->my_int.hit_crouch != 1) {
        all->my_int.hit_crouch = 1, all->my_int.hit_check = 1;
        sound_random(all);
    }
    else if (sfKeyboard_isKeyPressed(sfKeyRight) == 0)
        all->my_int.hit_check = 0;
    if (sfKeyboard_isKeyPressed(sfKeySpace) == 1
        && all->my_int.hit_crouch != 1 && all->my_int.down_throw != 1) {
        sound_random(all);
        all->my_int.down_throw = 1;
        all->my_int.check_throw = 1;
    }
}

void analyse_events_crouch(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) == 1 && all->my_int.jump == 0
        && all->my_int.hit == 0 && all->my_int.up_throw != 1)
        analyse_event_inside_crouch(all);
    else if (sfKeyboard_isKeyPressed(sfKeyDown) == 0) {
        if (all->my_int.crouch == 1) {
        all->my_int.hit_crouch = 0,  all->rect.rect_crouch_hit.width = 150;
        all->my_int.hit = 0, all->rect.rect_crouch_hit.left = 0;
        all->my_int.check_throw = 0;
        if (all->my_int.down_throw == 0)
            all->my_int.crouch = 0, all->my_int.hit_time = 0;
        sfSprite_setTextureRect(all->sprite.crouch_hit,
            all->rect.rect_crouch_hit);
        }
    }
}

void analyse_events_hit(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) == 1
        && all->my_int.crouch == 0 && all->my_int.hit_check != 1 &&
        all->my_int.hit != 1 && all->my_int.up_throw != 1)
        all->my_int.hit = 1, all->my_int.hit_check = 1, sound_random(all);
    else if (sfKeyboard_isKeyPressed(sfKeyRight) == 0)
        all->my_int.hit_check = 0;
    if (sfKeyboard_isKeyPressed(sfKeySpace) == 1 && all->my_int.crouch != 1
        && all->my_int.hit != 1 && all->my_int.up_throw != 1)
        sound_random(all), all->my_int.up_throw = 1, all->my_int.hit_check = 1;
}

void analyse_events(sfEvent event, all_t *all)
{
    while (sfRenderWindow_pollEvent(all->window, &event)) {
        menu_events(event, all);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1
            && all->my_int.speed == 200 && all->my_int.menu == 0)
            all->my_int.speed = 0;
        else if (sfKeyboard_isKeyPressed(sfKeyR) == 1
            && all->my_int.speed == 0 && all->my_int.menu == 0)
            all->my_int.speed = 200;
        if (event.type == sfEvtClosed) sfRenderWindow_close(all->window);
        if (all->my_int.speed != 0 && all->my_int.menu == 0
            && all->my_int.ia == 0) {
            if (sfKeyboard_isKeyPressed(sfKeyUp) == 1 && all->my_int.jump == 0
                && all->my_int.crouch == 0) {
                sound_random(all);
                all->my_int.energy = 30, all->my_int.jump = 1;
                sfClock_restart(all->clock.clock_jump);
            } analyse_events_crouch(all), analyse_events_hit(all);
        }
    }
}