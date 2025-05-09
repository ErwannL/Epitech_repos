/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myprintf-erwann.laplante
** File description:
** my_printf
*/

#include "../includes/my.h"

int my_printf_nbr(va_list *argptr)
{
    int nbr = va_arg(*argptr, int);

    if (nbr < 0) {
        my_put_nbr(4294967296 + nbr);
    } else {
        my_put_nbr(nbr);
    }
    return (0);
}

int my_printf_char(va_list *argptr)
{
    my_putchar(va_arg(*argptr, int));
    return (0);
}

int my_printf_str(va_list *argptr)
{
    char *str = va_arg(*argptr, char *);
    int i = 0;
    char *res = malloc(sizeof(char) * 3);
    int tmp;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] <= 126)
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            tmp = str[i];
            res = convert_base_oct(tmp);
            for (int j = my_strlen(res); j != 3; j++, my_putchar('0'));
            my_putstr(res);
        }
    }
    return (0);
}

int my_printf(char *str, ...)
{
    va_list argptr;
    va_start(argptr, str);
    char letter[13] = {'i', 'u', 'd', 'c', 's', 'o', 'O', 'x', 'X', 'b', 'S', \
    'p', '\0'};
    int (*function_to_point_to[12])(va_list *) = {my_printf_nbr, \
    my_printf_nbr, my_printf_nbr, my_printf_char, my_printf_str, \
    my_printf_oct, my_printf_oct, my_printf_hex_min, my_printf_hex_maj, \
    my_printf_bi, my_printf_str, my_printf_str};

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '%')
            my_putchar(str[i]);
        else {
            i++;
            for (int j = 0; letter[j] != '\0'; ((str[i] == letter[j]) ? \
            (function_to_point_to[j](&argptr)) : 0), j++);
        }
    }
    va_end(argptr);
    return (0);
}
