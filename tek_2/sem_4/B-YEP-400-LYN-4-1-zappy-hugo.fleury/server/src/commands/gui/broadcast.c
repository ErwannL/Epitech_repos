/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** broadcast
*/

#include "../../../include/my_teams.h"

int handle_broadcast(my_ftp_t *myftp, user_t *user, char *input_str)
{
    if (!user->state && dprintf(user->fd, "sbp (please connect first)\n"))
        return -1;

    char *value = (input_str != NULL) ? strtok(input_str, " ") : NULL;
    value = strtok(NULL, " ");
    int number_player = (value != NULL) ? atoi(value) : 0;

    if (value == NULL) {
        dprintf(user->fd, "Invalid command format\n");
        return -1;
    }
    char *message = strtok(NULL, "\0");
    if (message == NULL) {
        dprintf(user->fd, "Invalid command format\n");
        return -1;
    }
    dprintf(user->fd, "Player {%d}: %s\n", number_player, message);
    myftp = myftp;
    return 0;
}
