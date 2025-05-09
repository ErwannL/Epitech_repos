/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-palindrome-erwann.laplante
** File description:
** help
*/

#include "my.h"

int print_h(var_t *var)
{
    printf("USAGE\n");
    printf("    ./palindrome -n number -p palindrome [-b base] [-imin i] [-i");
    printf("max i]\n");
    printf("DESCRIPTION\n");
    printf("    -n n      integer to be transformed (>=0)\n");
    printf("    -p pal    palindromic number to be obtained (incompatible wi");
    printf("th the -n\n");
    printf("              option) (>=0)\n");
    printf("              if defined, all fitting values of n will be output");
    printf("\n");
    printf("    -b base   base in which the procedure will be executed (1<b<");
    printf("=10) [def: 10]\n");
    printf("    -imin i   minimum number of iterations, included (>=0) [def:");
    printf(" 0]\n");
    printf("    -imax i   maximum number of iterations, included (>=0) [def:");
    printf(" 100]\n");
    free(var);
    return 0;
}
