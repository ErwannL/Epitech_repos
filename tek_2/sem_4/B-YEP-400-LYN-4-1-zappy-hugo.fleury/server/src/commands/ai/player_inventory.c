/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** player_inventory
*/

#include "../../../include/my_teams.h"

int print_inventory_ai(user_t *user)
{
    char *res_names[7] = {"food", "linemate", "deraumere", "sibur", "mendiane"\
    , "phiras", "thystame"};

    dprintf(user->fd, "[");
    for (unsigned int i = 0; i < 7; i++)
        i ? dprintf(user->fd, ", %s %d", res_names[i]\
        , get_resource(user->infos->resources, i))\
        : dprintf(user->fd, "%s %d", res_names[i]\
        , get_resource(user->infos->resources, i));
    dprintf(user->fd, "]");
    return (1);
}

int handle_player_inventory_ai(my_ftp_t *myftp, user_t *user, char *input_str)
{
    myftp = myftp;
    input_str = input_str;
    if (!user->state && dprintf(user->fd, "sbp (please connect first)\n"))
        return (-1);
    print_inventory_ai(user);
    return (-1);
}
