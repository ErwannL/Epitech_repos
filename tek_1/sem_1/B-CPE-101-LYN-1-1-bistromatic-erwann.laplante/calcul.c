/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** calcul1
*/

#include"include/my.h"
#include <unistd.h>
#include <stdlib.h>

char *calc(var_t var)
{
    while (my_strlen(var.nbr1) > my_strlen(var.nbr2)) {
        var.nbr2 = my_rev_str(var.nbr2);
        var.nbr2[my_strlen(var.nbr2)] = '0';
        var.nbr2 = my_rev_str(var.nbr2);
    }
    if (var.op == var.operators[4])
        var.res = mult(var.nbr1, var.nbr2);
    if (var.op == var.operators[2])
        var.res = add(var.nbr1, var.nbr2);
    var.res = calc3(var);
    var = reset_calc(var);
    return (var.res);
}

var_t signe_calc(var_t var)
{
    while (var.new_str[0] == var.operators[2] || var.new_str[0] == \
    var.operators[3]) {
        if (var.new_str[0] == var.operators[3])
            var.count++;
        var.new_str++;
    }
    return (var);
}

calc_t dec_var(calc_t var_calc)
{
    var_calc.isneg1 = 0;
    var_calc.isneg2 = 0;
    return (var_calc);
}

char *calculus(var_t var, calc_t var_calc)
{
    while (my_str_only_base(var) != 0) {
        var_calc.k = 0;
        var = signe_calc(var);
        ((var.count % 2 != 0) ? (var_calc.isneg1 = 1, var.count = 0, \
        var_calc.j = 0) : (var_calc.isneg1, var.count = 0, var_calc.j = 0));
        for (; my_char_in_base(var, var.new_str[0]) == 0; var_calc.j++, \
        var.new_str++)
            var.nbr1[var_calc.j] = var.new_str[0];
        var.op = var.new_str[0];
        var.new_str++;
        var = signe_calc(var);
        ((var.count % 2 != 0) ? (var_calc.isneg2 = 1, var.count = 0, \
        var_calc.k = 0) : (var_calc.isneg2, var.count = 0, var_calc.k = 0));
        for (; my_char_in_base(var, var.new_str[0]) == 0; var_calc.k++, \
        var.new_str++, var.cc++)
            var.nbr2[var_calc.k] = var.new_str[0];
    var_calc = dec_var(var_calc);
    var = calculus2(var);
    }
    return (var.new_str);
}

char *dec_calc(var_t var)
{
    calc_t var_calc;

    var_calc.isneg1 = 0;
    var_calc.isneg2 = 0;
    return (calculus(var, var_calc));
}
