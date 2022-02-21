/*
** EPITECH PROJECT, 2020
** anim_4.c
** File description:
** animation 4
*/

#include "include/my.h"

static void display_anim4(screen *anim)
{
    sfTexture_updateFromPixels(anim->texture, anim->framebuffer->pixels,
    800, 600, 0, 0);
    sfRenderWindow_clear(anim->window, sfBlack);
    sfRenderWindow_drawSprite(anim->window, anim->sprite, NULL);
    sfRenderWindow_display(anim->window);
}

int anim_4(void)
{
    screen anim;
    sfVideoMode mode = {800, 600, 32};
    init_struct(&anim , "Animation 4", mode);
    !anim.texture ? exit(84) : (void) anim.event;
    sfSprite_setTexture(anim.sprite, anim.texture, sfTrue);
    while (sfRenderWindow_isOpen(anim.window)) {
        while (sfRenderWindow_pollEvent(anim.window, &anim.event)) {
            if (anim.event.type == sfEvtClosed)
                sfRenderWindow_close(anim.window);
        }
        display_anim4(&anim);
    }
    sf_destroy(&anim);
}
