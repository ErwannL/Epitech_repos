/*
** EPITECH PROJECT, 2021
** Task 03 - my_print_digits
** File description:
** This file displays all the digits
*/

int my_print_digits(void)
{
    int variable;
    variable = 48;
    while (variable <= 57) {
        my_putchar(variable);
        variable++;
    }
return(0);
}
