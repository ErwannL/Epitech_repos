/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** time_unit_modification
*/

#include "../../../include/my_teams.h"

int handle_tum(my_ftp_t *myftp, user_t *user, char *input_str)
{
    char *value = input_str ? strtok(input_str, " ") : NULL;
    int n = 0;

    if (!user->state)
        return (-1);
    value = strtok(NULL, " ");
    if ((!value || !(n = atoi(value))) && dprintf(user->fd, "sbp\n"))
        return (-1);
    myftp->config->frequency = n;
    dprintf(user->fd, "sst %f", 1 / myftp->config->frequency);
    return (0);
}
