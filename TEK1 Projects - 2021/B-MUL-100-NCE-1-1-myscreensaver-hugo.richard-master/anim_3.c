/*
** EPITECH PROJECT, 2020
** anim_3.c
** File description:
** animation 3
*/

#include "include/my.h"

int my_put_line(framebuffer_t *buffer, sfColor color, int x, int y)
{
    int i;
}

sfVector2f get_position(int x, int y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

static void display_anim3(screen *anim)
{
    sfVector2f mouse = get_position(anim->event.mouseMove.x,
    anim->event.mouseMove.y);
    sfVector2u v = {mouse.x, mouse.y};
    my_draw_square(anim->framebuffer, v, 10, random_color());
    sfTexture_updateFromPixels(anim->texture, anim->framebuffer->pixels,
    800, 600, 0, 0);
    sfRenderWindow_clear(anim->window, sfBlack);
    sfRenderWindow_drawSprite(anim->window, anim->sprite, NULL);
    sfRenderWindow_display(anim->window);
}

int anim_3(void)
{
    screen anim;
    sfVideoMode mode = {800, 600, 32};
    init_struct(&anim , "Animation 3", mode);
    !anim.texture ? exit(84) : (void) anim.event;
    sfSprite_setTexture(anim.sprite, anim.texture, sfTrue);
    while (sfRenderWindow_isOpen(anim.window)) {
        while (sfRenderWindow_pollEvent(anim.window, &anim.event)) {
            if (anim.event.type == sfEvtClosed)
                sfRenderWindow_close(anim.window);
        }
        display_anim3(&anim);
    }
    sf_destroy(&anim);
}
