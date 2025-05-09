/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper2-anthony.faure
** File description:
** main
*/

#include "../include/my.h"

int do_action(var_t *vars, char *str)
{
    int i = 1;

    vars->nb = my_getnbr(str);
    if (vars->nb > vars->width || vars->nb <= 0)
        return 0;
    if (vars->map[1][vars->nb] != '.')
        return 0;
    for (i = 1; vars->map[i][vars->nb] == '.'; i += 1);
    i -= 1;
    if (vars->player == 1) {
        vars->map[i][vars->nb] = vars->p1;
        vars->player = 2;
    } else {
        vars->map[i][vars->nb] = vars->p2;
        vars->player = 1;
    }
    return 1;
}

int check_input(char *str)
{
    if (my_strlen(str) < 2)
        return 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < 48 || str[i] > 57)
            return 0;
    }
    return 1;
}

int input(var_t *vars)
{
    size_t n = 0;
    int nb;
    char *line = NULL;

    print_ask(vars);
    if (nb = getline(&line, &n, stdin) != -1) {
        while (do_action(vars, line) == 0 && check_input(line) == 0) {
            print_ask(vars);
            nb = getline(&line, &n, stdin);
        }
        if (is_a_tie(vars) == 84)
            return print_tie(vars, line);
        if (check_victory(vars) == 1 || check_victory(vars) == 2)
            return print_vic(vars, line);
        print_map(vars);
    }
    free(line);
    return 0;
}

int main(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));

    fill_vars(var);
    if (options(var, argv, argc) == 84) {
        free(var);
        return print_error();
    }
    var = creat_map(var);
    while (input(var) == 0);
    for (int i = 0; i != var->height + 2; i++)
        free(var->map[i]);
    free(var->map);
    free(var);
    return 0;
}
