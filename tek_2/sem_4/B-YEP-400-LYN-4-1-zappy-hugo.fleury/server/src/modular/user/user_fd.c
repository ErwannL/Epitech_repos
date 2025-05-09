/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-server.fillaudeau
** File description:
** user_fd
*/

#include "../../../include/my_teams.h"

int fd_constructor(user_t *user)
{
    user->set_fd = &set_fd;
    user->get_fd = &get_fd;
    return (0);
}

int set_fd(user_t *user, int fd)
{
    user->fd = fd;
    return (0);
}

int get_fd(user_t *user)
{
    return (user->fd);
}
