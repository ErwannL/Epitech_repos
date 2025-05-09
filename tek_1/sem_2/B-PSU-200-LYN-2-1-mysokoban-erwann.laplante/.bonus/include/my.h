/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-erwann.laplante
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdlib.h>
    #include <unistd.h>
    #include <ncurses.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    typedef struct variable {
        WINDOW *my_win;
        int ch;
        int fd;
        char *buf_map;
        int size;
        struct stat buf;
        int num;
        int len;
        char **map;
        int line;
        int count;
        int index;
        int number;
        int x;
        int y;
        char **save_map;
        int start_x;
        int start_y;
        int r_val;
        int ex_num;
    }var_t;
    void my_putchar(char c);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strcpy(char *dest , char const *src);
    char *my_strncpy(char *dest , char const *src, int n);
    void my_str_to_word_array(char *str, var_t *var);
    void print_h(void);
    void print_map(char **map, var_t *var);
    var_t *cpy_word_array(var_t *var);
    var_t *reset_map(var_t *var);
    int error(char *str);
    var_t *init_struct(var_t *var, char **argv);
    void free_all(var_t *var);
    char **find_o(char **save, int max, char **map);
    var_t *move_down(var_t *var);
    var_t *move_up(var_t *var);
    var_t *move_right(var_t *var);
    var_t *move_left(var_t *var);
    var_t *move_player(var_t *var);
    var_t *restart(int argc, char **argv, var_t *var);
    int my_sokoban(int argc, char **argv);
    int check_win(char **save, int max, char **map);
    int check_loose(char **save, int max, char **map);
#endif
