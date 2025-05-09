/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-server.fillaudeau
** File description:
** users_handling
*/

#include "../include/my_teams.h"

/* @param my_ftp_t as myftp global var
** @param params_int as (int[4]){fd, socket, state, port}
** @param params_chars as (char *[3]){username, ip, path}
*/
int put_users(my_ftp_t *myftp, int params_int[4], char *params_char[3])
{
    user_t *user = malloc(sizeof(user_t));

    user_constructor(user);
    user->set_fd(user, params_int[0]);
    user->set_socket(user, params_int[1]);
    user->set_state(user, params_int[2]);
    user->set_port(user, params_int[3]);
    user->set_mode(user, 0);
    user->set_username(user, NULL);
    user->set_input_str(user, NULL);
    user->set_ip(user, params_char[1]);
    user->set_path(user, params_char[2]);
    user->next = myftp->client->user;
    myftp->client->user = user;
    return (0);
}

int get_users_size(my_ftp_t *my_ftp)
{
    int len = 0;

    for (user_t *tmp = my_ftp->client->user; tmp; len++, tmp = tmp->next);
    return (len);
}

int delete_users(my_ftp_t *myftp)
{
    user_t *prev = NULL;
    int i = 0;

    for (user_t *tmp = myftp->client->user; tmp; prev = tmp
    , tmp = tmp->next) {
        if (i++ != 0) {
            free(prev);
            tmp->ip ? free(tmp->ip) : 0;
            tmp->path ? free(tmp->path) : 0;
            tmp->str ? free(tmp->str) : 0;
        } else {
            tmp->ip ? free(tmp->ip) : 0;
            tmp->path ? free(tmp->path) : 0;
            tmp->str ? free(tmp->str) : 0;
        }
    }
    free(prev);
    return (0);
}
