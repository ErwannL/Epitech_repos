/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-server.fillaudeau
** File description:
** user_socket
*/

#include "../../../include/my_teams.h"

int socket_constructor(user_t *user)
{
    user->set_socket = &set_socket;
    user->get_socket = &get_socket;
    return (0);
}

int set_socket(user_t *user, int socket)
{
    user->socket = socket;
    return (0);
}

int get_socket(user_t *user)
{
    return (user->socket);
}
