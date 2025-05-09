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

    /*node for chained list*/
    typedef struct dlist_node {
        char symbol;
        int nbr;
        struct dlist_node *next;
    }dlist_node_t;

    /*chained list*/
    typedef struct dlist {
        struct dlist_node *start;
    }dlist_t;

    /*structure for all variables for all functions*/
    typedef struct variable {
        struct stat *st;
        char *buffer;
        char *buffer_com;
        char *buffer_end;
        char *color;
        int fd;
        int fd2;
        int error;
        int i;
        int j;
        int ident;
        int nbr;
        int len_color;
        dlist_t *my_list;
        dlist_t *sorted_list;
    }variable_t;

    /*binary tree*/
    typedef struct node {
        unsigned int key;
        int symb;
        struct node *left;
        struct node *right;
    } node;

    /*read file and :
    if ./antman -h 'mode' -> print the -h
    else if ./antman 'bad filpath' 'mode' -> print "file don't find"
    else -> print the antman result*/
    variable_t reading_file(variable_t var, char *filepath);

    /*add new symb at the end of the list*/
    void add_after(dlist_t *li, char new_sym);

    /*create list with value*/
    void browse_list_add(dlist_t *li, char symb);

    /*display list*/
    void browse(dlist_t *li);

    /*sort list*/
    void sorting_list(dlist_t *li, dlist_t *sorted_list, variable_t var);

    /*following of sorting_list function*/
    void if_sorting_list(variable_t var, int max, dlist_node_t *it,
    dlist_node_t *it_2);

    /*following of sorting_list function*/
    void else_sorting_list(variable_t var, dlist_node_t *it);

    /*compare two str and return :
    if s1 is egal with s2 -> 0
    else if s1 is greater -> a positive number
    else -> a negative number*/
    int my_strcmp(char const *s1, char const *s2);

    /*copy an str in an other*/
    char *my_strcpy(char *dest , char const *src);

    /*add an str after an other*/
    char *my_strcat(char *dest, char *src);

    /*print an str*/
    int my_putstr(char const *str);

    /*count the len of an str*/
    int my_strlen(char const *str);

    /*reverse an str*/
    char *my_revstr(char *str);

    /*convert an int in an str*/
    char *int_to_str(int nb);

    /*print a char*/
    void my_putchar(char c);

    /*print a int*/
    int my_put_nbr(int nb);

    /*count the number of digit in an int*/
    int my_intlen(int nbr);

    /*print the -h*/
    void print_h(void);

    /*choose the good mode*/
    int start_mode(variable_t var, char *mode);

    /*function for mode 1*/
    variable_t mode_1(variable_t var);

    /*function for mode 3*/
    variable_t mode_3(variable_t var);

    /*from str to binary tree*/
    int binary_tree(char *str);

    /*function for mode 3*/
    variable_t boucle_mode3(variable_t var);

    /*function for mode 3*/
    variable_t while_mode3(variable_t var);

    /*find color for mode3*/
    variable_t find_color(variable_t var);

    /*convert nbr into str*/
    char *nbr_str(int nbr);

#endif
