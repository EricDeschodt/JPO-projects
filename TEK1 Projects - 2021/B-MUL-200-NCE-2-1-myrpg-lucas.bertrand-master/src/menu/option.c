/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** option
*/
#include "../../include/my.h"
#include "../../include/struct.h"

int verif_option(scene_t *menu, int i)
{
    char *vem = "Activer le Eric mode ?\nCe mode ne peut"
        " etre desactive qu'en supprimant\nla sauvegarde en cours.";
    char *vef = "Voulez-vous vraiment supprimer la sauvegarde\nen cours ?";

    if (i == 0) {
        sfText_setString(menu[12].texts->text, vem);
        return (9);
    }
    else if (i == 2) {
        sfText_setString(menu[12].texts->text, vef);
        return (9);
    }
    return (0);
}

void reset_map(char *filepath, char **map)
{
    int fd = open(filepath, O_RDWR);
    char enter = '\n';

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == '9' || map[i][j] == ';'
                || map[i][j] == '=' || map[i][j] == '?')
                map[i][j]--;
            write(fd, &map[i][j], 1);
        }
        write(fd, &enter, 1);
    }
}

void verif_map(int i)
{
    char *map[5] = {"map/field.txt", "map/crypt1.txt", "map/crypt2.txt",
        "map/crypt3.txt", "map/labo.txt"};
    int fd = open(map[i], O_RDWR);
    struct stat buf;
    stat(map[i], &buf);
    int size = buf.st_size;
    char buffer[size + 1];

    read(fd, &buffer, size - 1);
    reset_map(map[i], my_str_to_word_array(buffer));
    close(fd);
}

void eric_mode(void)
{
    int fd = open("save/save.txt", O_RDWR);
    char *buffer = "f 0700 90 45 1240 0406 -3408 -1594 33377799;; ";

    for (int i = 0; buffer[i] != '\0'; i++)
        write(fd, &buffer[i], 1);
    for (int i = 0; i != 5; i++)
        verif_map(i);
    close(fd);
}

void erase_save(void)
{
    int fd = open("save/save.txt", O_RDWR);
    char *save = "f 0000 20 10 1240 0406 -3408 -1594            ";

    for (int i = 0; save[i] != '\0'; i++)
      write(fd, &save[i], 1);
    for (int i = 0; i != 5; i++)
        verif_map(i);
    close(fd);
}
