/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-guilhem.vinet
** File description:
** main
*/

#include "../include/my.h"

void print_maze(var_t *var)
{
    for (int i = 0; var->maze[i]; i++) {
        my_putstr(var->maze[i]);
        var->maze[i + 1] ? my_putchar('\n') : 0;
    }
    return;
}

void recurs_solv(var_t *var, int i, int j)
{
    ((var->maze[var->size_y - 1][var->size_x - 1] == 'o') ? (0) :
    (var->maze[i][j] = 'o'));
    if ((i == var->size_y - 1 && j == var->size_x - 1)
    || (var->maze[var->size_y - 1][var->size_x - 1] == 'o')) {
        (i == var->size_y - 1 && j == var->size_x - 1) ? var->finish = 1 : 0;
        return;
    }
    if (i != 0 && var->maze[i - 1][j] == '*')
        recurs_solv(var, i - 1, j);
    if (i != var->size_y - 1 && var->maze[i + 1][j] == '*')
        recurs_solv(var, i + 1, j);
    if (j != 0 && var->maze[i][j - 1] == '*')
        recurs_solv(var, i, j - 1);
    if (j != var->size_x - 1 && var->maze[i][j + 1] == '*')
        recurs_solv(var, i, j + 1);
    ((var->maze[var->size_y - 1][var->size_x - 1] == 'o') ? (0)
    : (var->maze[i][j] = '*'));
    return;
}

int solver(var_t *var)
{
    int i = 0;
    int j = 0;

    var->size_y = 0;
    var->size_x = 0;
    var->finish = 0;
    var->maze = my_str_to_word_array(var->buffer, var->maze);
    for (; var->maze[var->size_y]; var->size_y++);
    for (; var->buffer[var->size_x] != '\n'; var->size_x++);
    if (var->maze[0][0] != '*'
    || var->maze[var->size_y - 1][var->size_x - 1] != '*')
        return 84;
    recurs_solv(var, i, j);
    if (var->finish != 0) {
        print_maze(var);
        return 0;
    } else {
        my_putstr("no solution found\n");
        return 84;
    }
}

int check_error(var_t *var)
{
    for (int i = 0; var->buffer[i] != '\0'; i++) {
        if (var->buffer[i] != 'X' && var->buffer[i] != '*'
        && var->buffer[i] != '\n')
            return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));

    if (argc != 2)
        return 84;
    else {
        var->fd = open(argv[1], O_RDONLY);
        if (var->fd == -1)
            return 84;
        var->st = stat(argv[1], &var->statut);
        if (var->st == -1)
            return 84;
        var->size = var->statut.st_size;
        var->buffer = malloc(sizeof(char) * (var->size + 1));
        read(var->fd, var->buffer, var->size);
        if (check_error(var) == 84)
            return 84;
        return solver(var);
    }
}
