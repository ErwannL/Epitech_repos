/*
** EPITECH PROJECT, 2023
** antoine [WSL: Ubuntu]
** File description:
** tiles_handling
*/

#include "../../include/my_teams.h"

int create_all_tiles(my_ftp_t *myftp)
{
    myftp->map = malloc((myftp->config->width) * sizeof(case_t *));
    for (int x = 0; x < myftp->config->width; x++) {
        myftp->map[x] = malloc((myftp->config->height) * sizeof(case_t));
        for (int y = 0; y < myftp->config->height; y++) {
            init_resources(&myftp->map[x][y].resources);
            myftp->map[x][y].players = malloc(sizeof(user_t *));
        }
    }
    return (0);
}

int append_player_to_tile(case_t tile, user_t *user)
{
    user_t *tmp = tile.players;

    user->next = NULL;
    if (tmp == NULL) {
        tile.players = user;
        return (0);
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = user;
    return (0);
}

int remove_player_from_tile(case_t tile, user_t *user)
{
    user_t *prev = NULL;
    user_t *current = NULL;

    if (tile.players == NULL)
        return (0);
    if (tile.players == user) {
        tile.players = user->next;
        free(user);
        return (0);
    }
    prev = tile.players;
    current = prev->next;
    for (; current != NULL; prev = current, current = current->next) {
        if (current == user) {
            prev->next = current->next;
            free(current);
            return (0);
        }
    }
    return (0);
}

case_t retrieve_local_player(my_ftp_t *myftp, user_t *user, int i, int j)
{
    for (user_t *player = myftp->map[i][j].players; player;\
    player = player->next) {
        if (player == user)
            return (myftp->map[i][j]);
    }
    return ((case_t){0});
}

case_t get_tile(my_ftp_t *myftp, user_t *user)
{
    for (int i = 0; i < myftp->config->width; i++) {
        for (int j = 0; j < myftp->config->height; j++) {
            return (retrieve_local_player(myftp, user, i, j));
        }
    }
    return ((case_t){0});
}
