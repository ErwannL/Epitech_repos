/*
** EPITECH PROJECT, 2023
** tech2
** File description:
** my_ftp_client
*/

#ifndef MY_FTP_CLIENT_H_
    #define MY_FTP_CLIENT_H_

    #include "my_teams.h"

    typedef struct client_s {
        int sockfd;
        struct sockaddr_in address;
        fd_set active_fd;
        fd_set read_fd;
        user_t *user;
    } client_t;

#endif /* !MY_FTP_CLIENT_H_ */
