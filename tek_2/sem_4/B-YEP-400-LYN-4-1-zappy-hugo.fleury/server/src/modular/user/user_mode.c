/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-server.fillaudeau
** File description:
** user_mode
*/

#include "../../../include/my_teams.h"

int mode_constructor(user_t *user)
{
    user->set_mode = &set_mode;
    user->get_mode = &get_mode;
    return (0);
}

int set_mode(user_t *user, int mode)
{
    user->mode = mode;
    return (0);
}

int get_mode(user_t *user)
{
    return (user->mode);
}
