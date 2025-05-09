/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** resources_generation
*/

#include "../../include/my_teams.h"

int loop_resources_generation(my_ftp_t *myftp, double *res\
, int pos[2], int i)
{
    for (int j = 0; j < (myftp->config->width * myftp->config->height\
    * res[i]); j++) {
        srand(clock());
        pos[0] = rand() % myftp->config->width;
        srand(clock());
        pos[1] = rand() % myftp->config->height;
        change_resource_amount(myftp->map[pos[0]][pos[1]].resources\
        , (unsigned int) i, get_resource(myftp->map[pos[0]][pos[1]].resources\
        , (unsigned int) i) + 1);
    }
    return (0);
}

int handle_resources_generation(my_ftp_t *myftp)
{
    int current_time = time(NULL);
    double res[7] = {0.5, 0.3, 0.15, 0.1, 0.1, 0.08, 0.05};
    int x = 0;
    int y = 0;

    if (current_time - myftp->time_management.start >=\
    myftp->time_management.elapsed_time) {
        for (int i = 0;  i < 7; i++)
            loop_resources_generation(myftp, res, (int [2]) {x, y}, i);
        myftp->time_management.elapsed_time += (20\
        * myftp->time_management.tick);
    }
    return (0);
}
