/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** Split a given argument string into words.
*/

#include "my.h"

char **mem_alloc_2d_array(int *dimensions)
{
    char **ptr = (char **)malloc(dimensions[1] * sizeof(char *));

    for (int y = 0; y < dimensions[1]; y++) {
        ptr[y] = (char *)malloc(dimensions[0]);
    }
    return ptr;
}

char **my_str_to_word_array(char const *str, int *dimensions)
{
    int *axis = (int *)malloc(sizeof(int) * 2);
    char **arr = mem_alloc_2d_array(dimensions);

    for (int i = 0; str[i] != '\0'; i++) {
        axis[1] -= ((str[i] == '\n') ? -1 : 0);
        axis[0] = ((str[i] == '\n') ? 0 : axis[0]);
        if ((str[i] != '\n') && (axis[1] != 4)) {
            arr[axis[1]][axis[0]] = str[i];
        }
        axis[0] -= ((str[i] != '\n') ? -1 : 0);
    }
    return arr;
}
