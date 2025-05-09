/*
** EPITECH PROJECT, 2022
** private_palindrome
** File description:
** parsing
*/

#include "bonus.h"

var_t *print_invalid(var_t *var)
{
    dprintf(2, "invalid argument\n");
    var->r_val = 84;
    return var;
}

var_t *parsing_one(var_t *var, char **av, int i)
{
    if (av[i][0] != '-' && av[i - 1][0] != '-')
        return print_invalid(var);
    if (av[i][0] == '-' && (!av[i + 1] || my_str_is_int(av[i + 1]) == 84))
        return print_invalid(var);
    if (strcmp(av[i], "-n") == 0) {
        var->n_flag++;
        if (var->n_flag == 2)
            return print_invalid(var);
        var->number = my_str_to_int(av[i + 1]);
    }
    if (strcmp(av[i], "-b") == 0) {
        var->b_flag++;
        if (var->b_flag == 2)
            return print_invalid(var);
        var->base = my_str_to_int(av[i + 1]);
        if (var->base < 2 || var->base > 10)
            return print_invalid(var);
    }
    return var;
}

var_t *parsing_two(var_t *var, char **av, int i)
{
    if (strcmp(av[i], "-p") == 0) {
        var->p_flag++;
        if (var->p_flag == 2)
            return print_invalid(var);
        var->palindrome = my_str_to_int(av[i + 1]);
    }
    if (strcmp(av[i], "-imin") == 0) {
        var->imin_flag++;
        if (var->imin_flag == 2)
            return print_invalid(var);
        var->i_min = my_str_to_int(av[i + 1]);
    }
    if (strcmp(av[i], "-pn") == 0) {
        var->pn_flag++;
        if (var->pn_flag == 2)
            return print_invalid(var);
        var->pn = my_str_to_int(av[i + 1]);
    }
    return var;
}

var_t *parsing_three(var_t *var, char **av, int i)
{
    if (strcmp(av[i], "-imax") == 0) {
        var->imax_flag++;
        if (var->imax_flag == 2)
            return print_invalid(var);
        var->i_max = my_str_to_int(av[i + 1]);
    }
    if (strcmp(av[i], "-fn") == 0) {
        var->fn_flag++;
        if (var->fn_flag == 2)
            return print_invalid(var);
        var->fn = my_str_to_int(av[i + 1]);
    }
    if (av[i][0] == '-' && strcmp(av[i], "-n") != 0
    && strcmp(av[i], "-p") != 0 && strcmp(av[i], "-b") != 0
    && strcmp(av[i], "-imin") != 0 && strcmp(av[i], "-imax") != 0
    && strcmp(av[i], "-h") != 0 && strcmp(av[i], "-pn") != 0
    && strcmp(av[i], "-fn") != 0)
        return print_invalid(var);
    return var;
}

var_t *arg_parsing(var_t *var, char **av, int i)
{
    var = parsing_one(var, av, i);
    if (var->r_val == 84)
        return var;
    var = parsing_two(var, av, i);
    if (var->r_val == 84)
        return var;
    var = parsing_three(var, av, i);
    if (var->r_val == 84)
        return var;
    return var;
}
