/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ultimate_boss
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int fight_begin(sfRenderWindow *window, scene_t *boss)
{
    time_increase(boss[5].times);
    if (boss[0].objs->rect.left == 13440)
        return (1);
    if (boss[0].objs->rect.left >= 3200
        && boss[5].times->seconds >= 0.1) {
        boss[0].objs->rect.left += 640;
        sfSprite_setTextureRect(boss[0].objs->my_sprite, boss[0].objs->rect);
        sfClock_restart(boss[5].times->clock);
    }
    return (0);
}

int analyse_events_before_ultimate_boss(sfRenderWindow *window, sfEvent event,
                                        scene_t *boss, int *i)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (1);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == true
            && boss[0].objs->rect.left < 3200) {
            boss[0].objs->rect.left = 3200;
            sfSprite_setTextureRect(boss[0].objs->my_sprite, boss[0].objs->rect);
        }else if (my_strcmp(sfText_getString(boss[4].texts->text), "") != 0
                 && sfKeyboard_isKeyPressed(sfKeySpace) == true) {
            i[0]++;
            sfSleep(sfSeconds(0.2));
            boss[0].objs->rect.left += 640;
            sfSprite_setTextureRect(boss[0].objs->my_sprite, boss[0].objs->rect);
            sfText_setString(boss[4].texts->text, before_ultimate_boss(i[0]));
            sfSound_play(boss[2].sounds->sound);
        }
    }
    return (0);
}

int draw_before_ultimate_boss(sfRenderWindow *window, scene_t *boss)
{
    sfEvent event;
    int ret = 0;
    int i = -1;
    while (1) {
        sfRenderWindow_display(window);
        ret = analyse_events_before_ultimate_boss(window, event, boss, &i);
        if (boss[0].objs->rect.left == 3200)
            sfSound_play(boss[1].sounds->sound);
        if (ret == 1)
            return (1);
        if (fight_begin(window, boss) == 1)
            break;
        sfRenderWindow_drawSprite(window, boss[0].objs->my_sprite, NULL);
        if (boss[0].objs->rect.left < 3200) {
            sfRenderWindow_drawRectangleShape(window, boss[3].buttons->rect, NULL);
            sfRenderWindow_drawText(window, boss[4].texts->text, NULL);
        }
    }
    return (0);
}

void destroy_before_ultimate_boss(scene_t *boss)
{
    destroy_object(boss[0].objs->my_sprite, boss[0].objs->my_texture);
    for (int i = 1; i != 3; i++)
        destroy_sound(boss[i].sounds->sound, boss[i].sounds->soundbuffer);
    sfRectangleShape_destroy(boss[3].buttons->rect);
    destroy_text(boss[4].texts->text, boss[4].texts->font);
    sfClock_destroy(boss[5].times->clock);
}

int create_before_ultimate_boss(sfRenderWindow *window, protagonist_t *stat)
{
    scene_t boss[6];
    
    boss[0].objs = create_object("sprite/ultimate_form.png", create_v2f(0, 0),
                                 create_rect_int(0, 0, 640, 360), create_v2f(3, 3));
    boss[1].sounds = create_sound("sound/ultimate_battle.ogg", sfTrue);
    boss[2].sounds = create_sound("sound/button.ogg", sfFalse);
    boss[3].buttons =  init_button(create_v2f(485, 830),
                                   create_v2f(1000, 150));
    boss[4].texts = create_text("Oh, oh, Beyond Stars...", create_v2f(510, 845), 30, sfWhite);
    boss[5].times = create_time();
    if (draw_before_ultimate_boss(window, boss) == 1
        || create_ultimate_fight_one(window, stat, boss[1].sounds) == 1) {
        destroy_before_ultimate_boss(boss);
        return (1);
    }
    destroy_before_ultimate_boss(boss);
}
