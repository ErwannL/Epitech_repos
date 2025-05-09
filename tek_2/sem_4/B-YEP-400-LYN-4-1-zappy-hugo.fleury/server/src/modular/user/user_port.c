/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-server.fillaudeau
** File description:
** user_port
*/

#include "../../../include/my_teams.h"

int port_constructor(user_t *user)
{
    user->set_port = &set_port;
    user->get_port = &get_port;
    return (0);
}

int set_port(user_t *user, int port)
{
    user->port = port;
    return (0);
}

int get_port(user_t *user)
{
    return (user->port);
}
