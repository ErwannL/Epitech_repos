/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-server.fillaudeau
** File description:
** user_input_str
*/

#include "../../../include/my_teams.h"

int input_str_constructor(user_t *user)
{
    user->set_input_str = &set_input_str;
    user->get_input_str = &get_input_str;
    return (0);
}

int set_input_str(user_t *user, char *input_str)
{
    user->str = !input_str ? NULL : my_strcpy(input_str, 1);
    return (0);
}

char * get_input_str(user_t *user)
{
    return (user->str);
}
