/*
** EPITECH PROJECT, 2023
** tech2
** File description:
** command_handling
*/

#include "../include/my_teams.h"

int handle_wrong_command(user_t *user)
{
    dprintf(user->fd, "500\n");
    return (0);
}

int handle_connection_type(my_ftp_t *myftp, user_t *user, char *input_str)
{
    if (user->connection_type == NOTHING
    && !(myftp->gui.graphic_state == CONNECTED)
    && my_contains(input_str, "GRAPHIC")) {
        user->connection_type = GRAPHIC;
        myftp->gui.graphic_state = CONNECTED;
        myftp->gui.fd = user->fd;
        handle_new_player_connection(myftp, user, input_str);
        return (0);
    }
    if (user->connection_type == NOTHING) {
        user->connection_type = AI;
        handle_new_ai_connection(myftp, user, input_str);
        return (0);
    }
    return (-1);
}

int handle_ai_command(my_ftp_t *myftp, user_t *user, char *input_str)
{
    char *cmd_list[8] = {"Connect_nbr", "Inventory", "Look", "Take", "Set"\
    , "forward", "left", "right"};
    int (*cmd_func[8])(my_ftp_t *, user_t *, char *)\
    = {&handle_connect_nbr, &handle_player_inventory_ai, &handle_player_look\
    , &handle_take_object, &handle_set_object, &handle_forward\
    , &handle_rotation_left, &handle_rotation_right};

    for (int i = 0; i < 8; i++) {
        if (my_contains(input_str, cmd_list[i])) {
            cmd_func[i](myftp, user, input_str);
            return (0);
        }
    }
    return (0);
}

int handle_gui_command(my_ftp_t *myftp, user_t *user, char *input_str)
{
    char *cmd_list[13] = {"pex", "ppo", "msz",\
    "plv", "pin", "tna", "bct", "mct", "pbc",\
    "sgt", "sst", "seg", "pfk"};
    int (*cmd_func[13])(my_ftp_t *, user_t *, char *)\
    = {&handle_expulsion, &handle_player_position,\
    &handle_map_size, &handle_player_level, &handle_player_inventory,\
    &handle_team_name, &handle_tile_content, &handle_all_tiles_content\
    , &handle_broadcast, &handle_tur, &handle_tum, &handle_end_game,\
    &handle_lay_an_egg};

    for (int i = 0; i < 13; i++) {
        if (my_contains(input_str, cmd_list[i])) {
            cmd_func[i](myftp, user, input_str);
            return (0);
        }
    }
    return (0);
}

int handle_command(my_ftp_t *myftp, user_t *user)
{
    char input_str[256];
    int read_bytes = 0;

    read_bytes = read(user->fd, input_str, 256);
    input_str[read_bytes - 1] = '\0';
    if ((!read_bytes || read_bytes == 1))
        return (0);
    handle_connection_type(myftp, user, input_str);
    if (user->connection_type == GRAPHIC) {
        user->connection_type = GRAPHIC;
        handle_gui_command(myftp, user, input_str);
        return (0);
    }
    user->connection_type = AI;
    handle_ai_command(myftp, user, input_str);
    return (0);
}
