/*
** EPITECH PROJECT, 2023
** tech2
** File description:
** my_ftp
*/

#ifndef MY_FTP_H_
    #define MY_FTP_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <sys/select.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <signal.h>
    #include <time.h>

    #include "my_teams_user.h"
    #include "my_teams_server.h"
    #include "my_teams_client.h"
    #include "zappy_resources.h"
    #include "zappy_tiles.h"

    typedef struct server_config_s {
        int port;
        int width;
        int height;
        char **teamNames;
        int numTeams;
        int clientsPerTeam;
        double frequency;
    } server_config_t;

    typedef enum graphic_state_s graphic_state_t;

    typedef struct time_unit_s {
        char *cmd;
        int time_unit;
        size_t last_time;
    } time_unit_t;

    typedef struct incantation_s {
        int members[8];
    } incantation_t;

    typedef struct buffer_s {
        int id;
        char *cmd;
    } buffer_t;

    typedef struct my_ftp_s {
        server_t *server;
        client_t *client;
        case_t **map;
        server_config_t *config;
        struct gui_conf_t {
            enum graphic_state_s {
                NONE,
                CONNECTED,
            } graphic_state;
            int fd;
        } gui;
        struct time_management_s {
            int start;
            int last;
            int elapsed_time;
            int food_elapsed_time;
            int tick;
        } time_management;
        struct incantation_infos_s {
            case_t tile;
            user_t *players;
            int pos[2];
            time_t start;
            enum fail_s {
                YES,
                NO,
            } has_failed;
        } incantation_infos;
        time_unit_t *time_unit;
        incantation_t *incantation_requirements;
        buffer_t *buffer;
        int argc;
        char **argv;
        int (*set_argc)(struct my_ftp_s *, int);
        int (*set_argv)(struct my_ftp_s *, char **);
        int (*get_argc)(struct my_ftp_s *);
        char **(*get_argv)(struct my_ftp_s *);
    } my_ftp_t;

    int create_all_tiles(my_ftp_t *);
    /* @param my_ftp_t *myftp => main var
    ** @param user_t *user => user to get tile from
    ** @retval tile matching with given user
    */
    case_t get_tile(my_ftp_t *, user_t *);

    int handle_command(my_ftp_t *, user_t *);
    int handle_connection(my_ftp_t *);

    int put_users(my_ftp_t *, int[4], char *[3]);
    int get_users_size(my_ftp_t *);

    /* @param my_ftp_t *myftp => main var
    ** @param char *cmd => command to get elapsed time from
    ** @retval time frequency (n/f ratio)
    ** @retval -1 in case of error
    */
    int get_elapsed_time_by_cmd(my_ftp_t *, char *cmd);

    /* @param my_ftp_t *myftp => main var
    ** @param char *cmd => command which elapsed time should be set
    ** @retval 0 by default
    ** @retval -1 in case of error
    */
    int set_elapsed_time_by_cmd(my_ftp_t *, char *cmd);

    /* commands/gui */

    // misc.c
    int handle_expulsion(my_ftp_t *, user_t *, char *);
    int handle_help(my_ftp_t *, user_t *, char *);

    // new_player_connection.c
    int handle_new_player_connection(my_ftp_t *, user_t *, char *);
    int handle_new_ai_connection(my_ftp_t *, user_t *, char *);

    // player_position.c
    int handle_player_position(my_ftp_t *, user_t *, char *);

    // player_level.c
    int handle_player_level(my_ftp_t *, user_t *, char *);

    // player_inventory.c
    int handle_player_inventory(my_ftp_t *, user_t *, char *);

    // map_size.c
    int handle_map_size(my_ftp_t *, user_t *, char *);

    // team_name.c
    int handle_team_name(my_ftp_t *, user_t *, char *);

    // resource_collecting.c
    int handle_resource_collecting(my_ftp_t *, user_t *, char *);

    // resource_dropping.c
    int handle_resource_dropping(my_ftp_t *, user_t *, char *);

    // all_tiles_content.c
    int handle_all_tiles_content(my_ftp_t *, user_t *, char *);

    // tile_content.c
    int handle_tile_content(my_ftp_t *, user_t *, char *);

    // broadcast.c
    int handle_broadcast(my_ftp_t *, user_t *, char *);

    // end_game.c
    int handle_end_game(my_ftp_t *myftp, user_t *user, char *input_str);

    // lay_an_egg.c
    int handle_lay_an_egg(my_ftp_t *myftp, user_t *user, char *input_str);
    // time_unit_request.c
    int handle_tur(my_ftp_t *, user_t *, char *);

    // time_unit_modification.c
    int handle_tum(my_ftp_t *, user_t *, char *);

    /* !commands/gui */



    /* commands/ai */

    // connect_nbr.c
    int handle_connect_nbr(my_ftp_t *, user_t *, char *);

    // forward.c
    int handle_forward(my_ftp_t *myftp, user_t *user, char *input_str);

    // turn_left.c
    int handle_rotation_left(my_ftp_t *myftp, user_t *user, char *input_str);

    // turn_right.c
    int handle_rotation_right(my_ftp_t *myftp, user_t *user, char *input_str);

    // player_inventory.c
    int handle_player_inventory_ai(my_ftp_t *, user_t *, char *);

    // player_look.c
    int handle_player_look(my_ftp_t *, user_t *, char *);

    // take_object.c
    int handle_take_object(my_ftp_t *, user_t *, char *);
    int retrieve_object_by_name(char *);

    // set_object.c
    int handle_set_object(my_ftp_t *, user_t *, char *);

    // start_incantation.c
    int handle_start_incantation(my_ftp_t *, user_t *, char *);
    int check_resources(my_ftp_t *, resources_t *, int);
    int handle_incantation_fail(my_ftp_t *, int, int, int);
    char *retrieve_player_string(my_ftp_t *, int);

    /* !commands/ai */
    // death.c
    int handle_death(my_ftp_t *myftp, user_t *user, char *input_str);

    /* !commands/gui */

    /* local modular prototypes */

    // constructor
    int my_ftp_constructor(my_ftp_t *);

    // setters
    int set_argc(my_ftp_t *, int);
    int set_argv(my_ftp_t *, char **);

    // getters
    int get_argc(my_ftp_t *);
    char **get_argv(my_ftp_t *);

    /* !local modular prototypes */



    /* lib */

    // my_strcpy.c
    /* @param char *str => string to be edit
    ** @param int is_free => 1: str will be free'd ; 0: to keep str allocated
    ** @retval new string allocated (copied from str)
    */
    char *my_strcpy(char *, int);

    // my_equals.c
    /* @param char *str => string to be compared (original string)
    ** @param char *comp => string to compare (comparison string)
    ** @retval -1 if different, 0 if equals
    */
    int equals(char *, char *);

    /* @param char *str => string to be compared (original string)
    ** @param char *comp => string to compare (comparison string)
    ** @retval -1 if different, 0 if equals
    ** @retval NOTE: uppercase and lowercase letters will be compared as equal
    */
    int equals_ignore_case(char *, char *);

    // my_contains.c
    /* @param char *str => string to be compared (original string)
    ** @param char *comp => string to compare (comparison string)
    ** @retval matching index if true OR 0 if didn't match
    */
    int my_contains(char const *, char *);
    int my_contains_b(char const *, char *);

    // my_substring.c
    /* @param char *str => string to be edit
    ** @param int start => start index
    ** @param int end => end index
    ** @param int is_free => 1: str will be free'd ; 0: to keep str allocated
    ** @retval new string allocated (substracted from str)
    */
    char *my_substring(char *, int, int, int);

    // my_substring.c
    /* @param char *str => string to be edit
    */
    char **str_to_array(char *);

    // my_evil_str.c
    char *my_revstr(char *);

    // int_to_string.c
    char *int_to_string(int);

    /* !lib */



    /* my_ftp.c */

    int my_ftp(my_ftp_t *);

    /* !my_ftp.c */


    /* error_handling.c */

    int error_handling(my_ftp_t *);

    /* !error_handling.c */


    /* server_init.c */

    int start_server(my_ftp_t *);

    /* !server_init.c */



    /* clients_handling.c */

    int handle_client(my_ftp_t *, int);
    user_t *get_user(my_ftp_t *, int);

    /* !clients_handling.c */



    /* time_loop.c */

    int handle_time_loop(my_ftp_t *);
    int handle_food_loop(my_ftp_t *);
    int handle_resources_generation(my_ftp_t *);
    int append_player(my_ftp_t *, user_t *, case_t, int [2]);
    int handle_time_incantation_loop(my_ftp_t *);

    /* !time_loop.c */



    /* parsing */

    void free_server_config(server_config_t *config);

    server_config_t *parse_port(int i, my_ftp_t *, server_config_t *config);
    server_config_t *parse_width(int i, my_ftp_t *, server_config_t *config);
    server_config_t *parse_height(int i, my_ftp_t *, server_config_t *config);
    server_config_t *parse_team(int i, my_ftp_t *, server_config_t *config);
    server_config_t *parse_clients(int i, my_ftp_t *, server_config_t *config);
    server_config_t *parse_frequency(int i, my_ftp_t *, server_config_t *config);
    server_config_t *parsing_argument_four(int i, my_ftp_t *,\
    server_config_t *config);
    server_config_t *parsing_argument_three(int i, my_ftp_t *,\
    server_config_t *config);
    server_config_t *parsing_argument_two(int i, my_ftp_t *,\
    server_config_t *config);

    /* !parsing */

    int get_client_nbr(my_ftp_t *myftp);


#endif /* !MY_FTP_H_ */
