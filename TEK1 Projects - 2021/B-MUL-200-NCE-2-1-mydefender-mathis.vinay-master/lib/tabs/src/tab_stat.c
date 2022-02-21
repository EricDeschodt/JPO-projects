/*
** EPITECH PROJECT, 2021
** lib_include_makefile
** File description:
** get some stats about the given array
*/

#include <stdlib.h>

int get_len_array(char **array)
{
    int row = 0;

    for (; array[row]; row++);
    return row - 1;
}

int get_greater_line(char **array)
{
    int row = 0;
    int col = 0;
    int max = 0;

    for (; array[row]; row++) {
        for (col = 0; array[row][col]; col++);
        if (col >= max)
            max = col;
    }
    return max;
}

void **my_tabcat(void **dest, void **src)
{
    int a = 0;
    int s = 0;
    int r = 0;
    int q = 0;
    if (!src && !dest)
        return NULL;
    if (!dest)
        return src;
    if (!src)
        return dest;
    for (r = 0; dest[r]; r++);
    for (q = 0; src[q]; q++);
    void **save = malloc(sizeof(void *) * (r + 1 + q + 1));
    for (; dest[s]; s++)
        save[s] = dest[s];
    for (; src[a]; a++)
        save[s + a] = src[a];
    save[s + a] = NULL;
    return save;
}

void **my_tab_extend(void **dest, void *src)
{
    int i = 0;
    int r;
    void **save = NULL;
    if (!dest) {
        save = malloc(sizeof(void *) * 2);
        save[0] = src;
        save[1] = NULL;
        return save;
    }
    for (r = 0; dest[r]; r++);
    save = malloc(sizeof(void *) * (r + 2));
    for (; dest[i]; i++)
        save[i] = dest[i];
    save[i] = src;
    save[i + 1] = NULL;
    free(dest);
    return save;
}

void **my_tab_rm_line(void **dest, int i)
{
    if (!dest)
        return NULL;
    int r;
    for (r = 0; dest[r]; r++);
    for (; dest[i]; i++) {
        dest[i] = dest[i + 1];
    }
    free(dest[i]);
    return dest;
}