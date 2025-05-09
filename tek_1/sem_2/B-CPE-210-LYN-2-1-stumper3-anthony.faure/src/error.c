/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper3-anthony.faure
** File description:
** error
*/

#include "../include/my.h"

int no_s_no_n(char *str)
{
    if (my_strcmp(str, "-s") != 0 && my_strcmp(str, "-n") != 0)
        return 0;
    return 84;
}

int find_flag_s(char **av, int i, numbers_t *num)
{
    if (av[i + 1] && my_str_is_printable(av[i + 1]) == 0) {
        num->string = malloc(sizeof(char) * (my_strlen(av[i + 1]) + 1));
        num->string = my_strcpy(num->string, av[i + 1]);
    } else {
        return 84;
    }
    return 0;
}

int find_flag_n(char **av, int i, numbers_t *num)
{
    if (av[i + 1] && my_str_is_int(av[i + 1]) == 0) {
        num->to_print = malloc(sizeof(char) * (my_strlen(av[i + 1]) + 1));
        num->to_print = my_strcpy(num->to_print, av[i + 1]);
    } else {
        return 84;
    }
    return 0;
}

int error_handling(int argc, char **av, numbers_t *num)
{
    int find_n = 0;
    int value = 0;

    if (argc != 3 && argc != 5)
        return 84;
    for (int i = 1; i != argc; i++) {
        if (my_strcmp(av[i], "-n") == 0) {
            find_n += 1;
            value = find_flag_n(av, i, num);
        }
        if (my_strcmp(av[i], "-s") == 0)
            value = find_flag_s(av, i, num);
        if (value == 84)
            return 84;
        if (no_s_no_n(av[i]) == 0 && no_s_no_n(av[i - 1]) == 0)
            return 84;
    }
    if (find_n != 1)
        return 84;
    return 0;
}
