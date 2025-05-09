/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** eval expr
*/
#include"my.h"
#include"stdlib.h"

char *val_to_string(int number)
{
    char *str;
    int digit_count = 0;

    if (number < 0) {
        number = - 1 * number;
        digit_count++;
    }
    digit_count += nb_digit(number);
    str = malloc(sizeof(char)*(digit_count * 10));
    str[digit_count] = '\0';
    while (number > 0) {
        str[digit_count - 1] = number % 10 + '0';
        number = number / 10;
        digit_count--;
    }
    if (digit_count == 1)
        str[0] = '-';
    return (str);
}

int diviser(int nb1, int nb2, int result)
{
    if (nb2 == 0) {
        my_putstr("Stop: division by zero");
        return (84);
    } else
        result = (nb1 / nb2);
    return (result);
}

int calc(int nb1, char op, int nb2)
{
    int result = 0;

    if (op == '+')
        result = (nb1 + nb2);
    if (op == '-')
        result = (nb1 - nb2);
    if (op == '*')
        result = (nb1 * nb2);
    if (op == '/')
        result = diviser(nb1, nb2, result);
    if (op == '%') {
        if (nb2 == 0) {
            my_putstr("Stop: modulo by zero");
            return (84);
        } else
            result = (nb1 % nb2);
    }
    return(result);
}

int eval_expr(char *calcul)
{
    variables_t variables;

    if (if_one(calcul) != 1)
        calcul = sort(calcul);
    variables = eval_expr2(variables);
    while (only_digit(calcul) == 1) {
        calcul = if_parenthesis(calcul);
        ((calcul[0]) == '-' ? (variables.x = 1) && (calcul++) : 0);
        for (;calcul[0] >= '0' && calcul[0] <= '9'; calcul++)
            variables.nb1 = variables.nb1 * 10 + (calcul[0] - 48);
        variables.op = calcul[0];
        calcul = if_parenthesis(++calcul);
        ((calcul[0]) == '-' ? (variables.y = 1) && (calcul++) : 0);
        for (;calcul[0] >= '0' && calcul[0] <= '9'; calcul++)
            variables.nb2 = variables.nb2 * 10 + (calcul[0] - 48);
        return (eval_expr(if_minus_before(variables, calcul)));
    }
    return (my_getnbr(calcul));
}

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
