/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** time_unit_handling
*/

#include "../../include/my_teams.h"

int get_elapsed_time_by_cmd(my_ftp_t *myftp, char *cmd)
{
    size_t curr = 0;

    for (int i = 0; i < 11; i++) {
        if (equals(cmd, myftp->time_unit[i].cmd) != -1) {
            curr = time(NULL);
            return (curr - myftp->time_unit[i].last_time);
        }
    }
    return (-1);
}

int set_elapsed_time_by_cmd(my_ftp_t *myftp, char *cmd)
{
    for (int i = 0; i < 11; i++) {
        if (equals(cmd, myftp->time_unit[i].cmd) != -1) {
            myftp->time_unit[i].last_time = time(NULL);
            return (0);
        }
    }
    return (-1);
}
