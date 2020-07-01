/*
** EPITECH PROJECT, 2019
** message
** File description:
** message
*/

#include "runner.h"

void message2(void)
{
    write(1, "If you click Play, the game will launch your map as arg.\n", 57);
    write(1, "Click 'Levels' to select levels.\n", 33);
    write(1, "Try to complete levels from 1 to 3.\n", 36);
    write(1, "Avoid obstacles and monsters, and try to get every coin!\n", 57);
    write(1, "\nYour score is the product of total coins and distance.\n", 56);
    write(1, "\nThe best way to increase your score is infinite mode.\n", 55);
    write(1, "You can't win in infinite mode, if you fail you lose.\n", 55);
    write(1, "Your score is saved only if you win or lose and will be ", 56);
    write(1, "updated by returning to main menu or leaving the game.\n", 55);
    write(1, "In infinite mode the map is generating randomly between ", 56);
    write(1, "all the 3 maps.\n\n", 17);
    write(1, "You'll find my map formating system in the hidden", 49);
    write(1, " .legend file at the root\n\n", 27);
    write(1, "Play the game at 60 fps or more to avoid some bugs.\n", 53);
    write(1, "Good luck try your best and have fun!\n\n", 39);
}

int message(void)
{
    write(1, "USAGE\n", 6);
    write(1, "    ./my_runner maps/map(1, 2, or 3)\n\n", 38);
    write(1, "DESCRIPTION\n", 12);
    write(1, "    Runner game\n\n", 17);
    message2();
    write(1, "CONTROLS\n", 9);
    write(1, "    SPACE to jump\n", 18);
    write(1, "    LCTRL to slide\n    P to pause\n\n", 35);
    write(1, "NOTE\nYou can't slide and jump at the same time.\n", 48);
    write(1, "You will need to land first then slide. (It's tricky)\n", 54);
    return (EXIT_SUCCESS);
}