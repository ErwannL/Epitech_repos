/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-palindrome-erwann.laplante
** File description:
** debug
*/

#include "bonus.h"

int comparing_debug_next_next(char **av, int i, var_t *var)
{
    if (strcmp(av[i], "-imax") == 0) {
        var->imax_flag++;
        if (var->imax_flag == 2)
            return print_error("two time flag imax", var);
        var->i_max = my_str_to_int(av[i + 1]);
    }
    if (strcmp(av[i], "-fn") == 0) {
        var->fn_flag++;
        if (var->fn_flag == 2)
            return print_error("two time flag fn", var);
        var->fn = my_str_to_int(av[i + 1]);
    }
    if (av[i][0] == '-' && strcmp(av[i], "-n") != 0
    && strcmp(av[i], "-p") != 0 && strcmp(av[i], "-b") != 0
    && strcmp(av[i], "-imin") != 0 && strcmp(av[i], "-imax") != 0
    && strcmp(av[i], "-h") != 0 && strcmp(av[i], "-pn") != 0
    && strcmp(av[i], "-d") != 0 && strcmp(av[i], "-fn") != 0)
        return print_error("bad flag", var);
    return -1;
}

int comparing_debug_next(char **av, int i, var_t *var)
{
    if (strcmp(av[i], "-p") == 0) {
        var->p_flag++;
        if (var->p_flag == 2)
            return print_error("two time flag p", var);
        var->palindrome = my_str_to_int(av[i + 1]);
    }
    if (strcmp(av[i], "-imin") == 0) {
        var->imin_flag++;
        if (var->imin_flag == 2)
            return print_error("two time flag imin", var);
        var->i_min = my_str_to_int(av[i + 1]);
    }
    if (strcmp(av[i], "-pn") == 0) {
        var->pn_flag++;
        if (var->pn_flag == 2)
            return print_error("two time flag pn", var);
        var->pn = my_str_to_int(av[i + 1]);
    }
    return comparing_debug_next_next(av, i, var);
}

int comparing_debug(char **av, int i, var_t *var)
{
    if (av[i][0] != '-' && av[i - 1][0] != '-')
        return print_error("no flag before one argument", var);
    if (strcmp(av[i], "-d") != 0 && av[i][0] == '-' && (!av[i + 1]
    || my_str_is_int(av[i + 1]) == 84))
        return print_error("no int after one flag", var);
    if (strcmp(av[i], "-n") == 0) {
        var->n_flag++;
        if (var->n_flag == 2)
            return print_error("two time flag n", var);
        var->number = my_str_to_int(av[i + 1]);
    }
    if (strcmp(av[i], "-b") == 0) {
        var->b_flag++;
        if (var->b_flag == 2)
            return print_error("two time flag b", var);
        var->base = my_str_to_int(av[i + 1]);
        if (var->base < 2 || var->base > 10)
            return print_error("base need to be between 2 & 10", var);
    }
    return comparing_debug_next(av, i, var);
}

int print_end_error(var_t *var)
{
    if (var->pn_flag != 0 && var->n_flag != 0)
        return print_error("n flag & pn flag", var);
    if (var->fn_flag != 0 && var->n_flag != 0)
        return print_error("fn flag & n flag", var);
    if (var->pn_flag != 0 && var->fn_flag != 0)
        return print_error("fn flag & pn flag", var);
    if (var->p_flag != 0 && var->fn_flag != 0)
        return print_error("fn flag & p flag", var);
    if (var->p_flag == 0 && var->n_flag == 0 && var->pn_flag == 0
    && var->fn_flag == 0)
        return print_error("no p flag & no n flag & no pn flag & no fn flag"
        , var);
    if (var->p_flag != 0 && my_strcmp_free(convert_from_deci(var->base
    , var->palindrome), 1, my_revstr(convert_from_deci(var->base
    , var->palindrome)), 1) != 0)
        return print_error("no palindrome after p flag", var);
    if (var->pn_flag != 0 && my_strcmp_free(convert_from_deci(var->base
    , var->pn), 1, my_revstr(convert_from_deci(var->base, var->pn)), 1) != 0)
        return print_error("no palindrome after pn flag", var);
    return -1;
}

int debug_fonction(var_t *var, int ac, char **av)
{
    if (ac < 4)
        return print_error("too few argument", var);
    if (ac > 10)
        return print_error("too many argument", var);
    for (int i = 1; i != ac; i++)
        if (comparing_debug(av, i, var) == 0)
            return 0;
    if (var->i_max < var->i_min)
        return print_error("i min inferior to i_max", var);
    if (var->p_flag != 0 && var->n_flag != 0)
        return print_error("n flag & p flag", var);
    if (var->p_flag != 0 && var->pn_flag != 0)
        return print_error("pn flag & p flag", var);
    if (print_end_error(var) == 0)
        return 0;
    printf("number = %i\np palindrome = %i\nbase = %i\ni min = %i\ni max = %i\
    \npn palindrome = %i\nfn number = %i\n", var->number, var->palindrome
    , var->base, var->i_min, var->i_max, var->pn, var->fn);
    free(var);
    return 0;
}
