/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** a function to handle the help flag
*/

#include "../include/flags.h"

bool flag_help(int argc, char **argv, char const *to_display)
{
    if (is_flag(argc, argv, "--help", "-h")) {
        my_putstr(to_display);
        return true;
    }
    return false;
}