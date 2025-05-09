/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** forward
*/

#include "../../../include/my_teams.h"

static void set_position_user(my_ftp_t *myftp,user_t *user, int orientation)
{
    if (orientation == 1) {
        user->infos->y++;
        if (user->infos->y > myftp->config->height)
            user->infos->y = 0;
    }
    if (orientation == 2) {
        user->infos->x++;
        if (user->infos->x > myftp->config->width)
            user->infos->x = 0;
    }
    if (orientation == 3) {
        user->infos->y--;
        if (user->infos->y < 0)
            user->infos->y = myftp->config->height;
    }
    if (orientation == 4) {
        user->infos->x--;
        if (user->infos->x < 0)
            user->infos->x = myftp->config->width;
    }
}

static int check_case_player_forward(my_ftp_t *myftp, user_t *user, int pos[2])
{
    int r_value = 0;

    for (user_t *player = myftp->map[pos[0]][pos[1]].players; player;\
    player = player->next) {
        if (player == user) {
            r_value = append_player_to_tile(myftp->map[pos[0]][pos[1]], user);
        }
    }
    return (r_value);
}

int handle_forward(my_ftp_t *myftp, user_t *user, char *input_str)
{
    int r_value = 0;
    input_str = input_str;
    remove_player_from_tile(get_tile(myftp, user), user);
    set_position_user(myftp, user, user->infos->orientation);
    printf("[Joueur %d]: Coordonnées {x: %d, y: %d}\n", user->fd, user->infos->x, user->infos->y);
    for (int i = 0; i < myftp->config->width; i++) {
        for (int j = 0; j < myftp->config->height; j++) {
            r_value = check_case_player_forward(myftp, user, (int [2]) {i, j});
        }
    }
    r_value != 0 ? dprintf(user->fd, "ko\n") : dprintf(user->fd, "ok\n");
    return (0);
}
