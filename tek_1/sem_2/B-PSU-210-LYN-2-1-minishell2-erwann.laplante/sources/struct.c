/*
** EPITECH PROJECT, 2022
** B-PSU-101-LYN-1-1-minishell1-erwann.laplante
** File description:
** struct
*/

#include "../include/my.h"

var_t *init_struct(var_t *var, int argc, char **argv, char **env)
{
    var->line = 0;
    var->pid = 0;
    var->size = INT_MAX;
    var->buf = malloc(sizeof(char));
    var->home = malloc(sizeof(char));
    var->home = setup_home(var->home, env);
    var->argc = argc;
    var->argv = argv;
    var->env = env;
    var->here = malloc(sizeof(char));
    var->before = malloc(sizeof(char));
    var->buf_temp = malloc(sizeof(char));
    var->buf_temp2 = malloc(sizeof(char));
    var->dir = 0;
    return var;
}
