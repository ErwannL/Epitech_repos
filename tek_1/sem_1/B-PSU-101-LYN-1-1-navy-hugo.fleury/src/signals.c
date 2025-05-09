/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-navy-hugo.fleury
** File description:
** signals
*/

#include "navy.h"

void handle_answer(int sig, siginfo_t *info, void *secret)
{
    game->atk += ((sig == SIGUSR1) ? 1 : ((sig == SIGUSR2) ? 2 : 0));
}

void handle_signal(int sig, siginfo_t *info, void *secret)
{
    game->pid_enemy = info->si_pid;
}

void handle_reception(int sig, siginfo_t *info, void *secret)
{
    game->coo += ((sig == SIGUSR2) ? 1 : 0);
    if (sig == SIGUSR1) {
        game->x += ((game->coo == 1) ? 1 : 0);
        game->y += ((game->coo == 2) ? 1 : 0);
    }
}

void send_attack(int x, int y)
{
    kill(game->pid_enemy, SIGUSR2);
    for (int i = 0; i != x; kill(game->pid_enemy, SIGUSR1), usleep(10), i++);
    kill(game->pid_enemy, SIGUSR2);
    for (int i = 0; i != y; kill(game->pid_enemy, SIGUSR1), usleep(10), i++);
    kill(game->pid_enemy, SIGUSR2);
}

void connect(int x)
{
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = ((x == 0) ? handle_signal
                            : ((x == 1) ? handle_answer : handle_reception));
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    if (x == 2) {
        for (; game->coo != 3; pause());
    } else {
        pause();
    }
}
