/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myprintf-erwann.laplante
** File description:
** my_printf_bis
*/

#include "../includes/my.h"

int my_printf_oct(va_list *argptr)
{
    my_putstr(convert_base_oct(va_arg(*argptr, int)));
    return (0);
}

int my_printf_bi(va_list *argptr)
{
    convert_base_bi(va_arg(*argptr, int));
    return (0);
}

int my_printf_hex_maj(va_list *argptr)
{
    convert_base_hex_maj(va_arg(*argptr, int));
    return (0);
}

int my_printf_hex_min(va_list *argptr)
{
    convert_base_hex_min(va_arg(*argptr, int));
    return (0);
}
