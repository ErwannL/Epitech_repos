/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper2-anthony.faure
** File description:
** map
*/

#include "../include/my.h"

void print_map(var_t *var)
{
    for (int i = 0; var->map[i]; i++) {
        my_putstr(var->map[i], 1);
        my_putchar('\n', 1);
    }
}

var_t *put_in_map(var_t *var, int i, int j)
{
    if (i == 0 || i == var->height + 1) {
        var->map[i][j] = '+';
    } else if (j == 0 || j == var->width + 1) {
        var->map[i][j] = '|';
    } else {
        var->map[i][j] = '.';
    }
    return var;
}

var_t *creat_map(var_t *var)
{
    var->map = malloc(sizeof(char *) * (var->height + 3));
    var->map[var->height + 2] = NULL;
    for (int i = 0; i != var->height + 2; i++) {
        var->map[i] = malloc(sizeof(char) * (var->width + 3));
        var->map[i][var->width + 2] = '\0';
    }
    for (int i = 0; i != var->height + 2; i++) {
        for (int j = 0; j != var->width + 2; j++) {
            var = put_in_map(var, i, j);
        }
    }
    return var;
}

int is_a_tie(var_t *var)
{
    int val = 84;

    for (int i = 1; i != var->height + 1; i++) {
        for (int j = 1; j != var->width + 1; j++) {
            (var->map[i][j] == '.') ? val = 0 : 0;
        }
        if (val == 0)
            return 0;
    }
    return val;
}
