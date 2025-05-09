/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-bsmyls-erwann.laplante
** File description:
** my_ls
*/

#include "../includes/my.h"

variables_t check_if_flag_or_not(variables_t var, int ac, char **av, int i)
{
    if (av[i][0] == '-') {
        var.if_flags++;
        var = check_flag_function(var, av, ac, i);
    } else {
        my_putstr("ls: cannot access '");
        my_putstr(av[i]);
        my_putstr("': No such file or directory\n");
        var.return_value = 84;
    }
    return (var);
}

int check_if_file_exists(const char *filename)
{
    struct stat buffer;
    int exist = stat(filename, &buffer);

    if (exist == 0)
        return 1;
    else
        return 0;
}

int check_if_no_enter(int ac, char **av)
{
    int a = ac;
    int b = 0;
    int c = 0;

    if (ac == 1)
        return (0);
    for (int i = 1; i != ac; i++) {
        if (av[i][0] == '-')
            a--;
        if (av[i][0] == '-' && av[i][1] == 'd')
            b = 1;
        if (av[i][0] == '-' && av[i][1] == 'r')
            c = 1;
    }
    return (a == 1 && b == 1 ? 2 : a == 1 ? 0 : b == 1 && c == 1 ? 4 : b == 1\
    ? 3 : c == 1 ? 4 : 1);
}

variables_t dec_var(variables_t var, int ac, char **av)
{
    var.param1 = malloc(sizeof(int) * ac);
    var.j = 0;
    var.param2 = malloc(sizeof(int) * ac);
    var.k = 0;
    var.flags = malloc(sizeof(int) * 5);
    var.return_value = 0;
    var.if_flags = 0;
    var.num = 0;
    var.st = malloc(sizeof(struct stat));
    for (int i = 1; i < ac; i++)
        ((av[i][0] == '-') ? var.if_flags++ : 0);
    return (var);
}

int main(int ac, char **av)
{
    variables_t var;
    int num;

    var = dec_var(var, ac, av);
    ((var.if_flags == 0) ? sort_word_array2(ac, av) : 0);
    num = check_if_no_enter(ac, av);
    ((num == 0) ? var = display(opendir("."), var), my_putchar('\n'), exit(0)\
    : ((num == 2) ? my_putstr(".\n"), exit(0) : ((num == 3) ?\
    sort_word_array2(ac, av) : ((num == 4) ? sort_word_array3(ac, av) : 0))));
    for (int i = 1; i < ac; i++) {
        stat(av[i], var.st);
        if (check_if_file_exists(av[i]) == 0)
            var = check_if_flag_or_not(var, ac, av, i);
        else if (S_ISREG(var.st->st_mode))
            var.param1[var.j++] = i;
        else
            var.param2[var.k++] = i;
    }
    return (display_good_order(var, av, ac));
}
