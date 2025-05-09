/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** time_unit_request
*/

#include "../../../include/my_teams.h"

int handle_tur(my_ftp_t *myftp, user_t *user, char *input_str)
{
    input_str = input_str;
    if (!user->state && dprintf(user->fd, "sbp (please connect first)\n"))
        return (-1);
    dprintf(user->fd, "sgt %f\n", 1.0/myftp->config->frequency);
    return (0);
}
