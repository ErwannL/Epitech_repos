/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** end_game
*/

#include "../../../include/my_teams.h"

void dprintf_array(user_t *user, char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        dprintf(user->fd, "%s\n", array[i]);
    }
}

int len_array(char **arr)
{
    int i;
    for (i = 0; arr[i] != NULL; i++);
    return i;
}

char **remove_team_in_tab(char **array, char *team_remove)
{
    char **new_array = malloc(sizeof(char *) * (len_array(array) + 1));

    for (int i = 0, y = 0; array[i] != NULL; i++) {
        if (strcmp(array[i], team_remove) != 0) {
            new_array[y] = malloc(sizeof(char) * (strlen(array[i]) + 1));
            strcpy(new_array[y], array[i]);
            y++;
        }
    }
    new_array[len_array(array) - 1] = NULL;
    return new_array;
}

int team_exist_or_not(my_ftp_t *myftp, char *team)
{
    for (int i = 0; myftp->config->teamNames[i] != NULL; i++) {
        if (strcmp(myftp->config->teamNames[i], team) == 0) {
            myftp->config->teamNames = remove_team_in_tab(myftp->config->teamNames, team);
            return (0);
        }
    }
    return (1);
}

int handle_end_game(my_ftp_t *myftp, user_t *user, char *input_str)
{
    input_str = input_str;
    char *value = (input_str != NULL) ? strtok(input_str, " ") : NULL;
    value = strtok(NULL, " ");
    char *team = value;

    if (team_exist_or_not(myftp, team) != 0)
        dprintf(user->fd, "The %s team doesn't exist\n", team);
    else {
        dprintf(user->fd, "%s end of the game\n", team);
    }
    return (0);
}
