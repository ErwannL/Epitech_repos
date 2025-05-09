/*
** EPITECH PROJECT, 2021
** conversions_functions
** File description:
** conversion functions of the my_printf.
*/

#include "my.h"

char *convert_base(int number, int base, int capitalize)
{
    int i = 0;
    char all_bases[] = "0123456789abcdef0123456789ABCDEF";
    char *buf = (char *)malloc(sizeof(int) + 1);

    for (i = 0; number != 0; i -= -1) {
        buf[i] = all_bases[(number % base) + capitalize];
        number /= base;
    }
    buf[i] = '\0';
    return my_revstr(buf);
}

void do_str(va_list *args, int what)
{
    char *str = va_arg(*args, char *);

    if (str == NULL)
        return;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 32 || str[i] >= 127) && (what == 1)) {
            my_putchar('\\', 1);
            my_putstr(convert_base((int)str[i], 8, 0), 1);
        } else {
            my_putchar(str[i], 1);
        }
    }
}

void do_hex(va_list *args, int what)
{
    int cond = ((what == 7) || (what == 13));
    char *ch = convert_base(va_arg(*args, unsigned long), 16, (cond ? 16 : 0));

    if ((what == 12) || (what == 13)) {
        my_putstr((ch[0] != '\0') ? "0x" : "(nil)", 1);
        if (ch[0] == '\0') {
            return;
        }
    }
    my_putstr(my_strcapitalize(ch, (cond ? 1 : 0)), 1);
}

void do_oct(va_list *args, int what)
{
    what = 0;
    my_putstr(convert_base((int)va_arg(*args, int), 8, 0), 1);
}

void do_bin(va_list *args, int what)
{
    what = 0;
    my_putstr(convert_base((int)va_arg(*args, int), 2, 0), 1);
}
