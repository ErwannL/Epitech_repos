/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** arguments_two
*/

#include "../include/my.h"

var_t *arg_pars_six(var_t *var, char **av, int i)
{
    if (my_strncmp(av[i], "--map-size=", my_strlen("--map-size=")) == 0) {
        for (int j = 0; j != my_strlen("--map-size="); av[i]++, j++);
        if (av[i][0] && my_str_is_int_coma(av[i]) == 0)
            var->arg->map_size[0] = my_str_to_int_coma(av[i]);
        else
            exit(84);
        for (int j = 0; j != my_int_len(var->arg->map_size[0]); av[i]++, j++);
        if (av[i][0] && my_str_is_int(av[i]) == 0)
            var->arg->map_size[1] = my_str_to_int(av[i]);
        else
            exit(84);
    }
    return var;
}
