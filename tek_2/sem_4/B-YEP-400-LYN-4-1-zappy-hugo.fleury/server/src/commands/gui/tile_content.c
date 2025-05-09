/*
** EPITECH PROJECT, 2023
** antoine [WSL: Ubuntu]
** File description:
** tile_content
*/

#include "../../../include/my_teams.h"

int handle_tile_error(user_t *user, char *value, pos_t *pos)
{
    pos_t local_pos = *pos;

    if (!value && dprintf(user->fd, "sbp (/bct X Y)\n"))
        return (-1);
    if (!(local_pos.x = atoi(value)) &&\
    dprintf(user->fd, "sbp (/bct X Y)\n"))
        return (-1);
    value = strtok(NULL, " ");
    if (!value && dprintf(user->fd, "sbp (/bct X Y)\n"))
        return (-1);
    if (!(local_pos.y = atoi(value)) &&\
    dprintf(user->fd, "sbp (/bct X Y)\n"))
        return (-1);
    *pos = local_pos;
    return (0);
}

int handle_tile_content(my_ftp_t *myftp, user_t *user, char *input_str)
{
    case_t m;
    pos_t pos = {0, 0};
    char *value = NULL;

    if (!user->state && dprintf(user->fd, "sbp (please connect first)\n"))
        return (-1);
    value = input_str ? strtok(input_str, " ") : NULL;
    value = strtok(NULL, " ");
    if (handle_tile_error(user, value, &pos) < 0)
        return (-1);
    m = myftp->map[pos.x][pos.y];
    if (dprintf(user->fd, "sbp (wrong pos, /bct X Y)\n"))
        return (-1);
    dprintf(user->fd, "bct %d %d", pos.x, pos.y);
    for (unsigned int i = 0; i < 7; i++)
        dprintf(user->fd, " %d", get_resource(m.resources, i));
    dprintf(user->fd, "\n");
    return (0);
}
