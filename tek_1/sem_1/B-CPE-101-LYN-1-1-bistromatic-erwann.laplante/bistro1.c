/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** bistro1
*/

#include"include/my.h"
#include <unistd.h>
#include <stdlib.h>

int erro2_2(char **av, int i)
{
    for (int j = i + 1; av[1][j] != '\0'; j++) {
        if (av[1][i] == av[1][j])
            return (84);
    }
}

int erro2_1(char **av, int i)
{
    for (int j = 0; av[2][j] != '\0'; j++) {
        if (av[1][i] == av[2][j])
            return (84);
    }
}

int error2(char **av)
{
    if (my_strlen(av[2]) != 7)
        return (84);
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (erro2_1(av, i) == 84)
            return (84);
    }
    for (int i = 0; av[1][i + 1] != '\0'; i++) {
        if (erro2_2(av, i) == 84)
            return (84);
    }
    for (int i = 0; av[2][i + 1] != '\0'; i++) {
        if (erro2_3(av, i) == 84)
            return (84);
    }
    return (0);
}

int error(int ac, char **av)
{
    int i = my_getnbr(av[3]);
    int buff_size = i + 1;
    char buffer[buff_size];

    if (error2(av) == 84)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_putstr("USAGE\n./calc base operators size_read\n\nDESCRIPTION\n- ");
        my_putstr("base: all the symbols of the base\n- operators: the symbo");
        my_putstr("ls for the parentheses and the 5 operators\n- size_read: ");
        my_putstr("number of characters to be read\n");
        return (0);
    }
    if (ac == 4 && my_strlen(av[2]) == 7) {
        read(0, buffer, buff_size);
        buffer[buff_size] = '\0';
        eval_expr(buffer, av[1], av[2], av[3]);
        return (0);
    }
    return (84);
}

int main(int ac, char **av)
{
    int return_value = error(ac, av);
    if (return_value == 84)
        write(2, SYNTAX_ERROR_MSG, 12);
    return (return_value);
}
