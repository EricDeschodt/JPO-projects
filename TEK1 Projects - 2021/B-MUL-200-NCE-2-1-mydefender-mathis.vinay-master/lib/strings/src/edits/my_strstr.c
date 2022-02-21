/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** search for the index of a str in an other str and returns str[index:]
*/

int get_index(const char *str, char const *to_find)
{
    int index = -1;
    int is_same = 0;

    for (int i = 0 ; str[i] != '\0' && is_same != 1 ; i++) {
        is_same = 1;
        for (int j = 0 ; to_find[j] != '\0'; j++) {
            if (str[i + j] != to_find[j])
                is_same = 0;
        }
        if (is_same == 1)
            index = i;
    }
    return (index);
}

char *my_strstr(char *str, char const *to_find)
{
    int index = get_index(str, to_find);

    if (index != -1)
        return (&str[index + 1]);
    else
        return (0);
}
