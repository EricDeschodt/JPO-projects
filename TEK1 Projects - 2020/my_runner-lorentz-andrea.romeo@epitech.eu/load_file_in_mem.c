/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** load_file_in_mem
*/

#include "my.h"

char *load_file_in_mem(char *filepath)
{
    char *file;
    char buff;
    int fd = 0, len = 0, rd = 0;
    fd = open(filepath, O_RDONLY);
    if (fd == -1) return (NULL);
    rd = read(fd, &buff, 1);
    for (; buff != 'X' && rd != -1 ; len++)
        rd = read(fd, &buff, 1);
    file = malloc((len + 2) * sizeof(char));
    close(fd);
    fd = open(filepath, O_RDONLY);
    read(fd, file, len + 1);
    file[len + 1] = '\0';
    close(fd);
    return (file);
}

int count_entities(char *map)
{
    int count = 0;
    for (int i = 0; map[i] != 'X'; i++) {
        if (map[i] >= '0' && map[i] <= '9')
            count++;
    }
    return (count);
}

int pos_entities_bis(char *map, int nb, int pos)
{
    int count = 0;
    int i = 0;
    for (; count != nb; i++) {
        if (map[i] == 'R')
            i += 53;
        if (map[i] >= '0' && map[i] <= '9')
            count++;
    }
    i -= 2;
    for (; count != nb - 1; i--) {
        if (map[i] == '\n')
            i -= 53;
        if (map[i] >= '0' && map[i] <= '9')
            count--;
        pos += 40;
    }
    return (pos);
}

int pos_entities(char *map, int nb, int pos)
{
    int count = 0;
    int i = 0;
    if (nb >= 2) {
        pos = pos_entities_bis(map, nb, pos);
    }
    else {
        for (; count != nb; i++) {
            if (map[i] >= '0' && map[i] <= '9')
                count++;
            pos += 40;
        }
    }
    return (pos);
}

int who_entities(char *map, int nb)
{
    int count = 0;
    int i = 0;
    for (; count != nb && map[i] != 'X'; i++) {
        if (map[i] >= '0' && map[i] <= '9')
            count++;
    }
    i--;
    return (map[i] - '0');
}