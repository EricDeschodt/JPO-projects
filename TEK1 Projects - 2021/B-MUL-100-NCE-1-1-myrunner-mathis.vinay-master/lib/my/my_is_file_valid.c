/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCE-1-1-navy-mathis.vinay
** File description:
** bool function for know if if an given file adress is valid
*/

#include <stdbool.h>
#include <stdio.h>

bool my_is_file_valid(char const *adress)
{
    FILE *file = fopen(adress, "r");
    if (file == NULL)
        return false;
    fclose(file);
    return true;
}