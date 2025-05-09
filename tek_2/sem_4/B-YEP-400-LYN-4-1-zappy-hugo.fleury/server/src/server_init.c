/*
** EPITECH PROJECT, 2023
** tech2
** File description:
** server_init
*/

#include "../include/my_teams.h"

int init_sever_properties(my_ftp_t *myftp, int b)
{
    if (!(b >> 1)) {
        myftp->server->port = myftp->config->port;
        myftp->server->path = myftp->get_argv(myftp)[2];
        myftp->server->client_number = 0;
    }
    (b >> 1) && ((myftp->server->address.sin_family = PF_INET)
    && (myftp->server->address.sin_port = htons(myftp->server->port))
    && (myftp->server->address.sin_addr.s_addr = INADDR_ANY) + 1
    && (myftp->server->size_addr = sizeof(myftp->server->address))
    && (myftp->server->size_socket = sizeof(myftp->server->socket_fd)));
    return (1);
}

int init_socket(my_ftp_t *myftp)
{
    myftp->server->socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (myftp->server->socket_fd == -1 && close(myftp->server->socket_fd))
        return (-1);
    return (1);
}

int init_binding(my_ftp_t *myftp)
{
    if ((bind(myftp->server->socket_fd, (struct sockaddr *)&myftp->server->\
        address, myftp->server->size_addr) == -1) && ((shutdown(myftp->server->\
        socket_fd, SHUT_RDWR) + 2) && (close(myftp->server->socket_fd))))
            return (-1);
    return (1);
}

int init_listening(my_ftp_t *myftp)
{
    myftp->server->queue = listen(myftp->server->socket_fd, 1000);
    if ((myftp->server->queue == -1) && close(myftp->server->socket_fd))
        return (-1);
    return (1);
}

int start_server(my_ftp_t *myftp)
{
    srand(time(NULL));
    for (int (*init_functions[3])(my_ftp_t *) = {&init_socket, &init_binding
    , &init_listening}, i = 0; i < 3; i++) {
        if (!i) {
            init_sever_properties(myftp, 1);
            init_functions[i](myftp);
            init_sever_properties(myftp, 2);
        } else {
            init_functions[i](myftp);
        }
    }
    return (0);
}
