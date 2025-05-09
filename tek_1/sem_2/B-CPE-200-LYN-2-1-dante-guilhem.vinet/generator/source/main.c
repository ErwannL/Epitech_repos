/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-guilhem.vinet
** File description:
** main
*/

#include "../include/my.h"

void free_struct(var_t *var)
{
    for (int i = 0; i != var->size_y; i++) {
        free(var->maze[i]);
    }
    free(var);
}

int init_struct(var_t *var, char **argv, int argc)
{
    var->size_x = my_str_to_int(argv[1]);
    var->size_y = my_str_to_int(argv[2]);
    if (var->size_x == 0 || var->size_y == 0) {
        free(var);
        return 84;
    }
    var->perfect = ((argc == 4 && my_strcmp(argv[3], "perfect") == 0)
    ? TRUE : FALSE);
    return (0);
}

var_t *create_var(var_t *var)
{
    var->i = 0;
    var->j = 0;
    var->random = 0;
    var->maze[var->i][var->j] = '*';
    var->finish = 0;
    var->unperfect = 0;
    var->rand_ok = 0;
    return (var);
}

int generator(var_t *var, int argc, char **argv)
{
    if (init_struct(var, argv, argc) == 84)
        return (84);
    var->maze = malloc(sizeof(char *) * (var->size_y + 1));
    for (int i = 0; i != var->size_y; i++) {
        var->maze[i] = malloc(sizeof(char) * (var->size_x + 1));
    }
    for (int i = 0; i != var->size_y; i++) {
        for (int j = 0; j != var->size_x; j++) {
            var->maze[i][j] = var->size_x == 1 || var->size_y == 1 ? '*' : 'X';
        }
    }
    var = create_var(var);
    ((var->size_x == 1 || var->size_y == 1) ? (0) : (var = create_maze(var)));
    print_maze(var);
    free_struct(var);
    return 0;
}

int main(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));

    srand(time(NULL));
    if (argc < 3) {
        free(var);
        return 84;
    } else if ((argc == 3 && my_is_num(argv[1]) == 0
    && my_is_num(argv[2]) == 0) || (argc == 4 && my_is_num(argv[1]) == 0
    && my_is_num(argv[2]) == 0 && my_strcmp(argv[3], "perfect") == 0)) {
        return generator(var, argc, argv);
    } else {
        free(var);
        return 84;
    }
}
