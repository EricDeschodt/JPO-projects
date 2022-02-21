/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** create_bullet.c
*/

#include <stdlib.h>
#include "defender.h"
#include "elements.h"

static void choose_bullet_texture(bullet_t *bullet, int type)
{
    switch (type) {
        case 0:
            bullet->type = 0;
            break;
        case 1:
            bullet->type = 1;
            break;
        case 2:
            bullet->type = 2;
            break;
        case 3:
            bullet->type = 3;
            break;
        case 4:
            bullet->type = 4;
            break;
        default:
            bullet->type = 5;
    }
}

static void prepare_bullet(bullet_t *bullet, sfVector2f motion, sfClock *clock)
{
    bullet->motion = motion;
    bullet->frame = 0;
    bullet->stop = 0;
    bullet->is_exploding = 0;
    bullet->clock = clock;
    bullet->next = NULL;
}

bullet_t *create_bullet(sfVector2f pos, sfVector2f motion, float type)
{
    char path[] = "assets/textures/bullets_ss.png";
    sfIntRect texture_area[] = {
        {  0,  69,  64, 30}, {  0,  0, 1158, 16},
        {  0, 104, 157, 20}, {725, 80,    8,  8},
        {259,  76,  33, 33}, {473, 78,   45, 13}
    };
    sfTexture *texture;
    bullet_t *bullet;
    sfClock *clock;

    bullet = malloc(sizeof(bullet_t));
    clock = sfClock_create();
    choose_bullet_texture(bullet, type);
    texture = sfTexture_createFromFile(path, &texture_area[bullet->type]);
    sfVector2f size = { texture_area[bullet->type].width,   \
                        texture_area[bullet->type].height};
    bullet->bullet = create_rectangle(pos, size, texture, sfFalse);
    prepare_bullet(bullet, motion, clock);
    return (bullet);
}
