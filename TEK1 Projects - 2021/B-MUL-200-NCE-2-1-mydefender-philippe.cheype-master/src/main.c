/*
** EPITECH PROJECT, 2021
** myDefender
** File description:
** main
*/

#include <stdlib.h>
#include "defender.h"

int main(void)
{
    int return_code = SUCCESS_CODE;
    framebuffer_t *fb = NULL;
    vars_t *va = NULL;

    if ((fb = framebuffer_create()) == NULL)
        return_code = ERROR_CODE;
    if ((return_code != ERROR_CODE) && (va = vars_create(fb)) == NULL)
        return_code = ERROR_CODE;
    if (return_code == SUCCESS_CODE) {
        sfSprite_setTexture(va->sprite, va->texture, sfTrue);
        sfRenderWindow_setFramerateLimit(va->window, FPS);
        srand((unsigned long)&screen_end);
        menu(fb, va);
    }
    screen_end(fb, va);
    return (return_code);
}
