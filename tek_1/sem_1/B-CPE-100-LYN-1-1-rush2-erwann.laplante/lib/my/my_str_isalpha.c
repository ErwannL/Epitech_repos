/*
** EPITECH PROJECT, 2021
** Task 12 - my_str_isalpha
** File description:
** function returns 1 if parameter only alphabetical characters and 0 if not
*/

#include"my.h"

int my_str_isalpha(char const *s)
{
    int long_max = my_strlen(s);
    int longueur = 0;
    int i = 0;

    if (long_max == 0)
        return (1);
    while (s[i] != '\0') {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            longueur++;
        i++;
    }
    if (longueur == long_max)
        return (1);
    return (0);
}
