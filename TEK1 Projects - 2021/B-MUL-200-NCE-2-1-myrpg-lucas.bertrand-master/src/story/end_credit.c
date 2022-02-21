/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** end_credit
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int anim_end(scene_t *end)
{
    float sec[5] = {3.5, 2.75, 2, 1.25, 0.75};
    int ret[5] = {11, 10, 9, 8, 7};
    if (end[0].objs->rect.left < 1280 &&
        end[13].times->seconds >= 0.5) {
        end[0].objs->rect.left += 640;
        sfClock_restart(end[13].times->clock);
    }
    if (end[0].objs->rect.left == 1280)
        for (int i = 0; i != 5; i++)
            if (end[13].times->seconds > sec[i])
                return (ret[i]);
    sfSprite_setTextureRect(end[0].objs->my_sprite, end[0].objs->rect);
    return (6);
}

void end_credit(scene_t *end)
{   
    end[5].texts = create_text("BEYOND STARS", create_v2f(600, 50), 200, sfBlack);
    end[6].texts = create_text("Romaric Moy", create_v2f(775, 300), 60, sfCyan);
    end[7].texts = create_text("Faustine Thery", create_v2f(725, 400), 60, sfCyan);
    end[8].texts = create_text("Lucas Bertrand", create_v2f(715, 500), 60, sfCyan);
    end[9].texts = create_text("Quentin de Carvalho", create_v2f(650, 600), 60, sfCyan);
    end[10].texts = create_text("\t   Merci\nd'avoir joue !",
                                create_v2f(765, 700), 60, sfWhite);
}
