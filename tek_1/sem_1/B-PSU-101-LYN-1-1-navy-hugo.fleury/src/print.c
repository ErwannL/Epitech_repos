/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-navy-hugo.fleury
** File description:
** print
*/

#include "navy.h"

char get_pos_char(int what)
{
    switch (what) {
        case 2 : return 'A';
        case 4 : return 'B';
        case 6 : return 'C';
        case 8 : return 'D';
        case 10 : return 'E';
        case 12 : return 'F';
        case 14 : return 'G';
        case 16 : return 'H';
    }
    return 'X';
}

void attack_is_valid(int x, int y)
{
    if ((game->game_player[y][x] != '.') && (game->game_player[y][x] != 'o'))
        game->atk = 1;
    if ((game->game_player[y][x] == '.') || (game->game_player[y][x] == 'o'))
        game->atk = 2;
}

void print_atk_status(int x, int y, int what)
{
    if (what == 1) {
        game->game_enemy[y][x] = ((game->atk == 1) ? 'x' : 'o');
    } else {
        game->game_player[y][x] = ((game->atk == 1) ? 'x' : 'o');
    }
    my_printf("%c%i: %s\n\n", get_pos_char(x), y - 1
                                    , ((game->atk == 1) ? "hit" : "missed"));
}

void display_maps(void)
{
    my_printf("my positions:\n");
    for (int i = 0; i != 10; i++) {
        for (int j = 0; j != 17; j++) {
            my_printf("%c", game->game_player[i][j]);
        }
        my_printf("\n");
    }
    my_printf("\nenemy's positions:\n");
    for (int i = 0; i != 10; i++) {
        for (int j = 0; j != 17; j++) {
            my_printf("%c", game->game_enemy[i][j]);
        }
        my_printf("\n");
    }
    my_printf("\n");
}

char *print_prompt(void)
{
    size_t size = 3;
    char *buf = malloc(sizeof(char) * (size + 1));

    my_printf("attack: ");
    if (getline(&buf, &size, stdin) == EOF)
        return NULL;
    if (my_strlen(buf) != 3 || buf[0] < 'A' || buf[0] > 'H' || buf[1] < '1'
                                                            || buf[1] > '8') {
        free(buf);
        my_printf("wrong position\n");
        print_prompt();
    }
    return buf;
}
