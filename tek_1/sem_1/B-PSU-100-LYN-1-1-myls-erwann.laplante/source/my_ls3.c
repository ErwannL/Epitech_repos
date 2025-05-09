/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myls-erwann.laplante
** File description:
** my_ls2
*/

#include "../includes/my.h"

variables_t display_good_order_d(variables_t var, char **av, int a, int ac)
{
    for (; var.param1[0] != -1 || var.param2[0] != -1; a++) {
        if (a != 0)
            my_putstr("  ");
        if (var.param1[0] == -1) {
            my_putstr(av[var.param2[0]]);
            var.param2++;
        } else if (var.param2[0] == -1) {
            my_putstr(av[var.param1[0]]);
            var.param1++;
        } else {
            ((var.param1[0] - var.param2[0] > 0) ?\
            (my_putstr(av[var.param2[0]]), var.param2++) :\
            (my_putstr(av[var.param1[0]]), var.param1++));
        }
    }
    return (var);
}

variables_t display_r(DIR *directori, variables_t var)
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
    sort_word_array4(j, param);
    return (var);
}

variables_t display_good_order_r(variables_t var, char **av, int a, int ac)
{
    for (int i = 0; var.param1[i] != -1; i++) {
        my_putstr(av[var.param1[i]]);
        ((var.param1[i + 1] != -1) ? my_putstr("  ") : 0);
    }
    if (var.param1[0] != -1) {
        var.flags[2] != 0 ? my_putstr("  ") : var.param2[0] == -1 ?\
        my_putstr("\n") : my_putstr("\n\n");
    }
    for (int i = 0; var.param2[i] != -1; i++) {
        ac != 2 ? my_putstr(av[var.param2[i]]), my_putstr(":\n") : 0;
        var = display_r(opendir(av[var.param2[i]]), var);
        var.param2[i + 1] != -1 ? my_putstr("\n\n") : my_putstr("\n");
    }
    return (var);
}

variables_t check_flag_function2(variables_t var, char **av, int i)
{
    if (av[i][0] == 'r')
        var.flags[3] = 1;
    if (av[i][0] == 't')
        var.flags[4] = 1;
    return (var);
}
