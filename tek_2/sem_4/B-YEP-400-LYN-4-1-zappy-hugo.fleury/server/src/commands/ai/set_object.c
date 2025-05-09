/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** set_object
*/

#include "../../../include/my_teams.h"

int has_player_object(user_t *user, unsigned int object)
{
    for (resources_t *resources = user->infos->resources; resources;\
    resources = resources->next) {
        if (resources->key == object && resources->amount > 0)
            return (1);
    }
    return (0);
}

int drop_ressource(my_ftp_t *myftp, user_t *user, int pos[2], char *obj)
{
    char *resources[7] = {"food", "linemate", "derauemere", "sibur"\
    , "mendiane", "phiras", "thystame"};
    int key = 0;

    for (int i = 0; i < 7; i++)
        if (my_contains(obj, resources[i]))
            key = i;
    if (!has_player_object(user, key))
        return (-1);
    for (resources_t *resources = myftp->map[pos[0]][pos[1]].resources;\
    resources; resources = resources->next) {
        if ((unsigned int) key == resources->key && resources->amount >= 1) {
            change_resource_amount(user->infos->resources, resources->key\
            , get_resource(user->infos->resources, key) - 1);
            resources->amount += 1;
            return (0);
        }
    }
    return (-1);
}

int check_case_player_set(my_ftp_t *myftp, user_t *user, int pos[2], char *object)
{
    int r_value = 0;

    for (user_t *player = myftp->map[pos[0]][pos[1]].players; player;\
    player = player->next) {
        if (player == user) {
            r_value = drop_ressource(myftp, player, pos, object);
        }
    }
    return (r_value);
}

int handle_set_object(my_ftp_t *myftp, user_t *user, char *input_str)
{
    char *value = input_str ? strtok(input_str, " ") : NULL;
    int r_value = 0;

    if (!user->state && dprintf(user->fd, "sbp\n"))
        return (-1);
    value = strtok(NULL, " ");
    if (!value && dprintf(user->fd, "sbp\n"))
        return (-1);
    for (int i = 0; i < myftp->config->width; i++) {
        for (int j = 0; j < myftp->config->height; j++) {
            r_value = check_case_player_set(myftp, user, (int [2]) {i, j}, value);
        }
    }
    r_value != 0 ? dprintf(user->fd, "ko\n") : dprintf(user->fd, "ok\n");
    user->infos->tick_remaining += 7;
    dprintf(myftp->gui.fd, "pgt %d %d\n", user->infos->number\
    , retrieve_object_by_name(value));
    return (0);
}
