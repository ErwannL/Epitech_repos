/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-server.fillaudeau
** File description:
** my_ftp_user
*/

#ifndef MY_FTP_USER_H_
    #ifndef MISC_H_
        #define MY_FTP_USER_H_

        #include "zappy_resources.h"

        typedef struct user_s user_t;

        typedef enum connection_type_s connection_type_t;

        typedef struct player_infos_s {
            int x;
            int y;
            int orientation;
            int level;
            int number;
            int tick_remaining;
            char *team_name;
            resources_t *resources;
        } player_infos_t;

        struct user_s {
            int fd;
            int socket;
            int state;
            int port;
            int mode;
            char *username;
            char *str;
            char *ip;
            char *path;
            enum connection_type_s {
                NOTHING,
                GRAPHIC,
                AI,
            } connection_type;
            player_infos_t *infos;
            struct user_s *next;
            int (*set_fd)(struct user_s *, int);
            int (*set_socket)(struct user_s *, int);
            int (*set_state)(struct user_s *, int);
            int (*set_port)(struct user_s *, int);
            int (*set_mode)(struct user_s *, int);
            int (*set_username)(struct user_s *, char *);
            int (*set_input_str)(struct user_s *, char *);
            int (*set_ip)(struct user_s *, char *);
            int (*set_path)(struct user_s *, char *);
            int (*get_fd)(struct user_s *);
            int (*get_socket)(struct user_s *);
            int (*get_state)(struct user_s *);
            int (*get_port)(struct user_s *);
            int (*get_mode)(struct user_s *);
            char *(*get_username)(struct user_s *);
            char *(*get_input_str)(struct user_s *);
            char *(*get_ip)(struct user_s *);
            char *(*get_path)(struct user_s *);
        };

        /* local modular prototypes */

        // constructors
        int user_constructor(user_t *);
        int fd_constructor(user_t *);
        int socket_constructor(user_t *);
        int state_constructor(user_t *);
        int port_constructor(user_t *);
        int mode_constructor(user_t *);
        int username_constructor(user_t *);
        int input_str_constructor(user_t *);
        int ip_constructor(user_t *);
        int path_constructor(user_t *);

        // setters
        int set_fd(user_t *, int);
        int set_socket(user_t *, int);
        int set_state(user_t *, int);
        int set_port(user_t *, int);
        int set_mode(user_t *, int);
        int set_username(user_t *, char *);
        int set_input_str(user_t *, char *);
        int set_ip(user_t *, char *);
        int set_path(user_t *, char *);

        // getters
        int get_fd(user_t *);
        int get_socket(user_t *);
        int get_state(user_t *);
        int get_port(user_t *);
        int get_mode(user_t *);
        char *get_username(user_t *);
        char *get_input_str(user_t *);
        char *get_ip(user_t *);
        char *get_path(user_t *);

        /* !local modular prototypes */
    #endif /* !MISC_H_H */
#endif /* !MY_FTP_USER_H_ */
