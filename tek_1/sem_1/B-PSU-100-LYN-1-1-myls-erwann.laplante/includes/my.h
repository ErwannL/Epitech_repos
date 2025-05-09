/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <limits.h>
    #include <string.h>
    typedef struct variables {
        struct stat *st;
        struct dirent *dirent;
        int revers;
        char buf[1];
        int *param1;
        int j;
        int *param2;
        int k;
        int *flags;
        int if_flags;
        int return_value;
        int num;
    } variables_t;
    int my_put_nbr(int nb);
    void my_putchar(char c);
    int my_strlen(char *str);
    char *my_strdup(char *src);
    int main(int ac, char **av);
    int my_putstr(char const *str);
    int check_if_no_enter(int ac, char **av);
    void sort_word_array3(int argc, char **argv);
    void sort_word_array2(int argc, char **argv);
    void sort_word_array1(int argc, char **argv);
    void sort_word_array4(int argc, char **argv);
    int my_strcmp(char const *s1 , char const *s2);
    int check_if_file_exists(const char *filename);
    int my_strcmp_bis(char const *s1 , char const *s2);
    variables_t display(DIR *directori, variables_t var);
    variables_t dec_var(variables_t var, int ac, char **av);
    int display_good_order(variables_t var, char **av, int ac);
    void sort_word_array5(int argc, char **argv, variables_t var);
    variables_t display_basic(variables_t var, char **av, int ac);
    variables_t display_basic_bis(variables_t var, char **av, int ac);
    variables_t check_flag_function2(variables_t var, char **av, int i);
    variables_t check_flag_function(variables_t var, char **av, int ac, int i);
    variables_t check_if_flag_or_not(variables_t var, int ac, char **av,\
    int i);
    variables_t display_good_order_d(variables_t var, char **av, int a,\
    int ac);
    variables_t display_good_order_r(variables_t var, char **av, int a,\
    int ac);
#endif
