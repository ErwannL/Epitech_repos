/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** incantation_loop
*/

#include "../../include/my_teams.h"

int append_player(my_ftp_t *myftp, user_t *user, case_t tile\
, int pos[2])
{
    user_t *tmp = myftp->incantation_infos.players;

    user->next = NULL;
    if (tmp == NULL) {
        myftp->incantation_infos.players = user;
        return (0);
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = user;
    myftp->incantation_infos.tile = tile;
    myftp->incantation_infos.pos[0] = pos[0];
    myftp->incantation_infos.pos[1] = pos[1];
    return (0);
}

int local_player_level(my_ftp_t *myftp, int pos[2])
{
    for (user_t *player = myftp->map[pos[0]][pos[1]].players; player;\
    player = player->next)
        for (int i = 0; i < 7; i++)
            (player->infos->level == myftp->incantation_requirements[i]\
            .members[0]) ? player->infos->tick_remaining = 300 : 0;
    return (0);
}

int upgrade_after_incantation(my_ftp_t *myftp)
{
    for (user_t *players = myftp->incantation_infos.players; players\
    ; players = players->next) {
        players->infos->level += 1;
        players->infos->tick_remaining = 0;
        dprintf(players->fd, "Current level: %d\n", players->infos->level);
    }
    dprintf(myftp->gui.fd, "pie %d %d ok\n", myftp->incantation_infos.pos[0]\
    , myftp->incantation_infos.pos[1]);
    return (0);
}

int handle_local_incantation(my_ftp_t *myftp, int pos[2])
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
        if (!check_resources(myftp, resources\
        , myftp->incantation_infos.players->infos->level)) {
            return (-1);
        }
    }
    upgrade_after_incantation(myftp);
    return (0);
}

int handle_time_incantation_loop(my_ftp_t *myftp)
{
    int current_time = time(NULL);

    if (current_time - myftp->incantation_infos.start >=\
    300 / myftp->time_management.tick) {
        if ((myftp->incantation_infos.has_failed == YES) \
        | (handle_local_incantation(myftp, (int [2])\
        {myftp->incantation_infos.pos[0], myftp->incantation_infos.pos[1]})\
        != 0)) {
            handle_incantation_fail(myftp, myftp->incantation_infos.pos[0]\
            , myftp->incantation_infos.pos[1], 1);
        }
    }
    return (0);
}
