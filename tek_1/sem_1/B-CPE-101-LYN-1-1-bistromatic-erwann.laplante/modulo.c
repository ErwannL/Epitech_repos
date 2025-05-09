/*
** EPITECH PROJECT, 2021
** BistroDeLaStreet
** File description:
** modulo
*/

#include <stdlib.h>
#include "include/my.h"

modulo_t declara_var(modulo_t var, char *nbr1, char *nbr2)
{
    var.res = malloc(sizeof(char) * my_strlen(nbr1));
    var.res2 = malloc(sizeof(char) * my_strlen(nbr2));
    var.res3 = malloc(sizeof(char) * my_strlen(nbr2));
    var.i = 1;
    return (var);
}

char *next_modu(modulo_t var, char *nbr1, char *nbr2, int i)
{
    if (nbr1[var.i] < nbr2[var.i]) {
        var.res3[0] = '0';
        return (var.res3);
    }
    return 0;
}

char *modulo(char *nbr1, char *nbr2)
{
    modulo_t var;

    var = declara_var(var, nbr1, nbr2);
    if (my_strlen(nbr1) == my_strlen(nbr2)) {
        for (var.i = 0; nbr1[var.i] != '\0'; var.i++) {
            next_modu(var, nbr1, nbr2, var.i);
        }
    }
    if (my_strlen(nbr1) < my_strlen(nbr2)) {
        var.res3[0] = '0';
        return (var.res3);
    }
    var.res = division(nbr1, nbr2);
    var.res2 = mult(var.res, nbr2);
    var.res3 = minus(nbr1, var.res2);
    free(var.res);
    free(var.res2);
    return (var.res3);
}
