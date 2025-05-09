/*
** EPITECH PROJECT, 2021
** Task 05 - my_strstr
** File description:
** This function Reproduce the behavior of the strstr function
*/

#include <string.h>

int my_strlen6(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int second(char *str , char const *to_find, int i, int j)
{
    int max = 0;

    while (str[i] == to_find[j]) {
        i++;
        j++;
    }
    if (j == my_strlen6(to_find) + 1)
        max = 1;
    if (to_find[j - 1] == '\0' && max == 1)
        return (1);
    if (to_find[j] == '\0' && max == 0)
        return (1);
    return (0);
}

char *my_strstr(char *str , char const *to_find)
{
    int i = 0;
    int j = 0;
    int save = 0;
    int a = 0;

    if (my_strlen6(str) < my_strlen6(to_find) || my_strlen6(to_find) == 0)
        return (NULL);
    for (; str[i] != '\0';i++) {
        if (str[i] == to_find[j]) {
            save = i;
            a = second(str, to_find, i, j);
        }
        if (a == 1)
            return(&str[save]);
        if (a == 0)
            j = 0;
    }
}
