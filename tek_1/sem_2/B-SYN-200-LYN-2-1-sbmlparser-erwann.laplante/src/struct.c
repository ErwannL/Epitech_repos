/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** struct
*/

#include "my.h"

int free_all(int exit_val, var_t *var)
{
    free(var->i_flag_struct);
    free(var->no_flag_struct);
    free(var->flag);
    free(var->elements);
    free(var->good_chained);
    free(var->bad_chained);
    free(var->buf);
    free(var);
    return exit_val;
}

var_t *detect_flag(var_t *var, char **av, int i)
{
    if (strcmp(av[i], "-i") == 0 && av[i + 1])
        var->flag->i_flag++;
    if (strcmp(av[i], "-e") == 0)
        var->flag->e_flag++;
    if (strcmp(av[i], "-json") == 0)
        var->flag->json_flag++;
    if (strcmp(av[i], "-i") == 0 && (!av[i + 1] || av[i + 1][0] == '-'))
        var->r_val = 84;
    return var;
}

var_t *init_struct_bis(var_t *var, int ac, char **av)
{
    for (int i = 0; i != ac; i++) {
        if (av[i][0] == '-')
            var = detect_flag(var, av, i);
    }
    var->i_flag_struct = malloc(sizeof(i_flag_t));
    return var;
}

var_t *init_struct(var_t *var, int ac, char **av)
{
    var = malloc(sizeof(var_t));
    var->buf = NULL;
    var->fd = 0;
    var->re_error = 0;
    var->st_error = 0;
    var->bad_chained = malloc(sizeof(chained_t));
    var->bad_chained->name = NULL;
    var->bad_chained->next = NULL;
    var->good_chained = malloc(sizeof(chained_t));
    var->good_chained->name = NULL;
    var->good_chained->next = NULL;
    var->elements = malloc(sizeof(char) * 1);
    var->elem = 0;
    var->r_val = 0;
    var->flag = malloc(sizeof(flags_t));
    var->flag->e_flag = 0;
    var->flag->i_flag = 0;
    var->flag->json_flag = 0;
    var->no_flag_struct = malloc(sizeof(no_flag_t));
    return init_struct_bis(var, ac, av);
}
