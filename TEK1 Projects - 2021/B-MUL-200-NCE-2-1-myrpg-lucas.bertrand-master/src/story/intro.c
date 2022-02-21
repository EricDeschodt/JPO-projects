/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** intro
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void anim_intro(sfRenderWindow *window, scene_t *intro)
{
    time_increase(intro[4].times);
    if (intro[4].times->seconds > 0.15) {
        intro[0].objs->rect.left += 650;
        sfSprite_setTextureRect(intro[0].objs->my_sprite, intro[0].objs->rect);
        sfClock_restart(intro[4].times->clock);
    }
    if (intro[0].objs->rect.left == 10400)
        sfSleep(sfSeconds(1));
    else if (intro[0].objs->rect.left < 9750)
             sfRenderWindow_drawSprite(window, intro[0].objs->my_sprite, NULL);
}

int analyse_event_intro(sfRenderWindow *window, sfEvent event,
                        scene_t *intro, int *i)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(window);
    
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (1);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == true
            || my_strcmp(sfText_getString(intro[3].texts->text), "") == 0)
            return (2);
        else if (sfKeyboard_isKeyPressed(sfKeySpace) == true) {
            sfSleep(sfSeconds(0.2));
            i[0]++;
            intro_dialogue(intro, i[0]);
        }
    }
    return (0);
}

int draw_intro(sfRenderWindow *window, scene_t *intro)
{
    sfEvent event;
    int ret = 0;
    int i = -1;

    while (1) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        ret = analyse_event_intro(window, event, intro, &i);
        if (ret != 0)
            return (ret);
        if (intro[0].objs->rect.left != 10400)
            anim_intro(window, intro);
        else {
            sfRenderWindow_drawRectangleShape(window, intro[2].buttons->rect, NULL);
            sfRenderWindow_drawText(window, intro[3].texts->text, NULL);
        }
    }
}

void destroy_intro(scene_t *intro)
{
    destroy_object(intro[0].objs->my_sprite, intro[0].objs->my_texture);
    destroy_sound(intro[1].sounds->sound, intro[1].sounds->soundbuffer);
    sfRectangleShape_destroy(intro[2].buttons->rect);
    destroy_text(intro[3].texts->text, intro[3].texts->font);
    sfClock_destroy(intro[4].times->clock);
    destroy_sound(intro[5].sounds->sound, intro[5].sounds->soundbuffer);
}

int create_intro(sfRenderWindow *window)
{
    scene_t intro[6];

    intro[0].objs = create_object("sprite/intro.png", create_v2f(0, 0),
                                  create_rect_int(0, 0, 650, 366), create_v2f(3, 3));
    intro[1].sounds = create_sound("sound/intro.ogg", sfFalse);
    sfSound_play(intro[1].sounds->sound);
    intro[2].buttons = init_button(create_v2f(485, 530),
                                   create_v2f(1000, 150));
    intro[3].texts = create_text("...", create_v2f(520, 550), 30, sfYellow);
    intro[4].times = create_time();
    intro[5].sounds = create_sound("sound/button.ogg", sfFalse);
    if (draw_intro(window, intro) == 1) {
        destroy_intro(intro);
        return (1);
    }
    destroy_intro(intro);
}
