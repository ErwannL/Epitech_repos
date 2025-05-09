/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** turn_right
*/

#include "../../../include/my_teams.h"

int rotation_left(int orientation)
{
    return (orientation - 1 + 3) % 4 + 1;
}

int handle_rotation_left(my_ftp_t *myftp, user_t *user, char *input_str)
{
    int new_orientation = rotation_left(user->infos->orientation);

    myftp = myftp;
    input_str = input_str;
    user->infos->orientation = new_orientation;
    printf("[Joueur %d]: Orientation {%d}\n", user->infos->number\
    , user->infos->orientation);
    dprintf(user->fd, "ok\n");
    return (0);
}
