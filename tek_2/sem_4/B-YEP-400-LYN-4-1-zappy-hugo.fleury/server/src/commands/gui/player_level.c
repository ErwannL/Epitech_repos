/*
** EPITECH PROJECT, 2023
** antoine [WSL: Ubuntu]
** File description:
** player_level
*/

#include "../../../include/my_teams.h"

int handle_player_level(my_ftp_t *myftp, user_t *user, char *input_str)
{
    if (!user->state && dprintf(user->fd, "sbp (please connect first)\n"))
        return (-1);
    char *value = input_str ? strtok(input_str, " ") : NULL;
    int player_number = 0;

    value = strtok(NULL, " ");
    if (!value && dprintf(user->fd, "sbp (/plv #n)\n"))
        return (-1);
    if (!(player_number = atoi(value)) &&\
    dprintf(user->fd, "sbp (/plv #n)\n"))
        return (-1);
    for (user_t *tmp = myftp->client->user; tmp; tmp = tmp->next) {
        if (tmp->infos->number == player_number) {
            dprintf(user->fd, "plv %d %d\n", tmp->infos->number,\
            tmp->infos->level);
            return (0);
        }
    }
    dprintf(user->fd, "sbp (number not found)\n");
    return (-1);
}
