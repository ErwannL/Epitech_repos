/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-guilhem.vinet
** File description:
** my
*/

#ifndef MY_H_

    //define

    #define MY_H_

    //include

    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    //struct

    typedef struct var {
        int fd;
        struct stat statut;
        int size;
        char *buffer;
        char **maze;
        int st;
        int rd;
        int finish;
        int size_y;
        int size_x;
    } var_t;

    //lib

    char *int_to_str(int nb);
    int my_put_nbr(int nb);
    void my_putchar(char c);
    int my_putstr(char const *str);
    char *my_revstr(char *str);
    char *my_strcat(char *dest, char *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest , char const *src);
    int my_strlen(char const *str);
    char **my_str_to_word_array(char *str, char **array);

    //src

    int main(int argc, char **argv);

#endif
