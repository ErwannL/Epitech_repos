/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-solostumper01-erwann.laplante
** File description:
** main
*/

#include "../include/my.h"

int test_function(char c)
{
    if (c != ' ' && c != '\t')
        return 0;
    return 1;
}

void clean_string(char *str)
{
    int state = 0;

    while ((test_function(str[0]) == 1) && (str[1] != '\0'))
        str++;
    for (int i = 0; str[i] != '\0'; i++) {
        if (test_function(str[i]) == 0) {
            my_putchar(str[i]);
            state = 1;
        } else if ((test_function(str[i]) == 1) && state == 1
        && str[i + 1] != '\0' && test_function(str[i + 1]) == 0) {
            my_putchar(' ');
            state = 0;
        }
    }
}

int main(int ac, char **av)
{
    if (ac > 2) {
        my_putstr("too many arguments\n");
        return 84;
    } else if (ac == 2) {
        clean_string(av[1]);
    }
    my_putchar('\n');
    return 0;
}
