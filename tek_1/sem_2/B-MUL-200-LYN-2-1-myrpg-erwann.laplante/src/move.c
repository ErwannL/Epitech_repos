/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** move
*/

#include "my_rpg.h"

obstacle_t set_obstacles(int *nbr)
{
    obstacle_t os;

    os.piece = nbr[0];
    os.x_player_min = nbr[1];
    os.x_player_max = nbr[2];
    os.y_player_min = nbr[3];
    os.y_player_max = nbr[4];
    os.x_map_min = nbr[5];
    os.x_map_max = nbr[6];
    os.y_map_min = nbr[7];
    os.y_map_max = nbr[8];
    return os;
}

win_t *create_obstacles(win_t *win)
{
    win->all_obstacle = malloc(sizeof(obstacle_t) * 97);
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){0, 225
    , 405, 230, 450, 1167, 1169, 57, 62});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){0, 520
    , 700, 360, 520, 1169, 1169, 62, 62});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){0, 0
    , 105, 360, 520, 1167, 1167, 62, 62});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){0, 0
    , 305, 0, 150, 1167, 1167, 57, 57});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){0, 300
    , 640, 0, 80, 1167, 1169, 57, 57});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){1, 0
    , 210, 0, 155, 829, 829, 56, 56});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){1, 230
    , 405, 0, 155, 829, 831, 56, 56});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){1, 200
    , 635, 0, 80, 829, 831, 56, 56});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){1, 145
    , 595, 220, 450, 829, 831, 56, 64});
    return collide(win);
}

int can_player_move(win_t *win)
{
    for (int i = 0; i != win->nbr_obstacle; i++) {
        if (win->piece == win->all_obstacle[i].piece
        && win->x_player >= win->all_obstacle[i].x_player_min
        && win->x_player <= win->all_obstacle[i].x_player_max
        && win->y_player >= win->all_obstacle[i].y_player_min
        && win->y_player <= win->all_obstacle[i].y_player_max
        && win->x_map >= win->all_obstacle[i].x_map_min
        && win->x_map <= win->all_obstacle[i].x_map_max
        && win->y_map >= win->all_obstacle[i].y_map_min
        && win->y_map <= win->all_obstacle[i].y_map_max) {
            return 84;
        }
    }
    return 0;
}

win_t *create_grass(win_t *win)
{
    win->all_grass = malloc(sizeof(obstacle_t) * 28);
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){2, 106
    , 205, 156, 429, 14, 14, 54, 461});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){2, 106
    , 339, 300, 520, 14, 14, 410, 461});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){2, 400
    , 400, 300, 300, 15, 155, 301, 333});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){2, 400
    , 400, 300, 355, 250, 470, 456, 461});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){2, 580
    , 629, 156, 429, 496, 496, 54, 461});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){2, 400
    , 400, 0, 85, 256, 256, 54, 54});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 341, 404, 1433, 1466});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 61, 330, 1246, 1384});
    win->all_grass[win->nbr_grass++] = set_obstacles((int[9]){3, 400
    , 475, 300, 300, 425, 661, 1246, 1379});
    return grass(win);
}

void player_is_in_grass(win_t *win)
{
    for (int i = 0; i != win->nbr_grass; i++) {
        if (win->piece == win->all_grass[i].piece
        && win->x_player >= win->all_grass[i].x_player_min
        && win->x_player <= win->all_grass[i].x_player_max
        && win->y_player >= win->all_grass[i].y_player_min
        && win->y_player <= win->all_grass[i].y_player_max
        && win->x_map >= win->all_grass[i].x_map_min
        && win->x_map <= win->all_grass[i].x_map_max
        && win->y_map >= win->all_grass[i].y_map_min
        && win->y_map <= win->all_grass[i].y_map_max
        && sfClock_getElapsedTime(win->time_grass).microseconds > 500000) {
            (rand() % 10) == 0 ? win->step = STATE_FIGHT : 0;
            sfMusic_play(win->grass);
            sfClock_restart(win->time_grass);
            win->int_grass = 5;
        }
    }
}
