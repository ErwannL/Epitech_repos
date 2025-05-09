/*
** EPITECH PROJECT, 2023
** antoine
** File description:
** player_position
*/

#include "../../../include/my_teams.h"

int handle_player_position(my_ftp_t *myftp, user_t *user, char *input_str)
{
    if (!user->state && dprintf(user->fd, "sbp (please connect first)\n"))
        return (-1);
    char *value = input_str ? strtok(input_str, " ") : NULL;
    int player_number = 0;

    value = strtok(NULL, " ");
    if (!value && dprintf(user->fd, "sbp (/ppo #n)\n"))
        return (-1);
    if (!(player_number = atoi(value)) &&\
    dprintf(user->fd, "sbp (/ppo #n)\n"))
        return (-1);
    for (user_t *tmp = myftp->client->user; tmp; tmp = tmp->next) {
        if (tmp->infos->number == player_number) {
            dprintf(user->fd, "ppo %d %d %d %d\n", tmp->infos->number,\
            tmp->infos->x, tmp->infos->y, tmp->infos->orientation);
            return (0);
        }
    }
    dprintf(user->fd, "sbp (number not found)\n");
    return (-1);
}