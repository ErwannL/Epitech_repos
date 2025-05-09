/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** time_loop
*/

#include "../../include/my_teams.h"

int handle_time_loop(my_ftp_t *myftp)
{
    handle_resources_generation(myftp);
    handle_food_loop(myftp);
    handle_time_incantation_loop(myftp);
    return (0);
}
