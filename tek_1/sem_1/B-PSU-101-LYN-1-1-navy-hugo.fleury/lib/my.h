/*
** EPITECH PROJECT, 2021
** my
** File description:
** Header of libmy.
*/

#ifndef MY_H
    #define MY_H
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stddef.h>

    int my_put_nbr(int nb);
    int my_atoi(char *str);
    void my_putchar(char c, int x);
    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    int my_strlen(char const *str);
    char *my_strdup(char const *src);
    int my_putstr(char const *str, int x);
    int my_unsigned_put_nbr(unsigned int nb);
    char **mem_alloc_2d_array(int *dimensions);
    int my_strcmp(char const *s1, char const *s2);
    char **my_str_to_word_array(char const *str, int *dimensions);
    char *convert_base(int number, int base, int capitalize);
    int handle_flag(va_list *args, char *str, int i);
    char *my_strcpy(char *dest, char const *src);
    char *my_strcat(char *dest, char const *src);
    char *my_strcapitalize(char *str, int what);
    void do_str(va_list *args, int what);
    void do_hex(va_list *args, int what);
    void do_oct(va_list *args, int what);
    void do_bin(va_list *args, int what);
    void do_int(va_list *args, int what);
    void do_chr(va_list *args, int what);
    void do_per(va_list *args, int what);
    int my_strchr(char *str, int what);
    int my_sort_word_array(char **tab);
    int my_printf(char *str, ...);
    char *my_revstr(char *str);
#endif
