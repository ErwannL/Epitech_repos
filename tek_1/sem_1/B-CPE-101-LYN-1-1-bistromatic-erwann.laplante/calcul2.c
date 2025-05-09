/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** calcul2
*/

#include"include/my.h"
#include <unistd.h>
#include <stdlib.h>

char *calc2(char *res)
{
    if (res[0] == '0') {
        write(2, SYNTAX_ERROR_MSG, 12);
        exit(84);
    }
    for (int i = my_strlen(res); i > 0; i--) {
        res[i] = res[i - 1];
    }
    res[0] = '0';
    return (res);
}

char *reset_num(char *num)
{
    for (int i = 0; num[i] != '\0'; i++)
        num[i] = '0';
    return (num);
}

var_t reset_calc(var_t var)
{
    var.nbr1 = reset_num(var.nbr1);
    var.nbr2 = reset_num(var.nbr2);
    return (var);
}

var_t calculus2(var_t var)
{
    if (var.cc != my_strlen(var.nbr2)) {
        var.nbr2 = my_rev_str(var.nbr2);
        var.nbr2 = var.nbr2 + 1;
        var.nbr2 = my_rev_str(var.nbr2);
    }
    var.cc = 0;
    var.new_str = my_strcat(calc(var), var.new_str);
    var.nbr1 = reset_num(var.nbr1);
    var.nbr2 = reset_num(var.nbr2);
    return (var);
}

char *calc3(var_t var)
{
    if (var.op == var.operators[3])
        var.res = minus(var.nbr1, var.nbr2);
    if (var.op == var.operators[5]) {
        var.res = division(var.nbr1, var.nbr2);
        var.res = calc2(var.res);
    }
    if (var.op == var.operators[6])
        var.res = modulo(var.nbr1, var.nbr2);
    return (var.res);
}
