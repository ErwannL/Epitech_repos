/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** player_look
*/

#include "../../../include/my_teams.h"

void print_case_look(case_t current_case, user_t *user)
{
    user_t *temp_player = current_case.players;
    resources_t *temp_res = current_case.resources;
    while (temp_player != NULL) {
        dprintf(user->fd, "player ");
        temp_player = temp_player->next;
    }
    while (temp_res != NULL) {
        for (int i = 0; i != temp_res->amount; i++) {
            switch (temp_res->key) {
                case FOOD:
                    dprintf(user->fd, "food ");
                    break;
                case LINEMATE:
                    dprintf(user->fd, "linemate ");
                    break;
                case DERAUMERE:
                    dprintf(user->fd, "deraumere ");
                    break;
                case SIBUR:
                    dprintf(user->fd, "sibur ");
                    break;
                case MENDIANE:
                    dprintf(user->fd, "mendiane ");
                    break;
                case PHIRAS:
                    dprintf(user->fd, "phiras ");
                    break;
                case THYSTAME:
                    dprintf(user->fd, "thystame ");
                    break;
            }
        }
        temp_res = temp_res->next;
    }
}


int handle_player_look(my_ftp_t *myftp, user_t *user, char *input_str)
{
    input_str = input_str;
    dprintf(user->fd, "[ ");
    for (int j = 0; j != user->infos->level; j++) {
        for (int i = -j; i <= j; i++) {
            print_case_look(myftp->map[user->infos->x + 1][user->infos->y + j], user);
            if (j != user->infos->level - 1 || i != j)
                dprintf(user->fd, ", ");
        }
    }
    dprintf(user->fd, "]\n");
    return 0;
}
