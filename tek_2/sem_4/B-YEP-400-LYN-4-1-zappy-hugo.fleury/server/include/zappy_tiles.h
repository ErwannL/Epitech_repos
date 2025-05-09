/*
** EPITECH PROJECT, 2023
** antoine [WSL: Ubuntu]
** File description:
** zappy_tiles
*/

#ifndef ZAPPY_TILES_H_
    #define ZAPPY_TILES_H_

    #include "zappy_resources.h"

    struct pos_s {
        int x;
        int y;
    };

    typedef struct pos_s pos_t;

    // typedef struct tiles_s {
    //     int number;
    //     struct pos_s {
    //         int x;
    //         int y;
    //     } pos;
    //     resources_t *resources;
    //     struct tiles_s *next;
    // } tiles_t;

    typedef struct case_s {
        resources_t *resources;
        user_t *players;
    } case_t;

    /* @param tile_t **tiles => tiles_t chained_list adress (&myftp->tiles)
    ** @param pos_t pos => (pos_t) {x, y}
    */
    // int add_tile(tiles_t **, pos_t);


    /* @param tile_t *tiles => tiles_t chained_list (myftp->tiles)
    */
    // int get_tile_length(tiles_t *);

    int append_player_to_tile(case_t, user_t *);
    int remove_player_from_tile(case_t, user_t *);

#endif /* !ZAPPY_TILES_H_ */
