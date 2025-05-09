/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-navy-hugo.fleury
** File description:
** players
*/

#include "navy.h"

void reset(int x)
{
    game->atk = ((x == 0) ? 0 : game->atk);
    game->coo = ((x != 0) ? 0 : game->coo);
    game->x = 0;
    game->y = 0;
}

int game_one(void)
{
    reset(0);
    if ((game->input = print_prompt()) == NULL)
        return 0;
    send_attack(get_pos_int(game->input[0]), (game->input[1] - 48) + 1);
    connect(1);
    print_atk_status(get_pos_int(game->input[0]), (game->input[1] - 48) + 1
                                                                        , 1);
    if ((win(0) == 0) || (win(1) == 0))
        return 2;
    my_printf("waiting for enemy's attack...\n");
    reset(1);
    connect(2);
    attack_is_valid(game->x, game->y);
    kill(game->pid_enemy, (game->atk == 1) ? SIGUSR1 : SIGUSR2);
    print_atk_status(game->x, game->y, 0);
    free(game->input);
    if ((win(0) == 0) || (win(1) == 0))
        return 2;
    display_maps();
    return 1;
}

int game_two(void)
{
    reset(1);
    my_printf("waiting for enemy's attack...\n");
    connect(2);
    attack_is_valid(game->x, game->y);
    kill(game->pid_enemy, (game->atk == 1) ? SIGUSR1 : SIGUSR2);
    print_atk_status(game->x, game->y, 0);
    reset(0);
    if ((win(0) == 0) || (win(1) == 0))
        return 2;
    if ((game->input = print_prompt()) == NULL)
        return 0;
    send_attack(get_pos_int(game->input[0]), (game->input[1] - 48) + 1);
    connect(1);
    print_atk_status(get_pos_int(game->input[0]), (game->input[1] - 48) + 1
                                                                        , 1);
    free(game->input);
    if ((win(0) == 0) || (win(1) == 0))
        return 2;
    display_maps();
    return 1;
}

int player_one(game_t *game)
{
    my_printf("my_pid: %d\nwaiting for enemy connection...\n\n"
                                            , (game->pid_player = getpid()));
    connect(0);
    my_printf("enemy connected\n\n");
    game->game_player = setup_map_positions(1);
    game->game_enemy = setup_map_positions(0);
    display_maps();
    while (game_one() != 2);
    display_maps();
    my_printf("%s", ((win(1) == 0) ? "I won\n\n" : "Enemy won\n\n"));
    return ((win(1) == 0) ? 0 : 84);
}

int player_two(char *pid, game_t *game)
{
    game->pid_player = getpid();
    game->pid_enemy = my_atoi(pid);
    my_printf("my_pid: %d\n", getpid());
    if (kill(game->pid_enemy, SIGUSR1) == -1)
        return 84;
    my_printf("successfully connected\n\n");
    game->game_player = setup_map_positions(1);
    game->game_enemy = setup_map_positions(0);
    display_maps();
    while (game_two() != 2);
    display_maps();
    my_printf("%s", ((win(1) == 0) ? "\nI won\n\n" : "\nEnemy won\n\n"));
    return ((win(1) == 0) ? 0 : 84);
}
