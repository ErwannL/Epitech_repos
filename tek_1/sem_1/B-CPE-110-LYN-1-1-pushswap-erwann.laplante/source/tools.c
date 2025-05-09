/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-pushswap-erwann.laplante
** File description:
** my_pushswap
*/

#include"../includes/my.h"

int check_error(int ac, char **av)
{
    int return_val = 0;

    for (int i = 1; i != ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            av[i][j] != '0' && av[i][j] != '1' && av[i][j] != '2' &&\
            av[i][j] != '3' && av[i][j] != '4' && av[i][j] != '5' && av[i][j]\
            != '6' && av[i][j] != '7' && av[i][j] != '8' && av[i][j] != '9' &&\
            av[i][j] != '-' ? return_val = 84 : 0;
        }
    }
    return (return_val);
}

int is_sort(int ac, char **av)
{
    if (ac == 1) {
        return (0);
    }
    for (int i = 0, j = i + 1; i < ac - 1; i++, j++) {
        if (my_getnbr(av[i]) > my_getnbr(av[j])) {
            return (84);
        }
    }
    return (0);
}

int find_min(int ac, char **av, int min)
{
    for (int i = 0; i < ac; i++) {
        if (min > my_getnbr(av[i])) {
            min = my_getnbr(av[i]);
        }
    }
    return (min);
}

char **move_av(int ac, char **av)
{
    char *tmp = av[0];

    for (int i = 1; i < ac; i++) {
        av[i - 1] = av[i];
    }
    av[ac - 1] = tmp;
    return (av);
}

char **move_back_av(int ac, char **av)
{
    char *tmp = av[ac - 1];

    for (int i = ac - 1; i > 0; i--) {
        av[i] = av[i - 1];
    }
    av[0] = tmp;
    return (av);
}
