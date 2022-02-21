/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** anim_ending
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void player(scene_t *ending)
{
    if (ending[0].objs->rect.left == 2260)
        ending[0].objs->rect.left = 0;
    if (ending[9].times->seconds >= 0.5) {
        ending[0].objs->rect.left += 1130;
        sfClock_restart(ending[9].times->clock);
    }
    sfSprite_setTextureRect(ending[0].objs->my_sprite, ending[0].objs->rect);
}

int light(scene_t *ending)
{
    if (ending[0].objs->rect.left == 2260
        && ending[0].objs->rect.top == 5088
        && ending[9].times->seconds >= 0.5)
        return (1);
    else if (ending[0].objs->rect.top == 0) {
        ending[0].objs->rect.top = 636;
        ending[0].objs->rect.left = 0;
    }
    if ((ending[0].objs->rect.top <= 4452 &&
         ending[9].times->seconds >= 0.065)
        || ending[9].times->seconds >= 0.75) {
        if (ending[0].objs->rect.left == 2260) {
            ending[0].objs->rect.left = 0;
            ending[0].objs->rect.top += 636;
        }
        else
            ending[0].objs->rect.left += 1130;
        sfClock_restart(ending[9].times->clock);
    }sfSprite_setTextureRect(ending[0].objs->my_sprite, ending[0].objs->rect);
    return (0);
}

void last_attack(scene_t *ending)
{
    if (ending[1].objs->rect.left == 7680)
        ending[1].objs->rect.left = 3840;
    if (ending[10].times->seconds >= 0.065) {
        ending[1].objs->rect.left += 640;
        sfClock_restart(ending[10].times->clock);
    }
    sfSprite_setTextureRect(ending[1].objs->my_sprite, ending[1].objs->rect);
}

void last_surprise(scene_t *ending)
{
    if (ending[1].objs->rect.top == 0) {
        ending[1].objs->rect.top = 360;
        ending[1].objs->rect.left = 0;
    }
    else if (ending[1].objs->rect.left == 6400)
        ending[1].objs->rect.left = 3200;
    if (ending[10].times->seconds >= 0.065) {
        ending[1].objs->rect.left += 640;
        sfClock_restart(ending[10].times->clock);
    }
    sfSprite_setTextureRect(ending[1].objs->my_sprite, ending[1].objs->rect);    
}

void draw_ending_two(sfRenderWindow *window, scene_t *ending, int i)
{
    if (i < 3)
        last_attack(ending);
    else
        last_surprise(ending);
    sfRenderWindow_drawSprite(window, ending[1].objs->my_sprite, NULL);
    if (i != 19) {
        sfRenderWindow_drawRectangleShape(window, ending[5].buttons->rect, NULL);
        sfRenderWindow_drawText(window, ending[7].texts->text, NULL);
    }
    else if (ending[0].objs->rect.top == 0) {
        sfRenderWindow_drawRectangleShape(window, ending[6].buttons->rect, NULL);
        sfRenderWindow_drawText(window, ending[8].texts->text, NULL);
    }
    sfRenderWindow_drawSprite(window, ending[0].objs->my_sprite, NULL);
}
