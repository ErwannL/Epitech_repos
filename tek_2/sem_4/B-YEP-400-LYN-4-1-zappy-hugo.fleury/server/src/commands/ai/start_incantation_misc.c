/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** start_incantation_misc
*/

#include "../../../include/my_teams.h"

char *retrieve_player_string(my_ftp_t *myftp, int p_len)
{
    char *str = malloc(sizeof(char) * ((p_len * 2) + 1));
    char *n = NULL;
    int i = 0;

    for (user_t *players = myftp->incantation_infos.players; players\
    ; players = players->next) {
        n = int_to_string(players->infos->number);
        str[i++] = ' ';
        for (int j = 0; (size_t) j < strlen(n); j++)
            str[i++] = n[j];
    }
    str[i++] = '\n';
    str[i] = '\0';
    return (str);
}