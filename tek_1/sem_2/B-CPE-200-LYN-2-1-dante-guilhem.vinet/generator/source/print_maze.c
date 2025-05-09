/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-guilhem.vinet
** File description:
** print_maze
*/

#include "../include/my.h"

void print_maze(var_t *var)
{
    for (int i = 0; i != var->size_y - 1; i++) {
        my_putstr(var->maze[i]);
        my_putchar('\n');
    }
    my_putstr(var->maze[var->size_y - 1]);
}
