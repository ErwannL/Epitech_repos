/*
** EPITECH PROJECT, 2021
** Task 02 - my_print_revalpha
** File description:
** This file displays the lowercase alphabet in descending order
*/

int my_print_revalpha(void)
{
    int variable;
    variable = 122;
    while (variable >= 97) {
        my_putchar(variable);
        variable--;
    }
return(0);
}
