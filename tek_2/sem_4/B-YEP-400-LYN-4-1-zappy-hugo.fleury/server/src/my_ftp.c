/*
** EPITECH PROJECT, 2023
** tech2
** File description:
** my_ftp
*/

#include "../include/my_teams.h"

int my_ftp(my_ftp_t *myftp)
{
    int error_handling_value = 0;

    if ((error_handling_value = error_handling(myftp)) != 0)
        return (error_handling_value);
    myftp->time_management.tick = 1 / myftp->config->frequency;
    start_server(myftp);
    return (handle_connection(myftp));
}
