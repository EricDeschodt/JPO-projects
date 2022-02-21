/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** after_boss
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int analyse_events_after_boss(sfRenderWindow *window, sfEvent event, int *i)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (1);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == true)
            return (2);
        else if (sfKeyboard_isKeyPressed(sfKeySpace) == true) {
            i[0]++;
            sfSleep(sfSeconds(0.2));
            return (3);
        }
    }
    return (0);
}

int draw_after_boss(sfRenderWindow *window, scene_t *boss, char code)
{
    sfEvent event;
    int ret = 0;
    int i = -1;
    while (1) {
        sfRenderWindow_display(window);
        ret = analyse_events_after_boss(window, event, &i);
         if (ret == 1)
            return (1);
         if (ret == 3)
            after_boss_dialogue(boss, code, &i);
         if (ret == 2 || my_strcmp(sfText_getString(boss[5].texts->text), "") == 0)
             break;
         else
             sfRenderWindow_drawSprite(window, boss[0].objs->my_sprite, NULL);
         sfRenderWindow_drawRectangleShape(window, boss[4].buttons->rect, NULL);
         sfRenderWindow_drawText(window, boss[5].texts->text, NULL);
    }
    return (0);
}

void destroy_after_boss(scene_t *boss)
{
    destroy_object(boss[0].objs->my_sprite, boss[0].objs->my_texture);
    for (int i = 1; i != 4; i++)
        destroy_sound(boss[i].sounds->sound, boss[i].sounds->soundbuffer);
    sfRectangleShape_destroy(boss[4].buttons->rect);
    destroy_text(boss[5].texts->text, boss[5].texts->font);
}

int create_after_boss(sfRenderWindow *window, char code, int left)
{
    scene_t boss[6];
    char *map = "123";
    sfColor color[3] = {sfRed, sfGreen, sfYellow};

    boss[0].objs = create_object("sprite/boss_dialogue.png", create_v2f(0, 0),
                                 create_rect_int(360, left, 640, 360), create_v2f(3, 3));
    boss[1].sounds = create_sound("sound/after_fight.ogg", sfTrue);
    sfSound_play(boss[1].sounds->sound);
    boss[2].sounds = create_sound("sound/button.ogg", sfFalse);
    boss[3].sounds = create_sound("sound/new_power.ogg", sfFalse);
    boss[4].buttons =  init_button(create_v2f(485, 530),
                                   create_v2f(1000, 150));
    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == code)
            boss[5].texts = create_text("...", create_v2f(510, 545), 30, color[i]);
    if (draw_after_boss(window, boss, code) == 1) {
        destroy_after_boss(boss);
        return (1);
    }
    destroy_after_boss(boss); 
}
