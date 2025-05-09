/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myls-erwann.laplante
** File description:
** my_ls2
*/

#include "../includes/my.h"

variables_t display(DIR *directori, variables_t var)
{
    char **param = malloc(sizeof(char *) * INT_MAX);
    int j = 0;

    while ((var.dirent = readdir(directori)) != 0) {
        if ((var.dirent->d_name[0] != '.')) {
            param[j] = var.dirent->d_name;
            j++;
            var.num++;
        }
    }
    sort_word_array1(j, param);
    return (var);
}

variables_t display_basic_bis(variables_t var, char **av, int ac)
{
    for (int i = 0; var.param2[i] != -1; i++) {
        if (ac != 2) {
            my_putstr(av[var.param2[i]]);
            my_putstr(":\n");
        }
        var = display(opendir(av[var.param2[i]]), var);
        if (var.param2[i + 1] != -1)
            my_putstr("\n\n");
        else
            my_putstr("\n");
    }
    return (var);
}

variables_t display_basic(variables_t var, char **av, int ac)
{
    for (int i = 0; var.param1[i] != -1; i++) {
        my_putstr(av[var.param1[i]]);
        ((var.param1[i + 1] != -1) ? my_putstr("  ") : 0);
    }
    if (var.param1[0] != -1) {
        if (var.flags[2] != 0)
            my_putstr("  ");
        else if (var.param2[0] == -1)
            my_putstr("\n");
        else
            my_putstr("\n\n");
    }
    var = display_basic_bis(var, av, ac);
    return (var);
}

int display_good_order(variables_t var, char **av, int ac)
{
    int a = 0;

    var.param1[var.j] = -1;
    var.param2[var.k] = -1;
    if (var.if_flags == 0)
        var = display_basic(var, av, ac);
    if (var.flags[2] != 0) {
        var = display_good_order_d(var, av, a, ac);
        my_putstr("\n");
    }
    if (var.flags[3] != 0) {
        var = display_good_order_r(var, av, a, ac);
    }
    return (var.return_value);
}

variables_t check_flag_function(variables_t var, char **av, int ac, int i)
{
    av[i]++;
    while (av[i][0] != '\0') {
        if (av[i][0] == 'l')
            var.flags[0] = 1;
        if (av[i][0] == 'R')
            var.flags[1] = 1;
        if (av[i][0] == 'd')
            var.flags[2] = 1;
        var = check_flag_function2(var, av, i);
        av[i]++;
    }
    return var;
}
