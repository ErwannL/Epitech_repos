/*
** EPITECH PROJECT, 2021
** B-CPE-101-LYN-1-1-bistromatic-erwann.laplante
** File description:
** mult
*/

#include <stdlib.h>
#include "include/my.h"

mult_t declar_var(mult_t var, char *nbr2, char *nbr1)
{
    var.j = my_strlen(nbr2) - 1;
    var.result = malloc(sizeof(char) * my_strlen(nbr1) + my_strlen(nbr2));
    var.car = 0;
    var.o = 0;
    var.count = 0;
    return (var);
}

mult_t next(mult_t var, char *nbr1)
{
    for (int i = my_strlen(nbr1) - 1, o = var.count; i >= 0; i--, o++) {
        var.a = nbr1[i] - 48;
        var.c = var.a * var.b;
        if (var.result[o] >= '1' && var.result[o] <= '9')
            var.c = var.c + (var.result[o] - 48);
        if (var.car > 0) {
            var.c = var.c + var.car;
            var.car = 0;
        }
        if (var.c > 9) {
            var.car = var.c / 10;
            var.c = var.c % 10;
        }
        if (i == 0 && var.car > 0) {
            var.result[o + 1] = var.car + 48;
            var.car = 0;
        }
        var.result[o] = var.c + 48;
    }
    return (var);
}

char *mult(char *nbr1, char *nbr2)
{
    mult_t var;

    var = declar_var(var, nbr2, nbr1);
    for (; var.j >= 0; var.j--, var.o++) {
        var.b = nbr2[var.j] - 48;
        next(var, nbr1);
        var.count++;
    }
    var.result = my_rev_str(var.result);
    return var.result;
}
