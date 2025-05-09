/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-palindrome-erwann.laplante
** File description:
** lib
*/

#ifndef LIB_H_

    //define

    #define LIB_H_

    //include

    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>

    //utilitiees.c

    //if the string is only numbres return 0, else return 84
    int my_str_is_int(char *str);
    //reverse of the sring in parameter
    char *my_revstr(char *str);
    //convert the string in parameter to int
    int my_str_to_int(char *str);
    //convert the number in parameter to string
    char *int_to_str(int nb);

    //convert.c

    //convert a number in base 10 to another base
    char *convert_from_deci(int base, int num);
    //convert a number in another base to base 10
    int convert_to_deci(char *str, int base);

    //string_free.c

    //compare 2 string with the possibility to free the 2 string
    //for free the string 1 put 0 in int one & same for string 2
    int my_strcmp_free(char *str_one, int one, char *str_two, int two);
    //copy an string in another with possibility to free the src
    //for free the src put 0 in n
    char *my_strcpy_free(char *dest, char *src, int n);

#endif
