/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-server.fillaudeau
** File description:
** user_username
*/

#include "../../../include/my_teams.h"

int username_constructor(user_t *user)
{
    user->set_username = &set_username;
    user->get_username = &get_username;
    return (0);
}

int set_username(user_t *user, char *username)
{
    user->username = !username ? "UNKNOWN" : my_strcpy(username, 1);
    return (0);
}

char *get_username(user_t *user)
{
    return (user->username);
}
