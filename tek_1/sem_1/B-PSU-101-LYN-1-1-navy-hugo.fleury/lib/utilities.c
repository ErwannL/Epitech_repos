/*
** EPITECH PROJECT, 2021
** utilities
** File description:
** utilities of the my_printf.
*/

#include "my.h"
#include <stdlib.h>

void do_int(va_list *args, int what)
{
    if (what == 5) {
        my_unsigned_put_nbr(va_arg(*args, unsigned long));
    } else {
        my_put_nbr(va_arg(*args, long));
    }
}

void do_chr(va_list *args, int what)
{
    what = 0;
    my_putchar(va_arg(*args, long), 1);
}

void do_per(va_list *args, int what)
{
    what = 0;
    args = 0;
    my_putchar('%', 1);
}
