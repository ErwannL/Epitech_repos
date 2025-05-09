/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-erwann.laplante
** File description:
** loose
*/

#include "../include/my.h"

int loose(char **save, char **map, int i, int j)
{
    if (map[i][j] == 'X' && save[i][j] != 'O'
    && (((map[i + 1][j] == '#') && (map[i][j - 1] == '#'))
    || ((map[i][j - 1] == '#') && (map[i - 1][j] == '#'))
    || ((map[i - 1][j] == '#') && (map[i][j + 1] == '#'))
    || ((map[i + 1][j] == '#') && (map[i][j + 1] == '#')))) {
        return 84;
    }
    return 0;
}

int check_loose(char **save, int max, char **map)
{
    int i = 0;
    int j = 0;
    int val = 0;

    while (i < max) {
        j = 0;
        while (map[i][j] != '\0') {
            (loose(save, map, i, j) == 84) ? val = 84 : 0;
            j = j + 1;
        }
        if (val == 84)
            return 84;
        i = i + 1;
    }
    return 0;
}
