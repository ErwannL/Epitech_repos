/*
** EPITECH PROJECT, 2021
** lemin
** File description:
** utilities
*/

#include "lemin.h"

int my_getnbr(char const *str, int i)
{
    int nb = 0;
    int isneg = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        isneg = ((str[i] == '-') ? -1 : isneg);
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10 + str[i] - 48;
        }
    }
    nb *= isneg;
    return nb;
}

int *get_dimensions(char *str)
{
    int *dimensions = malloc(sizeof(int) * 2);

    dimensions[0] = 0;
    dimensions[1] = 0;
    for (int i = 0; str[i] != '\n'; i++, dimensions[0]++);
    for (int i = 0; str[i] != '\0'; i++)
        dimensions[1] += ((str[i] == '\n') ? 1 : 0);
    dimensions[1] += 1;
    return dimensions;
}

char **my_str_to_word_array(char const *str, int *dims)
{
    int *axis = (int *)malloc(sizeof(int) * 2);
    char **arr = (char **)malloc(sizeof(char *) * dims[1]);

    for (int y = 0; y < dims[1]; y++)
        arr[y] = (char *)malloc(sizeof(char) * dims[0]);
    for (int i = 0; str[i] != '\0'; i++) {
        axis[1] -= ((str[i] == '\n') ? -1 : 0);
        axis[0] = ((str[i] == '\n') ? 0 : axis[0]);
        if (str[i] != '\n')
            arr[axis[1]][axis[0]] = str[i];
        axis[0] -= ((str[i] != '\n') ? -1 : 0);
    }
    free(axis);
    return arr;
}
