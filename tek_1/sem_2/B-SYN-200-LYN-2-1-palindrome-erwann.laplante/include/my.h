/*
** EPITECH PROJECT, 2022
** private_palindrome
** File description:
** my
*/

#ifndef MY_H_

    //define

    #define MY_H_

    //include

    #include "../lib/lib.h"
    #include <stdio.h>

    //sruct

    //structure with all value
    typedef struct {
        int n_flag;
        int number;
        int p_flag;
        int palindrome;
        int b_flag;
        int base;
        int imin_flag;
        int i_min;
        int imax_flag;
        int i_max;
        int r_val;
    } var_t;

    //help.c

    //print the -h (help) flag
    int print_h(var_t *var);

    //parsing.c

    //pars the arguments and get all flag & value
    var_t *arg_parsing(var_t *var, char **av, int i);

    //struct.c

    //initialise all value in the structure
    var_t *init_struct(void);

#endif
