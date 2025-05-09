/*
** EPITECH PROJECT, 2022
** B-PSU-101-LYN-1-1-minishell1-erwann.laplante
** File description:
** main
*/

#include "../include/my.h"

void print_start(var_t *var)
{
    my_putchar('*');
    my_put_nbr(getpid());
    my_putstr("* -> ");
    var = setup_here(var);
    my_putstr(var->here);
    my_putstr(" > ");
}

void command_bis(var_t *var)
{
    if (my_strncmp(var->buf, "cd", 2) == 0) {
        var = cd_f(var);
    } else if (my_strncmp(var->buf, "ls", 2) == 0) {
        var = ls_f(var);
    } else {
        my_putstr("command not found: ");
        my_putstr(var->buf);
        my_putchar('\n');
    }
}

void command(var_t *var)
{
    if (my_strcmp(var->buf, "exit") == 0) {
        exit(0);
    } else if (my_strcmp(var->buf, "pwd") == 0) {
        var = pwd_f(var);
    } else {
        command_bis(var);
    }
}

void minishell(var_t *var)
{
    var->home = setup_home(var->home, var->env);
    var->before = my_strcpy(var->before, getcwd(var->buf, var->size));
    while (1) {
        print_start(var);
        var->line = getline(&var->buf, &var->size, stdin);
        if (var->line == -1) {
            my_putchar('\n');
            exit(0);
        } else if (my_strlen(var->buf) == 1) {
            my_putchar('\0');
        } else {
            var->buf = my_strncpy(var->buf, var->buf, my_strlen(var->buf) - 2);
            var->buf = clean_string(var->buf);
            command(var);
        }
    }
}

int main(int argc, char **argv, char **env)
{
    var_t *var = malloc(sizeof(var_t));

    var = init_struct(var, argc, argv, env);
    if (var->argc != 1) {
        my_putstr("Too many argument");
        return 84;
    } else {
        minishell(var);
    }
    return 0;
}
