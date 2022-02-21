/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCE-1-1-navy-mathis.vinay
** File description:
** bool function for know if if an given file adress is valid
*/

#include "../include/files.h"

bool my_is_file_valid(char const *adress)
{
    int file = open(adress, O_RDONLY);
    if (file == -1)
        return false;
    close(file);
    return true;
}

bool my_is_file_writable(char const *adress)
{
    int file = open(adress, O_WRONLY);
    if (file == -1)
        return false;
    close(file);
    return true;
}