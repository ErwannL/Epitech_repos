/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Display the number passed as argument.
*/

#include "my.h"

int my_unsigned_put_nbr(unsigned int nb)
{
    if (nb < 0 && nb >= -2147483647) {
        nb = nb * -1;
        my_putchar('-', 1);
    }
    if (nb > 9 || nb < -2147483647) {
        my_put_nbr(nb / 10);
    }
    my_putchar(((nb < 0) ? ((nb % 10) * - 1) : (nb % 10)) + '0', 1);
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb < 0 && nb >= -2147483647) {
        nb = nb * -1;
        my_putchar('-', 1);
    }
    if (nb > 9 || nb < -2147483647) {
        my_put_nbr(nb / 10);
    }
    my_putchar(((nb < 0) ? ((nb % 10) * - 1) : (nb % 10)) + '0', 1);
    return 0;
}
