/*
** EPITECH PROJECT, 2021
** TTask 05 - my_getnbr
** File description:
** This function eturns a number, sent to the function as a string
*/
#include"../include/my.h"

int diviser(int value1, int value2, int result)
{
    if (value2 == 0)
        my_putstr("Stop: division by zero");
    else
        result = value1 / value2;
    return (result);
}

int do_op(char operator, int value1, int value2)
{
    int result = 0;

    if (operator == '+')
        result = value1 + value2;
    if (operator == '-')
        result = value1 - value2;
    if (operator == '*')
        result =  value1 * value2;
    if (operator == '/')
        result = diviser(value1, value2, result);
    if (operator == '%') {
        if (value2 == 0)
            my_putstr("Stop: modulo by zero");
        else
            result = value1 % value2;
    }
    return(result);
}

int main (int ac, char **ar)
{
    char operator;
    int value1;
    int value2;
    int print;

    if (ac == 4) {
        operator = ar[2][0];
        value1 = my_getnbr(ar[1]);
        value2 = my_getnbr(ar[3]);
        print = do_op(operator, value1, value2);
        my_put_nbr(print);
        return (0);
    }
    return (84);
}
