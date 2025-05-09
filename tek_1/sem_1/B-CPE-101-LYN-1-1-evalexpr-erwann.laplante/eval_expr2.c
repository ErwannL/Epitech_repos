/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** eval expr
*/
#include"my.h"

int nb_digit(int nb)
{
    int digit_count = 0;

    while (nb > 0) {
        digit_count++;
        nb /= 10;
    }
    return digit_count;
}

int only_digit(char *str)
{
    if (str[0] == '-')
        str++;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/' || str[i] == '*' || str[i] == '-' || str[i] == '%')
            return (1);
        if (str[i] == '+' || str[i] == '(' || str[i] == ')')
            return (1);
    }
    return (0);
}

char *if_parenthesis(char *str)
{
    while (str[0] == '(' || str[0] == ')')
        str++;
    return (str);
}

char *if_minus_before(variables_t variables, char *calcul)
{
    if (variables.y == 1)
        variables.nb2 = variables.nb2 * - 1;
    if (variables.x == 1 && (variables.op == '+' || variables.op == '-')) {
        ((variables.op == '-') ? (variables.op = '+') : (variables.op = '-'));
        calcul = my_strcat(val_to_string(-1 * calc(variables.nb1, variables.op,
         variables.nb2)), if_parenthesis(calcul));
    }
    else if (variables.x == 1) {
        calcul = my_strcat(val_to_string(-1 * calc(variables.nb1, variables.op,
         variables.nb2)), if_parenthesis(calcul));
    } else {
        calcul = my_strcat(val_to_string(calc(variables.nb1, variables.op,
         variables.nb2)), if_parenthesis(calcul));
    }
    return (if_parenthesis(calcul));
}

variables_t eval_expr2(variables_t variables)
{
    variables.nb1 = 0;
    variables.nb2 = 0;
    variables.x = 0;
    variables.y = 0;
    return (variables);
}
