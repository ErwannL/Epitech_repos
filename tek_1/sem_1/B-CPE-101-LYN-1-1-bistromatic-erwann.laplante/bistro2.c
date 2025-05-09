/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** bistro2
*/

#include"include/my.h"
#include <unistd.h>
#include <stdlib.h>

var_t parenthis3(var_t var)
{
    ((my_char_in_base(var, var.calcul[var.i]) == 1 && my_char_in_op(var, \
    var.calcul[var.i], 0) == 1 && var.calcul[var.i] != '\0' && \
    var.calcul[var.i] != '\n') ? (exit_function()) : (var.val_return));
    ((((var.calcul[var.i] == var.operators[2]) || (var.calcul[var.i] == \
    var.operators[3])) && ((var.calcul[var.i + 1] == var.operators[4]) || \
    (var.calcul[var.i + 1] == var.operators[5]) || (var.calcul[var.i + 1] == \
    var.operators[6]))) ? (var.val_return = 84) : (var.val_return));
    if (var.val == 1) {
        (((my_char_in_base(var, var.calcul[var.i]) == 0) || \
        (var.calcul[var.i - 1] == var.operators[1] && var.calcul[var.i] == \
        var.operators[0])) ? (exit_function()) : (var.val_return));
    }
    var.val = 0;
    var.new_str[var.j] = var.calcul[var.i];
    var.str_calc = malloc(sizeof(var.calcul));
    ((my_strlen(var.calcul) == 1) ? (exit_function()) : (var.val_return));
    return (var);
}

var_t declaration_var2(var_t var, char *size_read)
{
    var.size_read = my_strdup(size_read);
    return (var);
}

var_t declaration_var(var_t var, char *calcul, char *base, char *operators)
{
    var.new_str = malloc(sizeof(calcul) * sizeof(calcul));
    var.calcul = my_strdup(calcul);
    var.str_calc;
    var.j = 0;
    var.k = 0;
    var.nbr_p = 0;
    var.tempo = 0;
    var.i = 0;
    var.base = my_strdup(base);
    var.operators = my_strdup(operators);
    var.val = 0;
    var.val_return = 0;
    var.nbr1 = malloc(sizeof(calcul) * sizeof(calcul));
    var.nbr2 = malloc(sizeof(calcul) * sizeof(calcul));
    var.count = 0;
    var.cc = 0;
    return (var);
}

int eval_expr(char *calcul, char *base, char *operators, char *size_read)
{
    var_t var;

    var = declaration_var(var, calcul, base, operators);
    var = declaration_var2(var, size_read);
    for (; var.calcul[var.i] != '\0'; var.i++, var.j++) {
        var = parenthis3(var);
        if ((var.calcul[var.i] == var.operators[0] && my_char_in_base(var, \
        var.calcul[var.i - 1]) == 0) || (var.val_return == 84))
            exit_function();
        ((var.calcul[var.i] == var.operators[0] || var.calcul[var.i] \
        == var.operators[1]) ? (var = parenthis(var)) : var);
    }
    if (var.nbr_p != 0)
        exit_function();
    var.new_str = dec_calc(var);
    while (my_strlen(var.new_str) > 2 && var.new_str[0] == '0')
        var.new_str++;
    write(1, var.new_str, my_strlen(var.new_str) - 1);
    return (var.val_return);
}

int erro2_3(char **av, int i)
{
    for (int j = (i + 1); av[2][j] != '\0'; j++) {
        if (av[2][i] == av[2][j])
            return (84);
    }
    return (0);
}
