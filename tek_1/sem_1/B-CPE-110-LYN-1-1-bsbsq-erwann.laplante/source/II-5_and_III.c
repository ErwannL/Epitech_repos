/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-bsbsq-erwann.laplante
** File description:
** I - File systems -> step 6 && II - 2d arrays -> step 1 to 4
*/

#include "../include/my.h"

int array_2d_how_many(int **arr , int nb_rows , int nb_cols , int number)
{
    int res = 0;

    for (int i = 0; i != nb_rows; i++) {
        for (int j = 0; j != nb_cols; j++)
            res += ((arr[i][j] == number) ? (1) : (0));
    }
    return (res);
}

char *mem_alloc(char const *a, char const *b)
{
    char *res = malloc(sizeof(a) + sizeof(b));

    res = my_strcat(res, a);
    res = my_strcat(res, b);
    return (res);
}

char **mem_alloc_2d_array(int nb_rows , int nb_cols)
{
    char **res = malloc(sizeof(char *) * nb_rows);

    for (int i = 0; i != nb_rows ;i++)
        res[i] = malloc(sizeof(char) * nb_cols);
    return (res);
}

char **mem_dup_2d_array(char **arr , int nb_rows , int nb_cols)
{
    char **res = mem_alloc_2d_array(nb_rows, nb_cols);

    for (int i = 0; i != nb_rows; i++) {
        res[i] = my_strdup(arr[i]);
    }
    return (res);
}
