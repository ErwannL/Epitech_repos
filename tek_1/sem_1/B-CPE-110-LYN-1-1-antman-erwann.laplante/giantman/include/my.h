/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>

    /*structure for all variables for all functions*/
    typedef struct variable {
        struct stat *st;
        int fd;
        int error;
        int i;
        int len;
        int nbr;
        int enter;
        char *buffer;
        char *color;
        char *nbr_str;
    }variable_t;

    /*binary tree*/
    typedef struct node {
        unsigned int key;
        int symb;
        struct node *left;
        struct node *right;
    } node;

    /*convert an int in an str*/
    char *int_to_str(int nb);

    /*print a int*/
    int my_put_nbr(int nb);

    /*print a char*/
    void my_putchar(char c);

    /*print an str*/
    int my_putstr(char const *str);

    /*reverse an str*/
    char *my_revstr(char *str);

    /*add an str after an other*/
    char *my_strcat(char *dest, char *src);

    /*compare two str and return :
    if s1 is egal with s2 -> 0
    else if s1 is greater -> a positive number
    else -> a negative number*/
    int my_strcmp(char const *s1, char const *s2);

    /*copy an str in an other*/
    char *my_strcpy(char *dest , char const *src);

    /*count the len of an str*/
    int my_strlen(char const *str);

    /*take nbr in str*/
    int my_getnbr(char *str);

    /*read file and :
    if ./antman -h 'mode' -> print the -h
    else if ./antman 'bad filpath' 'mode' -> print "file don't find"
    else -> print the antman result*/
    variable_t reading_file(variable_t var, char *filepath);

    /* print -h*/
    void print_h(void);

    /*print start of compressed file*/
    int start_mode(variable_t var, char *mode);

    /*the following of mode3 function*/
    variable_t mode_3(variable_t var);

    /*function for mode 1*/
    variable_t mode_1(variable_t var);

    /*make binary tree*/
    int binary_tree(char *str, char *crypted);

#endif
