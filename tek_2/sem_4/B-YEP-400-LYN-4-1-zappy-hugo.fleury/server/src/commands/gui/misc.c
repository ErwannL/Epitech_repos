/*
** EPITECH PROJECT, 2023
** antoine [WSL: Ubuntu]
** File description:
** misc
*/

#include "../../../include/my_teams.h"

int handle_help(my_ftp_t *myftp, user_t *user, char *input_s)
{
    dprintf(user->fd, "Commands available:\n");
    dprintf(user->fd, "- /help\n");
    dprintf(user->fd, "- /connect\n");
    dprintf(user->fd, "- /msz\n");
    dprintf(user->fd, "- /ppo #n\n");
    dprintf(user->fd, "- /plv #n\n");
    dprintf(user->fd, "- /pin #n\n");
    dprintf(user->fd, "- /pgt #n\n");
    dprintf(user->fd, "- /pdr #n\n");
    dprintf(user->fd, "- /tna\n");
    dprintf(user->fd, "- /bct X Y\n");
    dprintf(user->fd, "- /mct\n");
    dprintf(user->fd, "- /pex #n\n");
    input_s = input_s;
    myftp = myftp;
    return 1;
}

int handle_quit(my_ftp_t *myftp, user_t *user, char *input_s)
{
    dprintf(myftp->client->sockfd, "pex %d\n", user->infos->number);
    myftp->server->client_number -= 1;
    user->state = 0;
    FD_CLR(user->fd, &myftp->client->active_fd);
    close(user->fd);
    user->username = "NONE";
    input_s = input_s;
    return (0);
}

int handle_expulsion(my_ftp_t *myftp, user_t *user, char *input_str)
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
            handle_quit(myftp, user, input_str);
            return (0);
        }
    }
    dprintf(user->fd, "sbp (number not found)\n");
    return (-1);
}
