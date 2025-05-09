/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** turn
*/

#include "../include/my.h"

int check_turn(tetri_t *new_piece, tetri_t *old_piece, var_t *var, int *num)
{
    int a = num[0];
    int b = num[1];
    int h = num[2];

    for (int w = 0; w != new_piece->width; w++) {
        if (var->map[a + h][b + w] != ' '
        && old_piece->patern[(w - (old_piece->height - 1)) * -1][h] == '*')
            return 84;
        else
            new_piece->patern[h][w]
            = old_piece->patern[(w - (old_piece->height - 1)) * -1][h];
    }
    return 0;
}

tetri_t *turn_piece(var_t *var, tetri_t *old_piece, int a, int b)
{
    tetri_t *new_piece = malloc(sizeof(tetri_t));
    int *num = malloc(sizeof(int) * 4);

    new_piece->color = old_piece->color;
    new_piece->name = old_piece->name;
    new_piece->next = old_piece->next;
    new_piece->height = old_piece->width;
    new_piece->width = old_piece->height;
    new_piece->patern = malloc(sizeof(char *) * (new_piece->height + 1));
    for (int w = 0; w != new_piece->height; w++)
        new_piece->patern[w] = malloc(sizeof(char) * (new_piece->width + 1));
    for (int h = 0; h != new_piece->height; h++) {
        num[0] = a;
        num[1] = b;
        num[2] = h;
        if (check_turn(new_piece, old_piece, var, num) == 84)
            return old_piece;
    }
    return new_piece;
}
