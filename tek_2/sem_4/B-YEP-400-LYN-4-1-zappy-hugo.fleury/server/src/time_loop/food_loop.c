/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** food_loop
*/

#include "../../include/my_teams.h"

int handle_local_death(my_ftp_t *myftp, user_t *user)
{
    if (get_resource(user->infos->resources , FOOD) <= 0) {
        dprintf(myftp->gui.fd, "pdi %d\n", user->infos->number);
        dprintf(user->fd, "dead\n");
    }
    return (0);
}

int handle_food_loop(my_ftp_t *myftp)
{
    int current_time = time(NULL);

    if (current_time - myftp->time_management.start >=\
    myftp->time_management.food_elapsed_time) {
        for (user_t *users = myftp->client->user; users; users = users->next) {
            change_resource_amount(users->infos->resources , FOOD\
            , get_resource(users->infos->resources , FOOD) - 1);
            handle_local_death(myftp, users);
        }
        myftp->time_management.food_elapsed_time += (126\
        * myftp->time_management.tick);
    }
    return (0);
}
