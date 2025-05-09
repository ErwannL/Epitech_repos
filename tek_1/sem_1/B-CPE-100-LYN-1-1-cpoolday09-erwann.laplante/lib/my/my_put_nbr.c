/*
** EPITECH PROJECT, 2021
** Task 07 - my_put_nbr
** File description:
** This fill displays the number given as a parameter
*/
#include"../../include/my.h"

int my_put_nbr(int nb)
{
    int quotient;
    int rest;
    unsigned int nbr;

    if (nb < 0) {
        nb = nb * - 1;
        my_putchar('-');
    }
    if (nbr < 10)
        my_putchar(nbr + 48);
    if (nbr > 9) {
        rest = nbr % 10;
        quotient = nbr / 10;
        my_put_nbr(quotient + 48);
        my_putchar(rest + 48);
    }
    return (0);
}
