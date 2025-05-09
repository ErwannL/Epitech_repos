/*
** EPITECH PROJECT, 2023
** tech2
** File description:
** my_ftp_server
*/

#ifndef MY_FTP_SERVER_H_
    #define MY_FTP_SERVER_H_

    #include "my_teams.h"

    typedef struct server_s {
        int port;
        int client_number;
        int socket_fd;
        int queue;
        char *path;
        struct sockaddr_in address;
        socklen_t size_addr;
        socklen_t size_socket;
    } server_t;

#endif /* !MY_FTP_SERVER_H_ */
