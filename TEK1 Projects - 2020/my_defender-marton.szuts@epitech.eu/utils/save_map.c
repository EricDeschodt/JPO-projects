/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** save_map
*/

#include "defender.h"
#include "utils.h"

void create_new_file(char **saved, char *filename)
{
    char folder[13] = "custom_maps/";
    char *filepath = malloc(sizeof(char) * 13 * my_strlen(filename));
    filepath[0] = '\0';
    my_strcat(filepath, folder), my_strcat(filepath, filename);
    int fd = open(filepath, O_CREAT, 00660);
    close(fd);
    fd = open(filepath, O_RDWR);
    for (int i = 0; saved[i] != NULL; i++) {
        write(fd, saved[i], my_strlen(saved[i]));
    }
    close(fd);
    free_double_array(saved);
    free(filepath), free(filename);
}

void clean_str(char *str)
{
    my_revstr(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '@') str[i] = ' ';
    }
}

void write_map(char **saved, all_t *s_all)
{
    saved = rev_ptr(saved);
    int nb = 1;
    DIR *dirp;
    struct dirent *my_dirent;
    char name[12] = "custom_map_";
    char *new_name = malloc(sizeof(char) * 20);
    for (int i = 0; saved[i] != NULL; i++)
        clean_str(saved[i]);
    dirp = opendir("custom_maps");
    my_dirent = readdir(dirp), new_name[0] = '\0';
    for (; my_dirent != NULL;) {
        if (my_dirent->d_name[0] != '.') nb++;
        my_dirent = readdir(dirp);
    } closedir(dirp);
    if (map_error_handling(saved, s_all)) {
        my_strcat(new_name, name), my_strcat(new_name, strnbr(nb));
        create_new_file(saved, new_name);
    }
}

void save_map(all_t *s_all)
{
    char **saved = malloc(sizeof(char *) * 9);
    int i = 0, j = 0;
    support_t *temp = s_all->s_map_edit.head;
    for (; i != 8; i++) {
        saved[i] = malloc(sizeof(char) * 17);
        saved[i][j++] = '\n';
        saved[i][j++] = i == 0 ? '#' : ' ';
        for (; j != 16; j++) {
            saved[i][j] = temp->type;
            temp = temp->next;
        } saved[i][j] = '\0', j = 0;
    } saved[i] = NULL;
    write_map(saved, s_all);
    if (s_all->s_map_edit.error == 0)
        free_placed_node(s_all);
}