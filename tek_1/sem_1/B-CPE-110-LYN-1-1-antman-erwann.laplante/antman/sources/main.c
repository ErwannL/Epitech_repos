/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** main
*/

#include "../include/my.h"

void print_h(void)
{
    my_putstr("File compressor\n\nUSAGE\n ./antman 'file' 'mode' >");
    my_putstr(" 'compressed file'\n or \n ./a");
    my_putstr("ntman 'options'\n\nOPTIONS\n -h     print the usage and quit.");
    my_putstr("\n\nMODE\n 1 corresponds to text files containing song lyrics");
    my_putstr(".\n 2 corresponds to HTML files.\n 3 corresponds to P3 PPM im");
    my_putstr("age.\n");
}

int antman_bis(char **av, variable_t var, dlist_node_t *my_list, char *str)
{
    if (my_strcmp(av[2], "1") == 0 || my_strcmp(av[2], "2") == 0
    || my_strcmp(av[2], "3") == 0) {
        var = reading_file(var, av[1]);
        if (var.error != 0)
            return (var.error == 84 ? 84 : 0);
        start_mode(var, av[2]);
    } else {
        my_putstr("Bad mode.\nTry with -h.\n");
        return 84;
    }
}

int antman(char **av, variable_t var, dlist_node_t *my_list, char *str)
{
    int num;

    if (my_strcmp(av[2], "-h") == 0) {
        print_h();
    } else
        num = antman_bis(av, var, my_list, str);
    if (num == 84)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    variable_t var;
    dlist_node_t *my_list = malloc(sizeof(*my_list));
    char *str;

    if (ac == 3) {
        return antman(av, var, my_list, str);
    } else if (ac == 1) {
        my_putstr("Need a file and a compression mode.\nTry with -h.\n");
        return 84;
    } else {
        if (my_strcmp(av[1], "-h") == 0) {
            print_h();
            return 0;
        } else {
            my_putstr("Need a file and a compression mode.\nTry with -h.\n");
            return 84;
        }
    }
}
