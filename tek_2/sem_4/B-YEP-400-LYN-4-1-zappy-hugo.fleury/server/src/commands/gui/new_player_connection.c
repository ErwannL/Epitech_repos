/*
** EPITECH PROJECT, 2023
** antoine [WSL: Ubuntu]
** File description:
** new_player_connection
*/

#include "../../../include/my_teams.h"

int random_value(int max)
{
    srand(time(NULL));
    int number = rand() % max;
    return (number);
}

int handle_new_player_connection(my_ftp_t *myftp, user_t *user, char *input_s)
{
    input_s = input_s;
    user->infos = malloc(sizeof(player_infos_t));
    user->infos->resources = malloc(sizeof(resources_t));
    for (unsigned int i = 0; i < 7; i++)
        new_resource(&user->infos->resources, i);
    user->infos->level = 0;
    user->infos->number = 0;
    for (user_t *users = myftp->client->user; users; users = users->next)
        user->infos->number++;
    user->infos->orientation = 1;
    user->infos->x = random_value(myftp->config->width);
    user->infos->y = random_value(myftp->config->height);
    dprintf(user->fd, "%d %d", user->infos->x, user->infos->y);
    user->infos->orientation = 0;
    user->infos->x = 0;
    user->infos->y = 0;
    user->infos->tick_remaining = 0;
    user->infos->team_name = NULL;
    user->state = 1;
    dprintf(user->fd, "pnw %d %d %d %d %d %s\n", user->infos->number,\
    user->infos->x, user->infos->y, user->infos->orientation,\
    user->infos->level, user->infos->team_name);
    return (0);
}

int handle_new_ai_connection(my_ftp_t *myftp, user_t *user, char *input_s)
{
    input_s = input_s;
    user->infos = malloc(sizeof(player_infos_t));
    user->infos->resources = malloc(sizeof(resources_t));
    for (unsigned int i = 0; i < 7; i++)
        new_resource(&user->infos->resources, i);
    user->infos->level = 0;
    user->infos->number = 0;
    for (user_t *users = myftp->client->user; users; users = users->next)
        user->infos->number++;
    user->infos->orientation = 0;
    user->infos->x = rand() % myftp->config->width;
    user->infos->y = rand() % myftp->config->height;
    printf("new ai connected at : %i, %i\n", user->infos->x, user->infos->y);
    user->infos->team_name = NULL;
    user->state = 1;
    dprintf(user->fd, "%i\n%i %i\n", get_client_nbr(myftp), myftp->config->width, myftp->config->height);
    if (myftp->gui.graphic_state == CONNECTED) {
        dprintf(myftp->gui.fd, "pnw %d %d %d %d %d %s\n", user->infos->number,\
        user->infos->x, user->infos->y, user->infos->orientation,\
        user->infos->level, user->infos->team_name);
    }
    return (0);
}
