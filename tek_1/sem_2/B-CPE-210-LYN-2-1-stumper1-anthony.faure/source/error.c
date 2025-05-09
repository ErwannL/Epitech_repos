/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper1-anthony.faure
** File description:
** error
*/

#include "../include/my.h"

int error_arg(void)
{
    my_putstr("arguments error\n", 2);
    return 84;
}

int check_char(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] != '#' && str[i] != '.' && str[i] != '@')
            return 84;
    }
    return 0;
}

int check_content(char *str, char *str2)
{
    int nb = 0;
    int nb2 = 0;

    if (my_strlen(str) != my_strlen(str2))
        return 84;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '@')
            nb += 1;
    }
    for (int i = 0; str2[i] != '\0'; i += 1) {
        if (str2[i] == '@')
            nb2 += 1;
    }
    if (nb != nb2)
        return 84;
    return 0;
}

int nb_is_nb(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < 48 || str[i] > 57)
            return 84;
    }
    return 0;
}

int check_errors(char **argv)
{
    if (nb_is_nb(argv[1]) == 84)
        return 84;
    if (check_char(argv[2]) == 84 || check_char(argv[3]) == 84)
        return 84;
    if (check_content(argv[2], argv[3]) == 84)
        return 84;
    return 0;
}
