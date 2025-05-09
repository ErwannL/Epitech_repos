/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myprintf-erwann.laplante
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <criterion/criterion.h>
    #include <criterion/redirect.h>
    #include <stdarg.h>
    #include <stdlib.h>
    int my_getnbr(char const *str);
    int my_printf(char *str, ...);
    int my_put_nbr(long int nb);
    void my_putchar(char c);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    void convert_base_hex_maj(int nbr);
    void convert_base_bi(int nbr);
    char *my_rev_str(char *str);
    char *convert_base_oct(int nbr);
    int my_printf_nbr(va_list *argptr);
    int my_printf_char(va_list *argptr);
    int my_printf_str(va_list *argptr);
    int my_printf_oct(va_list *argptr);
    char *convert_base_hex_maj_bis(int *stock, int i, int n);
    char *convert_base_hex_min_bis(int *stock, int i, int n);
    void convert_base_hex_min(int nbr);
    int my_printf_bi(va_list *argptr);
    int my_printf_hex_maj(va_list *argptr);
    int my_printf_hex_min(va_list *argptr);
    char *my_strcpy(char *dest , char const *src);
#endif /* !MY_H_ */
