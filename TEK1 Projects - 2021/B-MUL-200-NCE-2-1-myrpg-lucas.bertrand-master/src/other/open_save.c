/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** open_save
*/
#include "../../include/my.h"
#include "../../include/struct.h"

char *find_music(char *save)
{
    char *code = "f123l";
    char *music[5] = {"sound/field.ogg", "sound/crypt1.ogg",
        "sound/crypt2.ogg", "sound/crypt3.ogg", "sound/labo.ogg"};

    for (int i = 0; i != 5; i++)
        if (save[0] == code[i])
            return (music[i]);
}

char *find_sprite(char *save)
{
    char *code = "f123l";
    char *sprite[5] = {"sprite/field.png", "sprite/crypt1.png",
        "sprite/crypt2.png", "sprite/crypt3.png", "sprite/labo.png"};

    for (int i = 0; i != 5; i++)
        if (save[0] == code[i])
            return (sprite[i]);
}

void open_map(sfRenderWindow *window, char *save, char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat buf;
    stat(filepath, &buf);
    int size = buf.st_size;
    char buffer[size + 1];
    char *file[3] = {find_sprite(save), find_music(save), buffer};
    int stat[7] = {my_getnbr(save, 2), my_getnbr(save, 7),
        my_getnbr(save, 10), my_getnbr(save, 13), my_getnbr(save, 18),
        my_getnbr(save, 23), my_getnbr(save, 29)};

    read(fd, &buffer, size - 1);
    close(fd);
    create_area_one(window, file, stat, save);
}

void read_save(sfRenderWindow *window, char *save)
{
    char *code = "f123l";
    char *area[5] = {"map/field.txt", "map/crypt1.txt",
        "map/crypt2.txt", "map/crypt3.txt", "map/labo.txt"};
    char *save_intro = "f 0000 20 10 1240 0406 -3408 -1594";
    int len_s = my_strlen(save_intro);
    char *eric = "f 0700 90 45 1240 0406 -3408 -1594 33377799;;";
    int len_e = my_strlen(eric);

    for (int i = 0; i != 5; i++)
        if (save[0] == code[i]) {
            if (my_strncmp(save, save_intro, len_s) == 0 ||
                my_strncmp(save, eric, len_e) == 0)
                if (create_intro(window) == 1)
                    return;
            open_map(window, save, area[i]);
        }
}

void open_save(sfRenderWindow *window)
{
    int fd = open("save/save.txt", O_RDONLY);
    struct stat buf;
    stat("save/save.txt", &buf);
    int size = buf.st_size;
    char buffer[size];

    read(fd, &buffer, size);
    read_save(window, buffer);
    close(fd);
}
