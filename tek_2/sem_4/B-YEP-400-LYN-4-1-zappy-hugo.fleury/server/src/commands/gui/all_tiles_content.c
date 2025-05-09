/*
** EPITECH PROJECT, 2023
** antoine [WSL: Ubuntu]
** File description:
** all_tiles_content
*/

#include "../../../include/my_teams.h"

int handle_all_tiles_content(my_ftp_t *myftp, user_t *user, char *input_str)
{
    if (!user->state && dprintf(user->fd, "sbp (please connect first)\n"))
        return (-1);

    input_str = input_str;
    for (int i = 0; i != myftp->config->width; i++) {
        for (int j = 0; j != myftp->config->height; j++) {
            dprintf(user->fd, "bct %d %d", i, j);
            for (unsigned int k = 0; k < 7; k++)
                dprintf(user->fd, " %d", get_resource(myftp->map[i][j].resources, k));
            dprintf(user->fd, "\n");
        }
    }
    return (0);
}
