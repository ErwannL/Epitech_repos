/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** check
*/

#include "../include/my.h"

int check_down(char **map, tetri_t *piece, int a, int b)
{
    int val = 0;

    if (piece->width == 1) {
        if (piece->patern[piece->height - 1][0] == '*'
        && map[a + piece->height][b] != ' ') {
            return 84;
        }
        return 0;
    }
    for (int i = 0; i != piece->height; i++) {
        for (int j = 0; j != piece->width; j++)
            (piece->patern[i][j] == '*' && map[a + i + 1][b + j] != ' ')
            ? val = 84 : 0;
        if (val == 84)
            return 84;
    }
    return 0;
}

int check_right(char **map, tetri_t *piece, int a, int b)
{
    int val = 0;

    for (int i = 0; i != piece->height; i++) {
        for (int j = 0; j != piece->width; j++)
            (piece->patern[i][j] == '*' && map[a + i][b + j + 1] != ' ')
            ? val = 84 : 0;
        if (val == 84)
            return 84;
    }
    return 0;
}

int check_left(char **map, tetri_t *piece, int a, int b)
{
    int val = 0;

    for (int i = 0; i != piece->height; i++) {
        for (int j = 0; j != piece->width; j++)
            (piece->patern[i][j] == '*' && map[a + i][b + j - 1] != ' ')
            ? val = 84 : 0;
        if (val == 84)
            return 84;
    }
    return 0;
}

int check_loose(var_t *var)
{
    if (var->ch == var->arg->key_quit)
        return 84;
    for (int j = 0; j != var->arg->map_size[1]; j++) {
        if (var->map[1][j] == '*')
            return 84;
    }
    return 0;
}
