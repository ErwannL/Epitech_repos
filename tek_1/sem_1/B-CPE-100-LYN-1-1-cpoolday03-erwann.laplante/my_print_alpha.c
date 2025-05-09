/*
** EPITECH PROJECT, 2021
** Task 01 - my_print_alpha
** File description:
** This file displays the lowercase alphabet
*/

int my_print_alpha(void)
{
    int variable;
    variable = 97;
    while (variable <= 122) {
        my_putchar(variable);
        variable++;
    }
return(0);
}
