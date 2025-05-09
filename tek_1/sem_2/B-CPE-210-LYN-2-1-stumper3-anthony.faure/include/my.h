/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper3-anthony.faure
** File description:
** my
*/

#ifndef MY_H_

    //define

    #define MY_H_

    //includes

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    //structures

    //number_struct
    typedef struct numbers {
        char **zero;
        char **one;
        char **two;
        char **three;
        char **four;
        char **five;
        char **six;
        char **seven;
        char **eight;
        char **nine;
        char *string;
        char *to_print;
    } numbers_t;

    //lib

    //print a char
    void my_putchar(char c, int fd);
    //print a string
    int my_putstr(char const *str, int fd);
    //count len of a string
    int my_strlen(char const *str);
    //copy an string in another one
    char *my_strcpy(char *dest, char const *src);
    //compare two string
    int my_strcmp(char const *s1, char const *s2);
    //transform a string in an number
    int my_atoi(char *str);
    //take a number in a string
    int my_getnbr(char *str);
    //put a string at the end of another one
    char *my_strcat(char *dest, char *src);
    //verify if a string contain only numbers
    int my_str_is_int(char *str);
    //verify if all char in a string are printable
    int my_str_is_printable(char *str);

    //src

    //check all errors of the programs
    int error_handling(int argc, char **argv, numbers_t *num);
    //fill the structure with numbers
    numbers_t *fill_numbers(void);
    //print the numbers
    void print_numbers(numbers_t *num);
    //apply the string argument on the numbers
    void apply_sting(numbers_t *numbers);

#endif
