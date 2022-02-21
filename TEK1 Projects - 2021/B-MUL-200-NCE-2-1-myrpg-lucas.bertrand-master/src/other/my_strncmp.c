/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** lib
*/

int my_strncmp(char const *s1, char const *s2, int n)
 {
     int i = 0;
     while (s1[i] != '\0' && s1[i] == s2[i] && i < n)
         i++;
     if (s1[i] < s2[i] && n != i)
         return (-1);
     else if (s1[i] > s2[i] && n != i)
         return (1);
     return (0);
 }
