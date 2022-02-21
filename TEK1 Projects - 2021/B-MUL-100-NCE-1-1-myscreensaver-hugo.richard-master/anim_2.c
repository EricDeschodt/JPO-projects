/*
** EPITECH PROJECT, 2020
** anim_2.c
** File description:
** animation 2
*/

#include "include/my.h"

static void display_anim2(screen *anim)
{
    my_put_pixel(anim->framebuffer, random_x(), random_y(), random_color());
    sfTexture_updateFromPixels(anim->texture, anim->framebuffer->pixels,
    800, 600, 0, 0);
    sfRenderWindow_clear(anim->window, sfBlack);
    sfRenderWindow_drawSprite(anim->window, anim->sprite, NULL);
    sfRenderWindow_display(anim->window);
}

int anim_2(void)
{
    screen anim;
    sfVideoMode mode = {800, 600, 32};
    init_struct(&anim , "Animation 2", mode);
    !anim.texture ? exit(84) : (void) anim.event;
    sfSprite_setTexture(anim.sprite, anim.texture, sfTrue);
    while (sfRenderWindow_isOpen(anim.window)) {
        while (sfRenderWindow_pollEvent(anim.window, &anim.event)) {
            if (anim.event.type == sfEvtClosed)
                sfRenderWindow_close(anim.window);
        }
        display_anim2(&anim);
    }
    sf_destroy(&anim);
}
