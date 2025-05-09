/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

divi_t declare_var(divi_t var, char *nbr1, char *nbr2)
{
    var.a = 0;
    var.b = my_getnbr(nbr2);
    var.c = 0;
    var.count = 0;
    var.op = 0;
    var.car = 0;
    var.res = malloc(sizeof(char) * my_strlen(nbr1));
    return (var);
}

divi_t bouc(divi_t var, char *nbr1, char *nbr2)
{
    var.res[var.o] = '0';
    return (var);
}

divi_t next_div(divi_t var, char *nbr1)
{
    for (var.o = 0; var.count <= my_strlen(nbr1); var.o++, var.count++) {
        ((var.c < var.a) ? \
        (var.a = ((var.a - var.c) * 10) + (nbr1[var.count] - 48)) : \
        (var.a = nbr1[var.count] - 48));
        if (var.a < var.b && var.count < my_strlen(nbr1) - 1) {
            while (var.a < var.b) {
                var.count++;
                var.a = var.a * 10 + (nbr1[var.count] - 48);
            }
        }
        for (var.op = 1, var.opera = 0; var.opera <= var.a; var.op++)
            var.opera = var.op * var.b;
        var.op -= 2;
        var.c = var.op * var.b;
        ((var.car == 1) ? (var.res[var.o] = '0') : \
        (var.res[var.o] = var.op + 48));
        var.car = 0;
    }
    return (var);
}

char *division(char *nbr1, char *nbr2)
{
    divi_t var;

    var = declare_var(var, nbr1, nbr2);
    if ((my_strlen(nbr1) == 1 && my_getnbr(nbr1) < my_getnbr(nbr2)) || \
    (my_strlen(nbr1) < my_strlen(nbr2) || (my_strlen(nbr1) == \
    my_strlen(nbr2) && my_getnbr(nbr1) < my_getnbr(nbr2))) || \
    (my_strlen(nbr2) == 1 && nbr2[0] == '0')) {
        bouc(var, nbr1, nbr2);
        return (var.res);
    }
    next_div(var, nbr1);
    var.c = my_strlen(var.res);
    var.res[var.c - 1] = '\0';
    return (var.res);
}
