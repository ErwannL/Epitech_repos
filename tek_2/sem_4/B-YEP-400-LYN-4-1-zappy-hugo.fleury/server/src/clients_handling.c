/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-server.fillaudeau
** File description:
** clients_handling
*/

#include "../include/my_teams.h"

int check_client_exists(my_ftp_t *myftp, int fd)
{
    for (user_t *tmp = myftp->client->user; tmp; tmp = tmp->next)
        if (tmp->fd == fd)
            return (1);
    return (0);
}

user_t *get_user(my_ftp_t *myftp, int fd)
{
    for (user_t *tmp = myftp->client->user; tmp; tmp = tmp->next)
        if (tmp->fd == fd)
            return (tmp);
    return (NULL);
}

int handle_client(my_ftp_t *myftp, int fd)
{
    if (check_client_exists(myftp, fd))
        return (0);
    myftp->server->client_number += 1;
    put_users(myftp, (int[4]){fd, myftp->server->socket_fd, 0
    , myftp->server->port}
    , (char *[3]){NULL, inet_ntoa(myftp->client->address.sin_addr)
    , myftp->server->path});
    return (0);
}
