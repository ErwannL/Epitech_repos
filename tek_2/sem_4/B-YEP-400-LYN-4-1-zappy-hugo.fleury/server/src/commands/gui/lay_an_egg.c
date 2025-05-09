/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** lay_an_egg
*/

#include "../../../include/my_teams.h"

int handle_lay_an_egg(my_ftp_t *myftp, user_t *user, char *input_str)
{
    myftp = myftp;
    input_str = input_str;
    dprintf(user->fd, "Player %d laid an egg\n", user->infos->number);
    return (0);
}