/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** parsing
*/

#include "../include/my_teams.h"

server_config_t *parse_clients(int i, my_ftp_t *myftp, server_config_t *config)
{
    char* endptr;
    long value;

    if (i + 1 < myftp->argc) {
        value = strtol(myftp->argv[i + 1], &endptr, 10);
        if (*endptr != '\0') {
            fprintf(stderr, "Error: Invalid number of clients per team\n");
            free_server_config(config);
            return NULL;
        }
        config->clientsPerTeam = (int)value;
        i++;
    } else {
        fprintf(stderr, "Error: Missing number of clients per team\n");
        free_server_config(config);
        return NULL;
    }
    return config;
}

server_config_t *parse_frequency(int i, my_ftp_t *myftp, server_config_t *config)
{
    char* endptr;
    double value;

    if (i + 1 < myftp->argc) {
        value = strtod(myftp->argv[i + 1], &endptr);
        if (*endptr != '\0') {
            fprintf(stderr, "Error: Invalid frequency\n");
            free_server_config(config);
            return NULL;
        }
        config->frequency = value;
        i++;
    } else {
        fprintf(stderr, "Error: Missing frequency\n");
        free_server_config(config);
        return NULL;
    }
    return config;
}

server_config_t *parsing_argument_four(int i, my_ftp_t *myftp,
                                                        server_config_t *config)
{
    if (strcmp(myftp->argv[i], "-c") == 0 && parse_clients(i, myftp, config) == NULL)
        return NULL;
    else if (strcmp(myftp->argv[i], "-f") == 0 &&
                                    parse_frequency(i, myftp, config) == NULL)
        return NULL;
    return config;
}

server_config_t *parsing_argument_three(int i, my_ftp_t *myftp,
                                                        server_config_t *config)
{
    if (strcmp(myftp->argv[i], "-y") == 0 && parse_height(i, myftp, config) == NULL)
        return NULL;
    else if (strcmp(myftp->argv[i], "-n") == 0 && parse_team(i, myftp, config) == NULL)
        return NULL;
    else
        return parsing_argument_four(i, myftp, config);
}

server_config_t *parsing_argument_two(int i, my_ftp_t *myftp,
                                                        server_config_t *config)
{
    if (strcmp(myftp->argv[i], "-p") == 0 && parse_port(i, myftp, config) == NULL)
        return NULL;
    else if (strcmp(myftp->argv[i], "-x") == 0 && parse_width(i, myftp, config) == NULL)
        return NULL;
    else
        return parsing_argument_three(i, myftp, config);
}
