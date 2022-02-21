/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Handles adding to scoreboard
*/

#include "../../include/scoreboard.h"

int *get_list(int *list, int len_array, int s)
{
    bool found = false;
    for (int i = 0; i < len_array; i++) {
        if (found && i + 1 < len_array) {
            list[i] = list[i + 1];
        }
        if (list[i] <= s && !found) {
            int tmp = list[i];
            list[i] = s;
            i++;
            list[i] = tmp;
            found = true;
        }
    }
    return list;
}

void scoreboard_write_score(int *list, int len, char *path)
{
    char *str = malloc(sizeof(char) * (10 * 999) + 1);
    char *substring1;
    char *substring2 = "\0";
    for (int i = 0; i < len; i++) {
        str = int_to_str(str, list[i]);
        substring1 = my_strcat(str, "\n");
        char *temp = my_strdup(substring2);
        if (substring2[0])
            free(substring2);
        substring2 = my_strcat(temp, substring1);
        free(substring1);
        free(temp);
    }
    int fd = open(path, O_WRONLY);
    write(fd, substring2, my_strlen(substring2));
    free(str);
    free(substring2);
    close(fd);
}

void scoreboard_add_score(char *path, int s)
{
    char *scorepath = my_strcat(path, "/score.txt");
    char *buffer = my_get_file_ctn(scorepath);
    char **array_score = tab_create(buffer);
    free(buffer);
    int len_array = get_len_array(array_score) + 1;
    if (len_array > 10) len_array = 10;
    int *list = malloc(sizeof(int) * len_array);
    for (int i = 0; i < len_array; i++)
        list[i] = my_getnbr(array_score[i]);
    my_sort_int_array(list, len_array);
    list = get_list(list, len_array, s);
    scoreboard_write_score(list, len_array, scorepath);
    free(scorepath);
    free(list);
    tab_free(array_score);
}