/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** death
*/

#include "../../include/my_teams.h"

int handle_death(my_ftp_t *myftp, user_t *user, char *input_str)
{
    if (!user->state && dprintf(user->fd, "sbp (please connect first)\n"))
        return (-1);

    char *value = (input_str != NULL) ? strtok(input_str, " ") : NULL;
    value = strtok(NULL, " ");
    int number_player = (value != NULL) ? atoi(value) : 0;
    dprintf(user->fd, "Player {%d} is dead\n", number_player);
}
