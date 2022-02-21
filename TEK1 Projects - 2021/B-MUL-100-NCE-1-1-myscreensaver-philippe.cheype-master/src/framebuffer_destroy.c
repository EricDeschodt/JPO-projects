/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** framebuffer_destroy
*/

#include <stdlib.h>
#include "struct.h"

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
    return;
}
