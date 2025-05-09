/*
** EPITECH PROJECT, 2023
** tech2
** File description:
** connection_handling
*/

#include "../include/my_teams.h"

typedef struct client_s_s {
    int socket_fd;
    struct sockaddr_in serv_addr;
    int login;
    char *user;
    char *uuid;
    fd_set fd;
} client_t_t;

int check_fd_is_new(my_ftp_t *myftp, int fd)
{
    if (fd == myftp->server->socket_fd) {
        myftp->client->sockfd = accept(myftp->server->socket_fd
        , (struct sockaddr *)&myftp->client->address
        , &myftp->server->size_socket);
        if (myftp->client->sockfd == -1)
            return (-1);
        dprintf(myftp->client->sockfd, "WELCOME\n");
        FD_SET(myftp->client->sockfd, &myftp->client->active_fd);
        return (1);
    }
    return (0);
}

int check_fd_exists(my_ftp_t *myftp, int fd)
{
    user_t *r_user = NULL;

    if (myftp->client->sockfd != -1) {
        if (handle_client(myftp, fd))
            return (-1);
        r_user = get_user(myftp, fd);
        return (handle_command(myftp, r_user));
    }
    return (-2);
}

int check_fd(my_ftp_t *myftp, int fd)
{
    int new = 0;
    int exists = 0;

    if (FD_ISSET(fd, &myftp->client->read_fd)) {
        if ((new = check_fd_is_new(myftp, fd)))
            return (!(new >> 1) ? 0 : -1);
        if ((exists = check_fd_exists(myftp, fd)) != -2)
            return (exists);
    }
    return (0);
}

int init_client_properties(my_ftp_t *myftp)
{
    int is_connected = 1;
    client_t_t *cli = malloc(sizeof(client_t_t));

    cli->serv_addr.sin_family = AF_INET;
    cli->serv_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    cli->serv_addr.sin_port = htons(myftp->config->port);
    cli->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (cli->socket_fd == -1 || (is_connected = connect(cli->socket_fd\
    , (struct sockaddr *) &cli->serv_addr, sizeof(cli->serv_addr))))
        return (1);
    cli->user = NULL;
    cli->uuid = NULL;
    close(cli->socket_fd);
    shutdown(cli->socket_fd, SHUT_RDWR);

    myftp->client->user = NULL;
    FD_ZERO(&myftp->client->active_fd);
    FD_SET(myftp->server->socket_fd, &myftp->client->active_fd);
    return (0);
}

int handle_connection(my_ftp_t *myftp)
{
    init_client_properties(myftp);
    for (int ret_value = 0; 1;) {
        handle_time_loop(myftp);
        myftp->client->read_fd = myftp->client->active_fd;
        if (select(FD_SETSIZE, &myftp->client->read_fd, NULL, NULL, NULL) < 0
        && close(myftp->server->socket_fd))
            return (-1);
        for (int i = 0; i != FD_SETSIZE; i++)
            (check_fd(myftp, i) && close(myftp->server->socket_fd)
            && (ret_value = 1));
        if (ret_value == 1) {
            return (-1);
        }
    }
    close(myftp->server->socket_fd);
    return (0);
}
