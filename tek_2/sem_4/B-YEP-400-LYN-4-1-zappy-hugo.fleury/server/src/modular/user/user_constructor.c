/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-server.fillaudeau
** File description:
** user_constructor
*/

#include "../../../include/my_teams.h"

int user_constructor(user_t *user)
{
    fd_constructor(user);
    socket_constructor(user);
    state_constructor(user);
    port_constructor(user);
    mode_constructor(user);
    username_constructor(user);
    input_str_constructor(user);
    ip_constructor(user);
    path_constructor(user);
    return (0);
}
