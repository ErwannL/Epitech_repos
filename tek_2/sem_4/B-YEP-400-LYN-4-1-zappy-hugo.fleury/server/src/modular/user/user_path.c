/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-server.fillaudeau
** File description:
** user_path
*/

#include "../../../include/my_teams.h"

int path_constructor(user_t *user)
{
    user->set_path = &set_path;
    user->get_path = &get_path;
    return (0);
}

int set_path(user_t *user, char *path)
{
    user->path = my_strcpy(path, 0);
    return (0);
}

char *get_path(user_t *user)
{
    return (user->path);
}
