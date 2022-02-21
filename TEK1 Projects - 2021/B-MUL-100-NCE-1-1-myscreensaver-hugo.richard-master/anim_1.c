/*
** EPITECH PROJECT, 2020
** anim_1.c
** File description:
** animation 1
*/

#include "include/my.h"

static void display_anim1(screen *anim)
{
    sfVector2u v = {random_x(), random_y()};
    my_draw_square(anim->framebuffer, v, rand() % 70, random_color());
    sfTexture_updateFromPixels(anim->texture, anim->framebuffer->pixels,
    800, 600, 0, 0);
    sfRenderWindow_clear(anim->window, sfBlack);
    sfRenderWindow_drawSprite(anim->window, anim->sprite, NULL);
    sfRenderWindow_display(anim->window);
}

int anim_1(void)
{
    screen anim;
    sfVideoMode mode = {800, 600, 32};
    init_struct(&anim , "Animation 1", mode);
    !anim.texture ? exit(84) : (void) anim.event;
    sfSprite_setTexture(anim.sprite, anim.texture, sfTrue);
    while (sfRenderWindow_isOpen(anim.window)) {
        while (sfRenderWindow_pollEvent(anim.window, &anim.event)) {
            if (anim.event.type == sfEvtClosed)
                sfRenderWindow_close(anim.window);
        }
        display_anim1(&anim);
    }
    sf_destroy(&anim);
}