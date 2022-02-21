/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-mydefender-philippe.cheype
** File description:
** MENU_PTR
*/

#ifndef MENU_PTR_H_
#define MENU_PTR_H_

#ifndef DEFENDER_H_

#include "defender.h"

#endif /* DEFENDER_H_ */

void (*menu_ptr[4])(framebuffer_t *fb, vars_t *va, menu_t *mn) = {
    game,
    high_score,
    settings,
    exit_game
};

#endif /* MENU_PTR_H_ */
