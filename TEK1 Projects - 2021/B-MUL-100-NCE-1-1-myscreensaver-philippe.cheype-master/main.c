/*
** EPITECH PROJECT, 2020
** Main
** File description:
** SFML Testing
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "src/struct.h"
#include "src/lib.h"
#include "src/my.h"

static int error_handling(int ac)
{
    if (ac < 2) {
        bad_params(ac);
        return (84);
    }
    return (0);
}

static int param_handling(char **av)
{
    if (av[1][0] == '-') {
        if (av[1][1] == 'h')
            help_menu();
        if (av[1][1] == 'd')
            list_menu();
        return (1);
    }
    return (0);
}

static void main_loop(framebuffer_t *fb, vars_t *va, char *effect)
{
    utils_t *u = utils_create();

    while (sfRenderWindow_isOpen(va->window)) {
        while (sfRenderWindow_pollEvent(va->window, &va->event)) {
            if (va->event.type == sfEvtClosed) sfRenderWindow_close(va->window);
            if (va->event.key.code == sfKeyLeft)
                effect[0]++, clean_window(fb);
            if (va->event.key.code == sfKeyRight)
                effect[0]--, clean_window(fb);
            (effect[0] < '1') && (effect[0] = '4');
            (effect[0] > '4') && (effect[0] = '1');
        }
        sfRenderWindow_clear(va->window, sfBlack);
        effect_index(fb, effect, va, u);
        sfTexture_updateFromPixels(va->texture, fb->pixels,    \
                                            fb->width, fb->height, 0, 0);
        sfRenderWindow_drawSprite(va->window, va->sprite, NULL);
        sfRenderWindow_display(va->window);
    }
}

int main(int ac, char **av)
{
    if (error_handling(ac) == 84)
        return (84);
    if (param_handling(av) == 1)
        return (0);
    char *effect = av[1];

    framebuffer_t *fb = framebuffer_create(WIDTH, HEIGHT);
    vars_t *va = vars_create(fb, PIXELS);
    sfSprite_setTexture(va->sprite, va->texture, sfTrue);
    sfRenderWindow_setFramerateLimit(va->window, 30);
    main_loop(fb, va, effect);
    screen_end(fb, va->sprite, va->texture, va->window);
    return (0);
}
