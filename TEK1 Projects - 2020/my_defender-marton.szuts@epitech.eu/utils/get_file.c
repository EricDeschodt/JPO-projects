/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** get_file
*/

#include "utils.h"
#include "defender.h"

int get_file_size(int fd)
{
    char c;
    int i = 0;
    for (; read(fd, &c, 1) == 1; i++);
    return (i);
}

int get_nb_lines(char *map)
{
    int i = 0, x = 0;

    for (; map[x] != '\0'; x++) {
        if (map[x] == '\n')
            i++;
    }
    return (i);
}

char *get_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int file_size = get_file_size(fd);
    close(fd);
    fd = open(filepath, O_RDONLY);
    char *str = malloc(sizeof(char) * file_size + 1);
    read(fd, str, file_size);
    str[file_size] = '\0', close(fd);
    return (str);
}

int get_biggest_line(char *map)
{
    int nb_lines = get_nb_lines(map);
    int nb_columns = 0, j = 0, k = 0;
    for (int i = 0; i < nb_lines; i++) {
        for (k = 0; map[j] != '\n'; j++, k++);
        j++;
    if (nb_columns < k)
        nb_columns = k;
    }
    return (nb_columns);
}

char *adapt(char const *filepath)
{
    char *map = get_file(filepath);
    int biggest = get_biggest_line(map);
    int nb_lines = get_nb_lines(map), k = 0, j = 0, x = 0;
    char *new_map = malloc(sizeof(char) * (biggest * nb_lines + nb_lines) + 1);
    for (int i = 0; i < nb_lines; i++) {
        for (x = 0; map[j] != '\n' && map[j] != '\0'; k++, j++, x++)
            new_map[k] = map[j];
        for (; x < biggest; k++, x++)
            new_map[k] = ' ';
        new_map[k++] = '\n';
        j++;
    }
    free(map);
    new_map[k] = '\0';
    return (new_map);
}