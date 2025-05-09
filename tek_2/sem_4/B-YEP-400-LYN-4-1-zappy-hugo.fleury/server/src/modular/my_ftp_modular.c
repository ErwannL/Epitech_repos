/*
** EPITECH PROJECT, 2023
** tech2
** File description:
** my_ftp_modular
*/

#include "../../include/my_teams.h"

int my_ftp_constructor(my_ftp_t *myftp)
{
    time_unit_t time_unit[11] = {{"Forward", 7, 0}, {"Right", 7, 0}
    , {"Left", 7, 0}, {"Look", 7, 0}, {"Inventory", 1, 0}\
    , {"Broadcast", 7, 0}, {"Fork", 42, 0}, {"Eject", 7, 0}, {"Take", 7, 0}\
    , {"Set", 7, 0}, {"Incantation", 300, 0}};
    incantation_t incantation[7] = {{ {1, 1, 0, 0, 0, 0, 0, 2} }\
    , { {2, 1, 1, 1, 0, 0, 0, 3} }, { {2, 2, 0, 1, 0, 2, 0, 4} }\
    , { {4, 1, 1, 2, 0, 1, 0, 5} }, { {4, 1, 2, 1, 3, 0, 0, 6} }\
    , { {6, 1, 2, 3, 0, 1, 0, 7} }, { {6, 2, 2, 2, 2, 2, 1, 8} }};
    buffer_t buffer[10]= {{0, NULL}, {1, NULL}, {2, NULL}, {3, NULL}\
    , {4, NULL}, {5, NULL}, {6, NULL}, {7, NULL}, {8, NULL}, {9, NULL}};

    myftp->set_argc = &set_argc;
    myftp->set_argv = &set_argv;
    myftp->get_argc = &get_argc;
    myftp->get_argv = &get_argv;
    myftp->server = malloc(sizeof(server_t));
    myftp->client = malloc(sizeof(client_t));
    myftp->gui.graphic_state = NONE;
    myftp->time_unit = time_unit;
    myftp->incantation_requirements = incantation;
    myftp->time_management.start = time(NULL);
    myftp->time_management.elapsed_time = 0;
    myftp->time_management.food_elapsed_time = 0;
    myftp->buffer = buffer;
    myftp->incantation_infos.players = NULL;
    myftp->incantation_infos.pos[0] = 0;
    myftp->incantation_infos.pos[1] = 0;
    myftp->incantation_infos.start = time(NULL);
    myftp->incantation_infos.has_failed = YES;
    return (0);
}

int set_argc(my_ftp_t *myftp, int argc)
{
    if (!(myftp->argc = argc)) {
        myftp->argc = 0;
        return (-1);
    }
    return (0);
}

int set_argv(my_ftp_t *myftp, char **argv)
{
    if (!(myftp->argv = argv)) {
        myftp->argv = NULL;
        return (-1);
    }
    return (0);
}

int get_argc(my_ftp_t *myftp)
{
    return (myftp->argc);
}

char **get_argv(my_ftp_t *myftp)
{
    return (myftp->argv);
}
