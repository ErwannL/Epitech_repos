/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-erwann.laplante
** File description:
** my
*/

#ifndef MY_H_

    //define

    #define MY_H_
    #define TRUE 0
    #define FALSE 1
    #define GAME 0
    #define PAUSE 1

    //include

    #include <stdlib.h>
    #include <unistd.h>
    #include <ncurses.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <time.h>

    //strcut

    typedef struct arguments {
        int level;
        int key_left;
        int key_right;
        int key_turn;
        int key_drop;
        int key_quit;
        int key_pause;
        int *map_size;
        int without_next;
    } arg_t;

    typedef struct tetri {
        int width;
        int height;
        int color;
        char *name;
        char **patern;
        void *next;
    } tetri_t;

    typedef struct variable {
        WINDOW *my_win;
        arg_t *arg;
        DIR *directory;
        struct dirent *dir;
        int fd;
        int st;
        struct stat *statu;
        int size;
        char *tetrimino;
        int num;
        char **map;
        int ch;
        int nbr_node;
        tetri_t *tetri;
        int a;
        int b;
        int full;
        tetri_t *cursor;
        int n;
        int destroy_line;
        int speed;
        int stat;
        int next_n;
        tetri_t *next_cursor;
    } var_t;

    //lib

    void my_putchar(char c);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_put_nbr(int nb);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_int_to_str(int nb);
    int my_str_is_int(char *str);
    int my_str_is_char(char *str);
    int my_str_to_int(char *str);
    int my_str_is_int_coma(char *str);
    int my_str_to_int_coma(char *str);
    int my_int_len(int nbr);
    char *my_revstr(char *str);
    char *my_strcat(char *dest, char *src);
    char *my_strcpy(char *dest , char const *src);

    //sources

    var_t *init_struct(var_t *var);
    void free_all(var_t *var);
    var_t *arg_pars(var_t *var, int ac, char **av);
    int launch_debug(var_t *var);
    int good_tetrimino(char *str);
    void put_name(var_t *var);
    void put_key(int key, char *name);
    int launch_game(var_t *var);
    void print_map(var_t *var);
    void create_node(char *name, char *tet, tetri_t *new);
    var_t *fill_map(var_t *var, int i, int j);
    var_t *put_piece(var_t *var, tetri_t *piece, int x, int y);
    var_t *clear_piece(var_t *var, tetri_t *piece, int x, int y);
    int init_chained(var_t *var);
    int full_line(var_t *var);
    int check_down(char **map, tetri_t *piece, int a, int b);
    int check_right(char **map, tetri_t *piece, int a, int b);
    int check_left(char **map, tetri_t *piece, int a, int b);
    int check_loose(var_t *var);
    var_t *arg_pars_six(var_t *var, char **av, int i);
    tetri_t *turn_piece(var_t *var, tetri_t *old_piece, int a, int b);
    var_t *init_map(var_t *var);
    var_t *place_piece(var_t *var, int num);
    var_t *handle_key(var_t *var);
    var_t *del_full_line(var_t *var);
    var_t *new_piece(var_t *var);
    void print_info_for(var_t *var);

#endif
