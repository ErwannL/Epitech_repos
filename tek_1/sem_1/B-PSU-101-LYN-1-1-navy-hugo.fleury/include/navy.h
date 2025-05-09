/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-navy-hugo.fleury
** File description:
** navy
*/

#ifndef NAVY_H_
    #define NAVY_H_
    #include "my.h"
    #include <stdio.h>
    #include <fcntl.h>
    #include <string.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <sys/types.h>

    typedef struct {
        char **game_player;
        char **game_enemy;
        pid_t pid_player;
        pid_t pid_enemy;
        int *dimensions;
        char *input;
        char **map;
        char *buf;
        int coo;
        int atk;
        int y;
        int x;
    } game_t;

    extern game_t *game;

    int win(int x);

    int open_file(char *what);
    int *get_dimensions(char *str);
    int error_handling(int argc, char **argv);

    int player_two(char *pid, game_t *game);
    int player_one(game_t *game);

    int get_pos_int(char what);
    char **setup_boats(char **array);
    int file_params_are_valids(void);
    char **setup_map_positions(int x);

    void display_maps(void);
    char *print_prompt(void);
    char get_pos_char(int what);
    void attack_is_valid(int x, int y);
    void print_atk_status(int x, int y, int what);

    void connect(int x);
    void send_attack(int x, int y);
    void handle_signal(int sig, siginfo_t *info, void *secret);
    void handle_answer(int sig, siginfo_t *info, void *secret);
#endif
