/*
** EPITECH PROJECT, 2020
** nb_text
** File description:
** return rectangle shape
*/

#include "../../include/include.h"

sfIntRect *nb_text3(char c)
{
    if (c == ',') return (get_rect(12*16, 4*16, 16, 16));
    if (c == ';') return (get_rect(12*16, 5*16, 16, 16));
    if (c == '!') return (get_rect(18*16, 0*16, 16, 16));
    return (NULL);
}

sfIntRect *nb_text2(char c)
{
    if (c == 'q') return (get_rect(17*16, 5*16, 16, 16));
    if (c == 's') return (get_rect(35*8, 5*16, 16, 16));
    if (c == 'd') return (get_rect(18*16, 5*16, 16, 16));
    if (c == 'w') return (get_rect(14*16, 7*16, 16, 16));
    if (c == 'x') return (get_rect(15*16, 6*16, 16, 16));
    if (c == 'c') return (get_rect(16*16, 6*16, 16, 16));
    if (c == 'E') return (get_rect(13*16, 0*16, 16, 16));
    if (c == 'l') return (get_rect(11*16, 4*16, 16, 16));
    if (c == 'f') return (get_rect(9*16, 6*16, 16, 16));
    if (c == 'F') return (get_rect(10*16, 6*16, 16, 16));
    if (c == 'r') return (get_rect(9*16, 5*16, 16, 16));
    if (c == 'R') return (get_rect(10*16, 5*16, 16, 16));
    if (c == 'o') return (get_rect(10*16, 7*16, 16, 16));
    if (c == 'g') return (get_rect(15*16, 7*16, 16, 16));
    if (c == 'h') return (get_rect(19*16, 1*16, 16, 16));
    if (c == 'p') return (get_rect(19*16, 2*16, 16, 16));
    if (c == 'm') return (get_rect(16*16, 0*16, 16, 16));
    if (c == '@') return (get_rect(13*16, 0*16, 16, 16));
    if (c == ')') return (get_rect(14*16, 0*16, 16, 16));
    return (nb_text3(c));
}

sfIntRect *nb_text(char c)
{
    if (c == '7') return (get_rect(0, 4*16, 16, 16));
    if (c == '8') return (get_rect(16, 4*16, 16, 16));
    if (c == '9') return (get_rect(2*16, 4*16, 16, 16));
    if (c == '4') return (get_rect(0, 5*16, 16, 16));
    if (c == '5') return (get_rect(16, 5*16, 16, 16));
    if (c == '6') return (get_rect(2*16, 5*16, 16, 16));
    if (c == '1') return (get_rect(0, 6*16, 16, 16));
    if (c == '2') return (get_rect(16, 6*16, 16, 16));
    if (c == '3') return (get_rect(2*16, 6*16, 16, 16));
    if (c == 'S') return (get_rect(7*16, 16, 16, 16));
    if (c == 'H') return (get_rect(7*16, 0*16, 16, 16));
    if (c == 'A') return (get_rect(8*16, 5*16, 16, 16));
    if (c == 'T') return (get_rect(8*16, 6*16, 16, 16));
    if (c == 'P') return (get_rect(0, 0, 16, 16));
    if (c == 'L') return (get_rect(13*16, 4*16, 16, 16));
    if (c == 'G') return (get_rect(14*16, 5*16, 16, 16));
    if (c == 'a') return (get_rect(15*16, 5*16, 16, 16));
    if (c == 'z') return (get_rect(14*16, 6*16, 16, 16));
    if (c == 'e') return (get_rect(16*16, 5*16, 16, 16));
    return (nb_text2(c));
}