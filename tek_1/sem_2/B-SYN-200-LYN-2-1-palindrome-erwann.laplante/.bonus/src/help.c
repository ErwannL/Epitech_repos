/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-palindrome-erwann.laplante
** File description:
** help
*/

#include "bonus.h"

int print_error(char *error_name, var_t *var)
{
    printf("%s\n", error_name);
    free(var);
    return 0;
}

int print_h_next(var_t *var)
{
    printf("    -imin i     minimum number of iterations, included (>=0) [de");
    printf("f: 0]\n");
    printf("    -imax i     maximum number of iterations, included (>=0) [de");
    printf("f: 100]\n");
    printf("    -d          if error in argument print good error message el");
    printf("se print what is in all value\n");
    printf("    -cf num     convert num from all base to base 10\n");
    printf("    -ct num     convert num from base 10 to all base\n");
    free(var);
    return 0;
}

int print_h(var_t *var, char *str, char **av, int ac)
{
    if (strcmp(str, "-d") == 0)
        return debug_fonction(var, ac, av);
    if (strcmp(str, "-cf") == 0 || strcmp(str, "-ct") == 0)
        return convert_flag(av, var, ac);
    printf("USAGE\n");
    printf("    ./palindrome -n number -p palindrome -pn first_palindrome [-");
    printf("b base] [-imin i] [-imax i]\n");
    printf("DESCRIPTION\n");
    printf("    -n n        integer to be transformed (>=0)\n");
    printf("    -p pal      palindromic number to be obtained (incompatible ");
    printf("with the -n option) (>=0)\n");
    printf("                if defined, all fitting values of n will be outp");
    printf("ut\n");
    printf("    -np f_pal   find number who there first palindrome is f_pal");
    printf(" (incompatible with the -n & the -p option) (>=0)\n");
    printf("                if defined, all fitting values of n & p will be ");
    printf("output\n");
    printf("    -b base     base in which the procedure will be executed (1<");
    printf("b<=10) [def: 10]\n");
    return print_h_next(var);
}
