/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    //include

    #include <stdlib.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <string.h>
    #include <stdio.h>

    //struct

    typedef struct {
        char *name;
        void *next;
    } chained_t;

    typedef struct {
        char **name;
        int *lenght;
    } out_t;

    typedef struct {
        int i_flag;
        int e_flag;
        int json_flag;
    } flags_t;

    typedef struct {
        int word;
        int can;
        int end;
        char **prev_word;
        int index;
        int min_id;
        int where;
        char **out;
        int lenght;
        char *tmp;
        int what;
    } no_flag_t;

    typedef struct {
        char **tmp;
        char *all;
        int lenght;
        int before;
        char *word;
        char **result;
        int res;
        int where;
        int mode;
        char *nbr;
        int len;
        int rea_int;
        int pro_int;
        int yes;
        int reverse;
    } i_flag_t;

    typedef struct {
        int on;
        int react;
        int produ;
    } valu_t;

    typedef struct {
        struct stat st;
        int fd;
        ssize_t re_error;
        char *buf;
        int st_error;
        char **array;
        chained_t *bad_chained;
        chained_t *good_chained;
        char **elements;
        int elem;
        flags_t *flag;
        int r_val;
        no_flag_t *no_flag_struct;
        i_flag_t *i_flag_struct;
        valu_t value;
    } var_t;

    //struct.c

    int free_all(int exit_val, var_t *var);
    var_t * init_struct(var_t *var, int ac, char **av);

    //file.c

    int get_file_info(var_t * var, char **av);

    //my_str_to_word_array.c

    char **my_str_to_word_array(char *str);

    //chained_list.c

    void chained_complete(var_t *var, char *str);
    void reverse_chained(var_t *var);
    void reverse_chained_bis(var_t *var);

    //revstr.c

    char *my_revstr(char *str);

    //flag/no_flag.c

    void display_no_flag(var_t *var);
    char *get_word(char *str);

    //utilities.c

    int already_meet(char **prev_word, char *str, int stop);
    char **sort_array(char **array, int stop);
    char *destroy_str(char *str, char *comp, int n);

    //flag/i_flag.c

    void display_i_flag(var_t *var, char *id, int what);

    //flag/species.c

    void start_start_react_f(var_t *var);
    int get_reaction(var_t *var, int i, char *id, int on);
    var_t *get_rectants_products(var_t *var, char *id, int i);
    int print_reactants(var_t *var, char *id);

    //flag/fill_elements_i.c

    int species_function(var_t *var, int i, int a);
    var_t *fill_elements(var_t *var, int i);
    var_t *fill_elements_next(var_t *var, int i);

    //flag/end_i.c

    var_t *get_id(var_t *var, int i, char *id);
    void else_i_flag(var_t *var);
    var_t *get_species(var_t *var, int i, int a);

    //flag/e_flag.c

    void display_e_flag(var_t *var, char *id);

    //falg/react_e.c

    var_t *get_rectants_products_e(var_t *var, char *id, int i);
    void start_start_react_e(var_t *var);
    void start_react_e(var_t *var, int *val, char *id);

#endif
