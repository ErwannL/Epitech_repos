/*
** EPITECH PROJECT, 2021
** Task 07 - my_put_nbr
** File description:
** This fill displays the number given as a parameter
*/

#include"../include/my.h"

int my_put_nbr(int nb)
{
    int quotient;
    int rest;

    if (nb < 0) {
        nb = nb * - 1;
        my_putchar('-');
    }
    if (nb < 10)
        my_putchar(nb + 48);
    if (nb > 9) {
        rest = nb % 10;
        quotient = nb / 10;
        my_put_nbr(quotient);
        my_putchar(rest + 48);
    }
    return (0);
}
