/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** arguments
*/

#include "../include/my.h"

var_t *arg_pars_five(var_t *var, char **av, int i)
{
    if (my_strncmp(av[i], "--key-quit=", my_strlen("--key-quit=")) == 0) {
        for (int j = 0; j != my_strlen("--key-quit="); av[i]++, j++);
        if (av[i][0] && my_str_is_int(av[i]) == 0)
            var->arg->key_quit = my_str_to_int(av[i]);
        else
            exit(84);
    }
    if (my_strncmp(av[i], "--key-pause="
    , my_strlen("--key-pause=")) == 0) {
        for (int j = 0; j != my_strlen("--key-pause="); av[i]++, j++);
        if (av[i][0] && my_str_is_int(av[i]) == 0)
            var->arg->key_pause = my_str_to_int(av[i]);
        else
            exit(84);
    }
    return arg_pars_six(var, av, i);
}

var_t *arg_pars_four(var_t *var, char **av, int i)
{
    if (my_strncmp(av[i], "--key-turn=", my_strlen("--key-turn=")) == 0) {
        for (int j = 0; j != my_strlen("--key-turn="); av[i]++, j++);
        if (av[i][0] && my_str_is_int(av[i]) == 0)
            var->arg->key_turn = my_str_to_int(av[i]);
        else
            exit(84);
    }
    if (my_strncmp(av[i], "--key-drop=", my_strlen("--key-drop=")) == 0) {
        for (int j = 0; j != my_strlen("--key-drop="); av[i]++, j++);
        if (av[i][0] && my_str_is_int(av[i]) == 0)
            var->arg->key_drop = my_str_to_int(av[i]);
        else
            exit(84);
    }
    return arg_pars_five(var, av, i);
}

var_t *arg_pars_three(var_t *var, char **av, int i)
{
    if (my_strncmp(av[i], "--key-left=", my_strlen("--key-left=")) == 0) {
        for (int j = 0; j != my_strlen("--key-left="); av[i]++, j++);
        if (av[i][0] && my_str_is_int(av[i]) == 0)
            var->arg->key_left = my_str_to_int(av[i]);
        else
            exit(84);
    }
    if (my_strncmp(av[i], "--key-right="
    , my_strlen("--key-right=")) == 0) {
        for (int j = 0; j != my_strlen("--key-right="); av[i]++, j++);
        if (av[i][0] && my_str_is_int(av[i]) == 0)
            var->arg->key_right = my_str_to_int(av[i]);
        else
            exit(84);
    }
    return arg_pars_four(var, av, i);
}

var_t *arg_pars_two(var_t *var, char **av, int i)
{
    if (my_strcmp(av[i], "-q") == 0 && av[i + 1]
    && my_str_is_int(av[i + 1]) == 0)
        var->arg->key_quit = my_str_to_int(av[i + 1]);
    if (my_strcmp(av[i], "-p") == 0 && av[i + 1]
    && my_str_is_int(av[i + 1]) == 0)
        var->arg->key_pause = my_str_to_int(av[i + 1]);
    if (my_strcmp(av[i], "-w") == 0 || my_strncmp(av[i], "--without-next"
    , my_strlen("--without-next")) == 0)
        var->arg->without_next = TRUE;
    if (my_strncmp(av[i], "--level=", my_strlen("--level=")) == 0) {
        for (int j = 0; j != my_strlen("--level="); av[i]++, j++);
        if (av[i][0] && my_str_is_int(av[i]) == 0)
            var->arg->level = my_str_to_int(av[i]);
        else
            exit(84);
    }
    return arg_pars_three(var, av, i);
}

var_t *arg_pars(var_t *var, int ac, char **av)
{
    for (int i = 1; i != ac; i++) {
        if (my_strcmp(av[i], "-L") == 0 && av[i + 1]
        && my_str_is_int(av[i + 1]) == 0)
            var->arg->level = my_str_to_int(av[i + 1]);
        if (my_strcmp(av[i], "-l") == 0 && av[i + 1]
        && my_str_is_int(av[i + 1]) == 0)
            var->arg->key_left = my_str_to_int(av[i + 1]);
        if (my_strcmp(av[i], "-r") == 0 && av[i + 1]
        && my_str_is_int(av[i + 1]) == 0)
            var->arg->key_right = my_str_to_int(av[i + 1]);
        if (my_strcmp(av[i], "-t") == 0 && av[i + 1]
        && my_str_is_int(av[i + 1]) == 0)
            var->arg->key_turn = my_str_to_int(av[i + 1]);
        if (my_strcmp(av[i], "-d") == 0 && av[i + 1]
        && my_str_is_int(av[i + 1]) == 0)
            var->arg->key_drop = my_str_to_int(av[i + 1]);
        var = arg_pars_two(var, av, i);
    }
    return var;
}
