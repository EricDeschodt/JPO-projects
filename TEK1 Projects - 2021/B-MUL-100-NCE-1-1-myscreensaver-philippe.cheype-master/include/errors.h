/*
** EPITECH PROJECT, 2020
** my_screensaver (Workspace)
** File description:
** errors
*/

#ifndef ERRORS_H_
#define ERRORS_H_

#include <unistd.h>

#define BAD_EFFECT  write(2, "Error: That effect doesn't exist.\n", 34)

#endif /* ERRORS_H_ */
