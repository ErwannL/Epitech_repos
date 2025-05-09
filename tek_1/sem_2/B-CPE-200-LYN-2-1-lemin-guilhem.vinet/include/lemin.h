/*
** EPITECH PROJECT, 2021
** lemin
** File description:
** lemin
*/

#ifndef LEMIN_H_
    #define LEMIN_H_

    //include

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <unistd.h>

    //put_str

    #define MY_PUTSTR(x, y) \
                        for (int i = 0; x[i] != '\0'; write(y, &x[i], 1), i++)
    //struct

    typedef struct Element Element;
    struct Element
    {
        char *name;
        int start;
        int end;
        Element *next;
    };

    typedef struct List {
        Element *first;
    } List;

    typedef struct node {
        char *name;
        char *next;
    } node_t;

    typedef struct dij {
        char *now_name;
        int nbr_node;
        node_t *nodes;
        char *end;
        char **path;
        int stop;
    } dij_t;

    typedef struct path {
        int nbr_node;
        char **path;
    } path_t;

    typedef struct ants {
        int finish;
        int nbr_path;
        char *where;
        char *path;
        int print;
    } ants_t;

    //lib

    int find_len(char *str);
    int len_tab(char **buf);
    int str_cmp(char *str1, char *str2);
    char *my_revstr(char *str);
    char *my_strcat(char *dest, char *src);
    char *my_strncat(char *dest, char *src, int n);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strcpy(char *dest, char const *src);
    int my_strlen(char const *str);
    char **my_str_to_word_array(char const *str, int *dims);
    int my_getnbr(char const *str, int i);
    void my_putchar (char c);
    int my_putstr(char const *str);
    int my_str_to_int(char *str);
    char *my_int_to_str(int nb);
    char *clean_string(char *str);

    //src

    List *init(void);
    int insertion(List *list, char *newname, int nb);
    int delete(List *list, int pos);
    int print_chain(List *list);
    char **word_array(char *str, char sep);
    char *cut_name(char *name);
    int check_room(char *line);
    int check_twins(List *room_list, char *new_name);
    int is_start(char **buf, List *room);
    int *get_dimensions(char *str);
    path_t *main_di(path_t *r_path, List *room_list, List *path,
    List *comp_room);
    dij_t *dijkstra(dij_t *diji);
    node_t create_node(char *name);
    node_t modif_node(node_t node, char *next);
    char *get_next(char *all_next);
    char *get_prev(char *str);
    int find_end(dij_t *diji);
    int is_path(char *line);
    int test_name(char **buf, List *room);
    int is_room(char **buf, List *room_list);
    char **chain_to_array(List *list);
    int len_array(char **array);
    void print_info(char **buf, List *comp_room, List *path);
    int compare_checkpoint(char *name, List *room);
    void take_data();
    int error_handling(char **buf, List *room_list, List *comp_room
    , List *path);
    int get_nbroom(List *room);
    char *clean_start(char *start);
    char *get_start(List *comp_room);
    char *get_end(List *comp_room);
    char *get_start_path(char *path);
    char *get_end_path(char *path);
    dij_t *rm_node(dij_t *diji);
    char *no_next(dij_t *diji, char *now_next, int i);
    int get_len_path(char *path);
    int fin_mini_path(int *path, int max);
    int all_finish(ants_t *ant, int nbr);
    void print_info_ant(int max, ants_t *all_ants, int space, ants_t ants);
    ants_t get_next_ant(ants_t ants, ants_t *all_ants, int max, int space);
    char *cut_com(char *buf);

#endif
