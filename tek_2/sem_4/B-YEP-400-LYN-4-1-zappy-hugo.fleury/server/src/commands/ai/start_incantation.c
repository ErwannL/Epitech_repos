/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** start_incantation
*/

#include "../../../include/my_teams.h"

int local_start_incantation(my_ftp_t *myftp, user_t *user, int pos[2])
{
    int p_len = 0;

    for (user_t *player = myftp->map[pos[0]][pos[1]].players; player;\
    player = player->next)
        for (int i = 0; i < 7; i++)
            (player->infos->level == myftp->incantation_requirements[i]\
            .members[0]) ? append_player(myftp, player\
            , myftp->map[pos[0]][pos[1]], pos), p_len += 1\
            , player->infos->tick_remaining = 300\
            , dprintf(player->fd, "Elevation underway\n") : 0;
    dprintf(myftp->gui.fd, "pic %d %d %d%s", pos[0], pos[1]\
    , user->infos->level, retrieve_player_string(myftp, p_len));
    user->infos->tick_remaining = 300;
    myftp->incantation_infos.has_failed = NO;
    return (0);
}

int check_resources(my_ftp_t *myftp, resources_t *resource, int level)
{
    int r_value = 0;

    for (unsigned int i = 0; i < 7; i++) {
        if (i == resource->key) {
            r_value = (myftp->incantation_requirements[level].members[i]\
            >= resource->amount) ? 1 : 0;
        }
    }
    return (r_value ? 1 : 0);
}

int check_requirements(my_ftp_t *myftp, user_t *user, int pos[2])
{
    int len = 0;

    for (user_t *player = myftp->map[pos[0]][pos[1]].players; player;\
    player = player->next) {
        for (int i = 0; i < 7; i++)
            len = (player->infos->level == myftp->incantation_requirements[i]\
            .members[0]) ? len + 1 : len;
    }
    len = len ? len : 0;
    if (!len)
        return (-1);
    for (resources_t *resources = myftp->map[pos[0]][pos[1]].resources\
    ; resources; resources = resources->next) {
        if (!check_resources(myftp, resources, user->infos->level)) {
            return (-1);
        }
    }
    local_start_incantation(myftp, user, pos);
    return (0);
}

int handle_incantation_fail(my_ftp_t *myftp, int i, int j, int block)
{
    for (user_t *players = myftp->map[i][j].players; players\
    ; players = players->next) {
        dprintf(players->fd, "ko\n");
        !block ? players->infos->tick_remaining = 300 : 0;
        myftp->incantation_infos.has_failed = YES;
    }
    dprintf(myftp->gui.fd, "pie %d %d ko\n", myftp->incantation_infos.pos[0]\
    , myftp->incantation_infos.pos[1]);
    return (0);
}

int handle_start_incantation(my_ftp_t *myftp, user_t *user, char *input_str)
{
    int block = 0;
    int i = 0;
    int j = 0;
    int r_value = 0;

    input_str = input_str;
    for (; i < myftp->config->width; i++)
        for (; j < myftp->config->height; j++)
            block = 1;
    for (user_t *player = myftp->map[i][j].players; player && block;\
    player = player->next) {
        if (player->infos->x == user->infos->x && player->infos->y\
        == user->infos->y) {
            r_value = check_requirements(myftp, user, (int [2]) {i, j});
        }
    }
    if (r_value == -1)
        handle_incantation_fail(myftp, i, j, 0);
    return (0);
}
