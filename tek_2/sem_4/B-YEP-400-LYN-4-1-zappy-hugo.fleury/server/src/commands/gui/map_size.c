/*
** EPITECH PROJECT, 2023
** antoine [WSL: Ubuntu]
** File description:
** map_size
*/

#include "../../../include/my_teams.h"

int handle_map_size(my_ftp_t *myftp, user_t *user, char *input_str)
{
    input_str = input_str;
    if (!user->state && dprintf(user->fd, "sbp (please connect first)\n"))
        return (-1);
    dprintf(user->fd, "msz %d %d\n", myftp->config->width, myftp->config->height);
    return (0);
}
