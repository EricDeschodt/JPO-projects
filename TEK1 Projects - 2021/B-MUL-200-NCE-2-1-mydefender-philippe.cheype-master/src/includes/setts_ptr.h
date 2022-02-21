/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** setts_ptr
*/

#ifndef SETTS_PTR_H_
#define SETTS_PTR_H_

#ifndef DEFENDER_H_

#include "defender.h"

#endif /* DEFENDER_H_ */

void (*setts_ptr[3])(vars_t *va, framebuffer_t *fb,     \
menu_t *mn, int *return_code) = {
    how_to_play,
    credits,
    return_menu
};

#endif /* SETTS_PTR_H_ */
