/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper2-anthony.faure
** File description:
** options
*/

#include "../include/my.h"

int find_opt(char *str)
{
    if (my_strcmp(str, "-w") == 0)
        return 1;
    if (my_strcmp(str, "-h") == 0)
        return 2;
    if (my_strcmp(str, "-p1") == 0)
        return 3;
    if (my_strcmp(str, "-p2") == 0)
        return 4;
    if (my_strcmp(str, "-a") == 0)
        return 5;
    return 0;
}

int find_int(char *str)
{
    if (str[0] < 48 || str[0] > 57)
        return 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < 48 || str[i] > 57)
            return 0;
    }
    return my_atoi(str);
}

char find_char(char *str)
{
    if (my_strlen(str) != 1)
        return 0;
    if (str[0] < 32 || str[0] > 176)
        return 0;
    if (str[0] == '.' || str[0] == '|' || str[0] == '+')
        return 0;
    return str[0];
}

void choose_opt(char *opt, char *str, var_t *vars)
{
    switch (find_opt(opt)) {
        case 1:
            vars->width = find_int(str);
            break;
        case 2:
            vars->height = find_int(str);
            break;
        case 3:
            vars->p1 = find_char(str);
            break;
        case 4:
            vars->p2 = find_char(str);
            break;
        case 5:
            vars->ref = find_char(str);
            break;
        default:
            return;
    }
    return;
}

int options(var_t *vars, char **argv, int argc)
{
    if (argc == 1)
        return 0;
    argc -= 1;
    for (int i = 1; i != argc; i += 1)
        choose_opt(argv[i], argv[i + 1], vars);
    if (vars->width > 80)
        return 84;
    if (vars->height > 16)
        return 84;
    if ((vars->height * vars->width) < 20)
        return 84;
    if (vars->p1 == vars->p2)
        return 84;
    if (vars->p1 == vars->ref || vars->p2 == vars->ref)
        return 84;
    return 0;
}
