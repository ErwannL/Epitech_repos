/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-server.fillaudeau
** File description:
** user_ip
*/

#include "../../../include/my_teams.h"

int ip_constructor(user_t *user)
{
    user->set_ip = &set_ip;
    user->get_ip = &get_ip;
    return (0);
}

int set_ip(user_t *user, char *ip)
{
    user->ip = my_strcpy(ip, 0);
    return (0);
}

char *get_ip(user_t *user)
{
    return (user->ip);
}
