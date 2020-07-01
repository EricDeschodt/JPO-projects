/*
** EPITECH PROJECT, 2019
** message
** File description:
** message
*/

#include "defender.h"
#include "utils.h"

int message(void)
{
    char *text = adapt(".header");
    for (int i = 0; text[i] != '\0'; i++) {
        write(1, &text[i], 1);
    }
    return (EXIT_SUCCESS);
}