/*
** EPITECH PROJECT , $YEAR
** $NAME_OF_THE_PROJECT
** File description:
** No file there , just an epitech header example
*/
#include "../../include/rush3.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + '0');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    return 0;
}
