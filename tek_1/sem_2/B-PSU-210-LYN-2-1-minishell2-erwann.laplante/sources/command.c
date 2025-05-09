/*
** EPITECH PROJECT, 2022
** B-PSU-101-LYN-1-1-minishell1-erwann.laplante
** File description:
** command
*/

#include "../include/my.h"

var_t *pwd_f(var_t *var)
{
    getcwd(var->buf, var->size);
    my_putstr(var->buf);
    my_putchar('\n');
}

var_t *cd_f_bis(var_t *var)
{
    if (my_strcmp(var->buf, "-") == 0) {
        my_putstr(var->before);
        my_putchar('\n');
        getcwd(var->buf_temp, var->size);
        chdir(var->before);
        var->buf_temp2 = var->before;
        var->before = var->buf_temp;
        var->buf_temp = var->buf_temp2;
    } else {
        getcwd(var->before, var->size);
        var->dir = chdir(var->buf);
        if (var->dir == -1)
            my_putstr("wrong directory\n");
    }
}

var_t *cd_f(var_t *var)
{
    my_putstr(var->buf);
    var->buf++;
    var->buf++;
    var->buf++;
    if (my_strlen(var->buf) == 0
    || my_strcmp(var->buf, "~") == 0) {
        var->buf[0] = '~';
        var->buf[1] = '\0';
        getcwd(var->before, var->size);
        while (my_strcmp("/", getcwd(var->buf, var->size)) != 0)
            chdir("../");
        var->home = setup_home(var->home, var->env);
        chdir(var->home);
    } else if (my_strcmp(var->buf, "..") == 0
    || my_strcmp(var->buf, "../") == 0) {
        getcwd(var->before, var->size);
        chdir("../");
    } else
        var = cd_f_bis(var);
    return var;
}

var_t *ls_f(var_t *var)
{
    var->buf++;
    var->buf++;
    var->buf++;
    var->pid = fork();
    if (var->pid == 0) {
        execve("/bin/ls", var->argv, var->env);
        exit(127);
    } else {
        wait(NULL);
    }
    return var;
}
