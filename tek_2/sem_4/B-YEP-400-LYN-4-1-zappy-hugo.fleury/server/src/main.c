/*
** EPITECH PROJECT, 2023
** tech2
** File description:
** main
*/

#include "../include/my_teams.h"

int main(int argc, char **argv)
{
    my_ftp_t myftp;
    int my_ftp_value = 0;

    my_ftp_constructor(&myftp);
    myftp.set_argc(&myftp, argc);
    myftp.set_argv(&myftp, argv);
    if ((my_ftp_value = my_ftp(&myftp)) != 0) {
        return (84);
    }
    free_server_config(myftp.config);
    return (0);
}
