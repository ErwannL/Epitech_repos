/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** collide
*/

#include "my_rpg.h"

win_t *collide_five(win_t *win)
{
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 730, 300, 520, 555, 1016, 845, 926});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 0
    , 400, 300, 300, 14, 35, 455, 875});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 30, 160, 545, 785});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 140, 185, 575, 785});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 165, 220, 605, 785});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 200, 340, 630, 785});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 320, 365, 740, 785});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 375, 485, 740, 785});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 525, 575, 790, 840});
    return collide_six(win);
}

win_t *collide_four(win_t *win)
{
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 60, 155, 480, 580});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 130, 355, 505, 580});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 310, 535, 480, 580});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 60, 345, 125, 390});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 315, 535, 125, 200});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 400, 285, 300, 260, 345, 64, 140});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 400, 0, 190, 60, 335, 64, 64});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 475, 0, 190, 415, 661, 64, 64});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 0
    , 400, 300, 520, 14, 515, 845, 926});
    return collide_five(win);
}

win_t *collide_three(win_t *win)
{
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 475
    , 730, 0, 520, 661, 661, 64, 1466});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 60, 155, 1170, 1245});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 265, 345, 1150, 1245});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 475, 300, 300, 320, 661, 1170, 1245});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 60, 440, 955, 1055});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 475, 300, 300, 595, 661, 980, 1055});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 60, 105, 790, 865});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 400, 300, 300, 120, 295, 790, 865});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 475, 300, 300, 310, 661, 790, 865});
    return collide_four(win);
}

win_t *collide_two(win_t *win)
{
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 400
    , 400, 300, 300, 270, 340, 55, 135});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 400
    , 400, 165, 300, 305, 496, 54, 140});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 245
    , 400, 300, 300, 14, 20, 55, 140});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 340
    , 400, 165, 300, 14, 45, 54, 140});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 340
    , 400, 165, 300, 14, 180, 54, 95});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 400
    , 400, 300, 300, 80, 180, 80, 140});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 400, 300, 520, 20, 340, 1385, 1466});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 400
    , 580, 300, 520, 405, 661, 1380, 1466});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){3, 0
    , 400, 0, 300, 19, 60, 64, 1385});
    return collide_three(win);
}

win_t *collide(win_t *win)
{
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 0
    , 105, 0, 520, 14, 14, 54, 461});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 100
    , 400, 0, 155, 14, 255, 54, 54});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 400
    , 730, 0, 155, 305, 496, 52, 54});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 100
    , 205, 430, 520, 14, 14, 461, 461});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 630
    , 730, 150, 520, 496, 496, 54, 461});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 400
    , 635, 430, 520, 170, 496, 461, 461});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 340
    , 400, 300, 520, 14, 180, 410, 461});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 345
    , 400, 300, 300, 14, 180, 215, 300});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 400
    , 400, 300, 300, 230, 495, 380, 455});
    return collide_two(win);
}
