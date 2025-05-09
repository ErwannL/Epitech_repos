/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** args
*/

#include "../include/c_test.h"

pars_t finish_args(int ac, char **av, int i, pars_t my_pars)
{
    if (strcmp(av[i], "-d") == 0 || strcmp(av[i], "--detail") == 0)
        my_pars.details = true;
    else {
        if (strcmp(av[i], "-b") == 0 || strcmp(av[i], "--bonus") == 0)
            my_pars.bonus = true;
        else {
            printf("\nunknown flag [%s], try -h or --help\n", av[i]);
            my_pars.r = 84;
            return my_pars;
        }
    }
    return my_pars;
}

pars_t pars_args(int ac, char **av, int i, pars_t my_pars)
{
    if (strcmp(av[i], "-h") == 0 || strcmp(av[i], "--help") == 0) {
        print_help();
        my_pars.r = 1;
        return my_pars;
    } else {
        if (strcmp(av[i], "-c") == 0 || strcmp(av[i], "--color") == 0)
            my_pars.color = true;
        else
            return finish_args(ac, av, i, my_pars);
    }
    return my_pars;
}
