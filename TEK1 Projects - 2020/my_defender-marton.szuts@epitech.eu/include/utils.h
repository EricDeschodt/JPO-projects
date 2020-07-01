/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_
#include <stdlib.h>
#include <unistd.h>
#include "defender.h"
#include <signal.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

#ifndef READ_SIZE
#define READ_SIZE (30)
#endif

typedef struct parsor {
    sfVector2f pos;
    int i;
    char *map;
} parsor_t;

support_t *parse_map(char *filepath);
char *my_strdup(char *str);
int my_strlen(char *str);
int my_strlen_n(char *str);
char *strnbr(int n);
char *adapt(char const *filepath);
char *get_file(char const *filepath);
void parse_wave(all_t *s_all);
int get_int(char *av);
void parse_wave(all_t *s_all);
char *my_revstr(char *str);
char **rev_ptr(char **str);
void free_double_array(char **str);
int my_ptr_len(char **str);
int randomizer(FILE *file);
int randomize(void);
int linked_len(all_t *s_all, int id);
char *my_strcat(char *dest, char const *src);
char *strnbr_float(float n);
int my_atoi(char const *str);

char *get_next_line(int fd);

#endif /* !UTILS_H_ */
