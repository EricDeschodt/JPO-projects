/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** utils_create
*/

#include <stdlib.h>
#include "struct.h"

utils_t *utils_create(void)
{
    utils_t *util = malloc(sizeof(utils_t));

    util->p.x = WIDTH / 2;
    util->p.y = HEIGHT / 2;
    util->u.x = WIDTH / 2;
    util->u.y = HEIGHT / 2;
    util->m.x = 10;
    util->m.y = 10;
    return (util);
}
