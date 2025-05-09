/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-palindrome-erwann.laplante
** File description:
** convert_flag
*/

#include "bonus.h"

int convert_int_bonus(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

int convert_to_deci_bonus(char *str, int base)
{
    int len = strlen(str);
    int power = 1;
    int res = 0;

    for (int i = len - 1; i >= 0; i--, power = power * base)
        res += convert_int_bonus(str[i]) * power;
    return res;
}

void convert_from(char **av, int cf)
{
    int yes = 0;

    for (int j = 2; j != 11; j++) {
        yes = 0;
        for (int k = 0; av[cf + 1][k]; k++)
            (av[cf + 1][k] > j + 48 - 1) ? yes = 1 : 0;
        if (yes == 0)
            printf("%s in base %i = %i in base 10\n", av[cf + 1]
            , j, convert_to_deci_bonus(av[cf + 1], j));
    }
}

int convert_flag(char **av, var_t *var, int ac)
{
    int ct = 0;
    int cf = 0;

    for (int i = 0; i != ac; i++) {
        if (strcmp(av[i], "-ct") == 0 && (av[i + 1]
        && my_str_is_int(av[i + 1]) == 0))
            ct = i;
        if (strcmp(av[i], "-cf") == 0 && (av[i + 1]
        && my_str_is_int(av[i + 1]) == 0))
            cf = i;
    }
    if (ct != 0)
        for (int j = 2; j != 11; j++)
            printf("%s in base 10 = %s in base %i\n", av[ct + 1]
            , convert_from_deci(j, my_str_to_int(av[ct + 1])), j);
    if (cf != 0)
        convert_from(av, cf);
    free(var);
    return 0;
}
