/*
** EPITECH PROJECT, 2021
** Task 04 - my_isneg
** File description:
** This file displays N if parameter is negative or P, if positive or null
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}
