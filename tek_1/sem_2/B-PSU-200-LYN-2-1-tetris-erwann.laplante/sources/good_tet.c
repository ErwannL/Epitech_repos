/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** good_tet
*/

#include "../include/my.h"

int good_tetrimino_bis(char *str, int column, int line)
{
    int x = 0;
    int y = 0;

    for (int i = 0, space = 0; str[i] != '\n'; i++) {
        if (str[i] == ' ') {
            space++;
            i++;
        }
        if (space == 0)
            x = (10 * x) + (str[i] - 48);
        if (space == 1)
            y = (10 * y) + (str[i] - 48);
    }
    if (column != x || line != y)
        return 84;
    return 0;
}

int good_tetrimino(char *str)
{
    int column = 0;
    int line = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            line++;
        if ((line == 0 && (str[i] < '0' || str[i] > '9') && str[i] != ' ')
        || (line != 0 && str[i] != ' ' && str[i] != '*' && str[i] != '\n'))
            return 84;
        if (line == 1)
            column++;
    }
    line--;
    column--;
    return good_tetrimino_bis(str, column, line);
}
