/*
** EPITECH PROJECT, 2021
** Task 02 - my.h
** File description:
** description
*/

#ifndef MY_LIB_
    #define MY_LIB_
    void my_putstr(char const *str);
    void my_putchar(char c);
    int my_put_nbr(int nb);
    int my_getnbr(char const *str);
    int my_strlen(char const *str);
    int my_str_isnum(char const *str, int i);
    char *my_evil_str(char *str);
    char *my_strcat(char *dest , char const *src);
    int my_strcmp(char const *s1 , char const *s2);
    int main(int ac, char **ar);
    void infin_add(char *s1, char *s2);
    void show_result_to_char(char *str, int len);
    void string_to_val(char *str, int len);
    char *my_alloc(int len);
    int is_neg(char *number);
    void infin_sous(char *s1, char *s2);
    void sous_param(int is_neg1, int is_neg2, char *s1, char *s2);
#endif
