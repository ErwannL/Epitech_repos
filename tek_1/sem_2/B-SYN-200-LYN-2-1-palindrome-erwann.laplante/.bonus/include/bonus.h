/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-palindrome-erwann.laplante
** File description:
** bonus
*/

#ifndef BONUS_H_

    //define

    #define BONUS_H_

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
        int pn_flag;
        int pn;
        int d_flag;
        int fn_flag;
        int fn;
    } var_t;

    //bonus.c

    //compare if the palindrome in parametr is the first palindome of numbers
    void p_fonction_bonus(int number, int base, int min, int max);
    //launch the good function according to the flag
    void flag_function_bonus(var_t *var);

    //help.c

    //print the -h (help) flag
    int print_h(var_t *var, char *str, char **av, int ac);
    //print error message in parameter, free var and return 0
    int print_error(char *error_name, var_t *var);

    //parsing.c

    //pars the arguments and get all flag & value
    var_t *arg_parsing(var_t *var, char **av, int i);

    //struct.c

    //initialise all value in the structure
    var_t *init_struct(void);

    //main.c

    //add an str and his reverse with the base
    char *add_str(char *str, int base);
    //lauch p flag
    void p_fonction(int number, int base, int min, int max);
    //lauch n flag
    void n_fonction(int number, int base, int min, int max);

    //debug.c

    //print good message error and if no error print all variables
    int debug_fonction(var_t *var, int ac, char **av);

    //convert_flag.c

    //convert from base 10 to all or convert from all base to 10
    int convert_flag(char **av, var_t *var, int ac);

    //f_flag.c

    //compare all flag and test error
    int test_error_flag(var_t *var);
    //execute number times the n fonction
    void fn_fonction(int number, int base, int min, int max);

#endif
