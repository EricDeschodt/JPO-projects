/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** functions to handle flags
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_FLAGS_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_FLAGS_H

#include <stdbool.h>
#include <stdlib.h>

#include "../../print/include/print.h"

bool is_flag(int argc, char **argv, char const *flag, char const *alias);
char *flag_get_value(int argc, char **argv, char const *flag, char const
*alias);

bool flag_help(int argc, char **argv, char const *to_display);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_FLAGS_H
