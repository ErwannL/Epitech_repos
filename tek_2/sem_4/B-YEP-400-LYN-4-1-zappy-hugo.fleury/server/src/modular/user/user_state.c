/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-server.fillaudeau
** File description:
** user_state
*/

#include "../../../include/my_teams.h"

int state_constructor(user_t *user)
{
    user->set_state = &set_state;
    user->get_state = &get_state;
    return (0);
}

int set_state(user_t *user, int state)
{
    user->state = state;
    return (0);
}

int get_state(user_t *user)
{
    return (user->state);
}
