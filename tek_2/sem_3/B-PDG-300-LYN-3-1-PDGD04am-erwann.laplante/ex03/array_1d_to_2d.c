/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04am-erwann.laplante
** File description:
** array_1d_to_2d
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void array_1d_to_2d (const int *array, size_t height, size_t width,
    int ***res)
{
    int num = 0;

    *res = malloc(sizeof(int *) * (height + 2));
    for (int i = 0; i != height; i++) {
        (*res)[i] = malloc(sizeof(int) * (width + 2));
    }
    for (int j = 0; j != height; j++) {
        for (int k = 0; k != width; k++) {
            (*res)[j][k] = array[num];
            num++;
        }
    }
}

void array_2d_free (int **array, size_t height, size_t width)
{
    for (int i = 0; i != height; i++) {
        free(array[i]);
    }
    free(array);
}
