/*
** EPITECH PROJECT, 2023
** tech2
** File description:
** error_handling
*/

#include "../include/my_teams.h"

void print_data(server_config_t* config)
{
    printf("Port: %d\n", config->port);
    printf("Width: %d\n", config->width);
    printf("Height: %d\n", config->height);
    printf("Number of teams: %d\n", config->numTeams);
    printf("Team names:\n");
    for (int i = 0; i < config->numTeams; i++)
        printf("  - %s\n", config->teamNames[i]);
    printf("Clients per team: %d\n", config->clientsPerTeam);
    printf("Frequency: %f\n", config->frequency);
}

void print_usage(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ");
    printf("... -c clientsNb -f freq\n");
    printf("\tport\t\tis the port number\n");
    printf("\twidth\t\tis the width of the world\n");
    printf("\theight\t\tis the height of the world\n");
    printf("\tnameX\t\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n");
    printf("\tfreq\t\tis the reciprocal of time unit for execution of");
    printf("actions\n");
}

server_config_t* parse_arguments(my_ftp_t *myftp)
{
    server_config_t* config = (server_config_t*) malloc(sizeof(server_config_t));

    config->teamNames = NULL;
    config->numTeams = 0;
    for (int i = 1; i < myftp->argc; i++) {
        if (parsing_argument_two(i, myftp, config) == NULL) {
            print_usage();
            return (NULL);
        }
    }
    if (config->port == 0 || config->width == 0 || config->height == 0 ||
        config->numTeams == 0 || config->clientsPerTeam == 0 ||
        config->frequency == 0.000000) {
        fprintf(stderr, "Error: Missing or invalid arguments\n");
        free_server_config(config);
        print_usage();
        return (NULL);
    }
    return (config);
}

int error_handling(my_ftp_t *myftp)
{
    for (int i = 1; i < myftp->argc; i++) {
        if (strcmp(myftp->argv[i], "-help") == 0) {
            print_usage();
            return 0;
        }
    }
    if (myftp->argc < 13) {
        fprintf(stderr, "Error: Missing arguments\n");
        print_usage();
        return 84;
    }
    myftp->config = parse_arguments(myftp);
    if (myftp->config == NULL)
        return 84;
    create_all_tiles(myftp);
    print_data(myftp->config);
    return (0);
}
