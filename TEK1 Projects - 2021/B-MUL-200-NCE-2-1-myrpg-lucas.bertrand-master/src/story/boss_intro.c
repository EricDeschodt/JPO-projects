/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** boss_intro
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int boss_transition(sfRenderWindow *window, scene_t *boss)
{
    time_increase(boss[7].times);
    if (boss[1].objs->rect.left == 0) {
        sfSound_pause(boss[2].sounds->sound);
        sfSound_play(boss[4].sounds->sound);
    }
    if (boss[1].objs->rect.left == 5120) {
        sfSleep(sfSeconds(0.2));
        sfRenderWindow_clear(window, sfBlack);
        return (1);
    }
    if (boss[7].times->seconds >= 0.075) {
        boss[1].objs->rect.left += 640;
        sfSprite_setTextureRect(boss[1].objs->my_sprite, boss[1].objs->rect);
        sfClock_restart(boss[7].times->clock);
    }
    return (0);
}

int analyse_events_boss(sfRenderWindow *window, sfEvent event,
                        scene_t *boss, int *i)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (1);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == true)
            return (2);
        else if (my_strcmp(sfText_getString(boss[6].texts->text), "") != 0
                 && sfKeyboard_isKeyPressed(sfKeySpace) == true) {
            i[0]++;
            sfSleep(sfSeconds(0.2));
            return (3);
        }
    }
    return (0);
}

int draw_boss(sfRenderWindow *window, scene_t *boss, char code)
{
    sfEvent event;
    int ret = 0;
    int i = -1;
    sfSound_play(boss[2].sounds->sound);
    while (1) {
        sfRenderWindow_display(window);
        ret = analyse_events_boss(window, event, boss, &i);
         if (ret == 1)
            return (1);
         if (ret == 3)
            boss_dialogue(boss, code, &i);
         if ((ret == 2 || boss[1].objs->rect.left > 0
              || my_strcmp(sfText_getString(boss[6].texts->text), "") == 0) &&
             boss_transition(window, boss) == 1)
            break;
        sfRenderWindow_drawSprite(window, boss[0].objs->my_sprite, NULL);
        sfRenderWindow_drawRectangleShape(window, boss[5].buttons->rect, NULL);
        sfRenderWindow_drawText(window, boss[6].texts->text, NULL);
        sfRenderWindow_drawSprite(window, boss[1].objs->my_sprite, NULL);
    }
    return (0);
}

void destroy_boss(scene_t *boss)
{
    for (int i = 0; i != 2; i++)
        destroy_object(boss[i].objs->my_sprite, boss[i].objs->my_texture);
    for (int i = 2; i != 5; i++)
        destroy_sound(boss[i].sounds->sound, boss[i].sounds->soundbuffer);
    sfRectangleShape_destroy(boss[5].buttons->rect);
    destroy_text(boss[6].texts->text, boss[6].texts->font);
    sfClock_destroy(boss[7].times->clock);
}

int create_boss(sfRenderWindow *window, char code, int left)
{
    scene_t boss[8];
    char *map = "123l";
    sfColor color[4] = {sfRed, sfGreen, sfYellow, sfMagenta};
    boss[0].objs = create_object("sprite/boss_dialogue.png", create_v2f(0, 0),
                                 create_rect_int(0, left, 640, 360), create_v2f(3, 3));
    boss[1].objs = create_object("sprite/transition.png", create_v2f(0, 0),
                                 create_rect_int(0, 0, 640, 360), create_v2f(3, 3));
    boss[2].sounds = create_sound("sound/boss_intro.ogg", sfTrue);
    boss[3].sounds = create_sound("sound/button.ogg", sfFalse);
    boss[4].sounds = create_sound("sound/battle_begin.ogg", sfFalse);
    boss[5].buttons =  init_button(create_v2f(485, 530),
                                   create_v2f(1000, 150));
    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == code)
            boss[6].texts = create_text("...", create_v2f(510, 545), 30, color[i]);
    boss[7].times = create_time();
    if (draw_boss(window, boss, code) == 1) {
        destroy_boss(boss);
        return (1);
    }destroy_boss(boss); 
}
