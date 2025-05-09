/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** game_next
*/

#include "../include/my.h"

void print_info_condition(var_t *var, int i, int j)
{
    if (var->next_cursor->patern[j][i] >= 65
    && var->next_cursor->patern[j][i] <= 90)
        addch('*');
    else
        addch(var->next_cursor->patern[j][i]);
}

void print_info_for(var_t *var)
{
    for (int j = 0; j < var->next_cursor->height; j++) {
        for (int i = 0; i < var->next_cursor->width; i++)
            print_info_condition(var, i, j);
        printw("\n");
    }
}
