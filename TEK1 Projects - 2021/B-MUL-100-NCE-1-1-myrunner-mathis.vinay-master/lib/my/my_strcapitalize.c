/*
** EPITECH PROJECT, 2020
** my_strcaptitalize
** File description:
** chaque mot voit sa première lettre être foutue en maj.
** ça sert à rien mais c'est stylé
*/

char upper_this(char c);

char *my_strcapitalize(char *str)
{
    int is_spaced = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_spaced == 1) {
            str[i] = upper_this(str[i]);
            is_spaced = 0;
        }
        if (str[i] == ' ')
            is_spaced = 1;
    }
    return (str);
}
