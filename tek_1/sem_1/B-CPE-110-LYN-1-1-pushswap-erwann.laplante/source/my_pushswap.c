/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-pushswap-erwann.laplante
** File description:
** my_pushswap
*/

#include"../includes/my.h"

int help_main(int ac, char **av)
{
    int c = 0;

    while (ac != 1) {
        if (is_sort(ac, av) == 0)
            return (c);
        if (my_getnbr(av[0]) == find_min(ac, av, my_getnbr(av[0]))) {
            my_putstr("pb ");
            av++;
            ac--;
            c++;
        } else if (my_getnbr(av[ac - 1]) ==\
        find_min(ac, av, my_getnbr(av[ac- 1]))) {
            my_putstr("rra ");
            av = move_back_av(ac, av);
        } else {
            my_putstr("ra ");
            av = move_av(ac, av);
        }
    }
    return (c);
}

int main(int ac, char **av)
{
    int c = 0;

    if (ac == 1 || check_error(ac, av) == 84)
        return (84);
    av++;
    ac--;
    if (is_sort(ac, av) == 0) {
        my_putchar('\n');
        return (0);
    }
    c = help_main(ac, av);
    for (int i = c; i != 1; i--, my_putstr("pa "));
    my_putstr("pa\n");
    return (0);
}
