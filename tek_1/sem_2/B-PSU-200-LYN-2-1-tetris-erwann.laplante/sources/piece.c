/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** piece
*/

#include "../include/my.h"

var_t *put_piece(var_t *var, tetri_t *piece, int x, int y)
{
    int i = piece->height;
    int j = piece->width;

    for (int a = 0; a != i; a++) {
        for (int b = 0; b != j; b++) {
            piece->patern[a][b] == '*'
            ? var->map[a + x][b + y] = piece->patern[a][b] : 0;
        }
    }
    return var;
}

var_t *clear_piece(var_t *var, tetri_t *piece, int x, int y)
{
    int i = piece->height;
    int j = piece->width;

    for (int a = 0; a != i; a++) {
        for (int b = 0; b != j; b++) {
            piece->patern[a][b] == '*' ? var->map[a + x][b + y] = ' ' : 0;
        }
    }
    return var;
}

var_t *place_piece(var_t *var, int num)
{
    if (num == 1)
        var->a++;
    if (num == 2)
        var->b--;
    if (num == 3)
        var->b++;
    if (num == 4) {
        var->a = 1;
        var->b = 1;
    }
    var = put_piece(var, var->cursor, var->a, var->b);
    print_map(var);
    var = clear_piece(var, var->cursor, var->a, var->b);
    return var;
}

var_t *new_piece(var_t *var)
{
    var->n = var->next_n;
    var->cursor = var->next_cursor;
    var->next_cursor = var->tetri;
    var->next_n = rand() % (var->nbr_node - 1);
    for (; var->next_n >= var->nbr_node;)
        var->next_n = rand() % (var->nbr_node - 1);
    for (int i = 0; i != var->next_n; i++)
        var->next_cursor = var->next_cursor->next;
    var = place_piece(var, 4);
    return var;
}
