/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** connect_nbr
*/

#include "../../../include/my_teams.h"

int get_client_nbr(my_ftp_t *myftp)
{
    int graphic_nb = myftp->gui.graphic_state == CONNECTED ? 1 : 0;
    int n = 0;

    for (user_t *tmp = myftp->client->user; tmp; tmp = tmp->next, n++);
    return (n - graphic_nb);
}

int handle_connect_nbr(my_ftp_t *myftp, user_t *user, char *input_str)
{
    input_str = input_str;
    if (!user->state && dprintf(user->fd, "sbp (please connect first)\n"))
        return (-1);
    dprintf(user->fd, "connect_nbr: %d\n", get_client_nbr(myftp));
    return (0);
}
