/*
** EPITECH PROJECT, 2023
** antoine [WSL: Ubuntu]
** File description:
** team_name
*/

#include "../../../include/my_teams.h"

int handle_team_name(my_ftp_t *myftp, user_t *user, char *input_str)
{
    input_str = input_str;
    if (!user->state && dprintf(user->fd, "sbp (please connect first)\n"))
        return (-1);
    for (int i = 0; i < myftp->config->numTeams; i++)
        dprintf(user->fd, "tna %s\n", myftp->config->teamNames[i]);
    return (0);
}
