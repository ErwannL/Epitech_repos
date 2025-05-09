/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** libc 'printf' but recoded.
*/

#include "my.h"

int handle_flag(va_list *args, char *str, int i)
{
    int j = 0;
    char flags[15] = { 's', 'S', 'c', 'd', 'i', 'u', 'x', 'X', 'o', 'O', 'b'
                    , '%', 'p', 'P', 0 };
    void (*func_ptr[15])(va_list *, int) = { do_str, do_str, do_chr, do_int
        , do_int, do_int, do_hex, do_hex, do_oct, do_oct, do_bin, do_per
        , do_hex, do_hex, NULL };

    for (j = 0; str[i + 1] != flags[j] && j != 15; j++);
    if (j == 15) {
        return 84;
    }
    i -= -1;
    func_ptr[j](args, j);
    return i;
}

int my_printf(char *str, ...)
{
    va_list args;

    va_start(args, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '%') {
            my_putchar(str[i], 1);
        } else if ((i = handle_flag(&args, str, i)) == 84) {
            return 84;
        }
    }
    va_end(args);
    return 0;
}
