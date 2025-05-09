/*
** EPITECH PROJECT, 2023
** antoine [WSL: Ubuntu]
** File description:
** player_inventory
*/

#include "../../../include/my_teams.h"

int print_inventory(user_t *user)
{
    dprintf(user->fd, "pin %d %d %d", user->infos->number,\
            user->infos->x, user->infos->y);
    for (unsigned int i = 0; i < 7; i++)
        dprintf(user->fd, " %d", get_resource(user->infos->resources, i));
    dprintf(user->fd, "\n");
    return (1);
}

int handle_player_inventory(my_ftp_t *myftp, user_t *user, char *input_str)
{
    if (!user->state && dprintf(user->fd, "sbp (please connect first)\n"))
        return (-1);
    char *value = input_str ? strtok(input_str, " ") : NULL;
    int player_number = 0;

    value = strtok(NULL, " ");
    if (!value && dprintf(user->fd, "sbp (/pin #n)\n"))
        return (-1);
    if (!(player_number = atoi(value)) &&\
    dprintf(user->fd, "sbp (/pin #n)\n"))
        return (-1);
    for (user_t *tmp = myftp->client->user; tmp; tmp = tmp->next)
        if (tmp->infos->number == player_number && print_inventory(tmp))
            return (0);
    dprintf(user->fd, "sbp (number not found)\n");
    return (-1);
}
