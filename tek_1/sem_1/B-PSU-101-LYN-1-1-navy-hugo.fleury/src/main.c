/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-navy-hugo.fleury
** File description:
** main
*/

#include "navy.h"

game_t *game = NULL;

int win(int x)
{
    int boats = 14;

    for (int i = 0; i != 10; i++) {
        for (int j = 0; j != 17; j++) {
            boats -= ((x == 0) ? ((game->game_player[i][j] == 'x') ? 1 : 0)
                                : ((game->game_enemy[i][j] == 'x') ? 1 : 0));
        }
    }
    return boats;
}

int help(void)
{
    my_printf("USAGE\n"
        "     ./navy [first_player_pid] navy_positions\n"
        "DESCRIPTION\n"
        "     first_player_pid: only for the 2nd player."
        " pid of the first player.\n"
        "     navy_positions: file representing "
        "the positions of the ships.\n");
    return 0;
}

void free_all(int ret)
{
    if (ret != 84) {
        for (int i = 0; i != 10; free(game->game_player[i]), i++);
        for (int i = 0; i != 10; free(game->game_enemy[i]), i++);
    }
    free(game->game_player);
    free(game->game_enemy);
    free(game->dimensions);
}

int main(int argc, char **argv)
{
    int ret = 0;
    game = malloc(sizeof(game_t));

    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0) {
            free(game);
            return help();
        } else if (argv[1][0] == '-') {
            my_printf("[navy]: unrecognized flag, retry with -h.\n");
            free(game);
            return 84;
        }
    }
    if ((ret = error_handling(argc, argv)) != 84) {
        ret = ((argc == 2) ? player_one(game) : player_two(argv[1], game));
        free_all(ret);
    }
    free(game);
    return ret;
}
