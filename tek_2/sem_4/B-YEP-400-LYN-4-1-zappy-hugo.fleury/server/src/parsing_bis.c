/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** parsing_bis
*/

#include "../include/my_teams.h"

void free_server_config(server_config_t *config)
{
    for (int i = 0; i < config->numTeams; i++)
        free(config->teamNames[i]);
    free(config->teamNames);
    free(config);
}

server_config_t *parse_port(int i, my_ftp_t *myftp, server_config_t *config)
{
    char* endptr;
    long value;

    if (i + 1 < myftp->argc) {
        value = strtol(myftp->argv[i + 1], &endptr, 10);
        if (*endptr != '\0') {
            fprintf(stderr, "Error: Invalid port number\n");
            free_server_config(config);
            return NULL;
        }
        config->port = (int)value;
        i++;
    } else {
        fprintf(stderr, "Error: Missing port number\n");
        free_server_config(config);
        return NULL;
    }
    return (config);
}

server_config_t *parse_width(int i, my_ftp_t *myftp, server_config_t *config)
{
    char* endptr;
    long value;

    if (i + 1 < myftp->argc) {
        value = strtol(myftp->argv[i + 1], &endptr, 10);
        if (*endptr != '\0') {
            fprintf(stderr, "Error: Invalid width\n");
            free_server_config(config);
            return NULL;
        }
        config->width = (int)value;
        i++;
    } else {
        fprintf(stderr, "Error: Missing width\n");
        free_server_config(config);
        return NULL;
    }
    return (config);
}

server_config_t *parse_height(int i, my_ftp_t *myftp, server_config_t *config)
{
    char* endptr;
    long value;

    if (i + 1 < myftp->argc) {
        value = strtol(myftp->argv[i + 1], &endptr, 10);
        if (*endptr != '\0') {
            fprintf(stderr, "Error: Invalid height\n");
            free_server_config(config);
            return NULL;
        }
        config->height = (int)value;
        i++;
    } else {
        fprintf(stderr, "Error: Missing height\n");
        free_server_config(config);
        return NULL;
    }
    return config;
}

server_config_t *parse_team(int i, my_ftp_t *myftp, server_config_t *config)
{
    int j;

    if (i + 1 < myftp->argc) {
        config->numTeams = 0;
        j = i + 1;
        while (j < myftp->argc && myftp->argv[j][0] != '-') {
            config->numTeams++;
            j++;
        }
        config->teamNames = (char**)malloc(sizeof(char*) * config->numTeams);
        for (int k = 0; k < config->numTeams; k++)
            config->teamNames[k] = strdup(myftp->argv[i + k + 1]);
        i = j - 1;
    } else {
        fprintf(stderr, "Error: Missing team names\n");
        free_server_config(config);
        return NULL;
    }
    return config;
}
