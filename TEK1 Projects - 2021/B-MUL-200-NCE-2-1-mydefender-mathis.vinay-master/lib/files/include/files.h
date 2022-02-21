/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** fonctions to handle files
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_FILES_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_FILES_H

#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

bool my_is_file_valid(char const *adress);
char *my_get_file_ctn(char const *file_adress);
bool my_is_file_writable(char const *adress);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_FILES_H
