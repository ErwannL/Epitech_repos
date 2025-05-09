/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** utilities
*/

#include "my.h"

int already_meet(char **prev_word, char *str, int stop)
{
    for (int i = 0; i != stop; i++) {
        if (strcmp(prev_word[i], str) == 0) {
            return 84;
        }
    }
    return 0;
}

char **sort_array(char **array, int stop)
{
    char *tmp;

    for (int i = 0; i != stop; i++) {
        for (int j = i; j != stop; j++) {
            (strcmp(array[i], array[j]) > 0) ? (tmp = strdup(array[j])
            , array[j] = strdup(array[i]), array[i] = strdup(tmp)) : 0;
        }
    }
    return array;
}

char *destroy_str(char *str, char *comp, int n)
{
    while (strncmp(str, comp, n) != 0)
        str++;
    return str;
}
