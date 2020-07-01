/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** wave_parsor
*/

#include "utils.h"
#include "defender.h"

waves_t *fill_waves(char *line)
{
    waves_t *new = malloc(sizeof(waves_t));
    int i = my_strlen(line);
    new->clock = sfClock_create();
    for (; *line;) {
        if (*line == '%') {
            line++;
            new->round = get_int(line);
            line = new->round >= 10 ? line + 3 : line + 2;
            new->square = get_int(line);
            line = new->square >= 10 ? line + 3 : line + 2;
            new->triangle = get_int(line);
            line = new->triangle >= 10 ? line + 3 : line + 2;
        }
    }
    line -= (i + 1);
    new->seconds = 0, new->time.microseconds = 0;
    new->next = NULL;
    return (new);
}

void parse_wave(all_t *s_all)
{
    int fd = open("maps/waves_map1", O_RDONLY);
    char *waves = get_next_line(fd);
    int count = 0;
    s_all->s_wave_c.head = NULL;
    while (waves != NULL) {
        waves_t *temp = s_all->s_wave_c.head;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = fill_waves(waves);
        else temp = fill_waves(waves);
        free(waves);
        waves = get_next_line(fd);
        if (s_all->s_wave_c.head == NULL)
            s_all->s_wave_c.head = temp;
        count++;
    } s_all->s_wave_c.nb_waves = count;
    s_all->s_wave_c.temp = s_all->s_wave_c.head;
}