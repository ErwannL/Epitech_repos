/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** collide_bis
*/

#include "my_rpg.h"

win_t *collide_ten(win_t *win)
{
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){6, 0
    , 400, 0, 285, 1229, 1369, 39, 39});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){6, 0
    , 730, 0, 100, 1229, 1451, 39, 39});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){6, 400
    , 440, 120, 285, 1351, 1451, 39, 39});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){6, 478
    , 730, 120, 285, 1451, 1451, 39, 39});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){6, 600
    , 730, 285, 300, 1451, 1451, 39, 79});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){6, 400
    , 400, 325, 520, 1295, 1370, 86, 86});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){6, 484
    , 730, 324, 520, 1451, 1451, 86, 86});
    return win;
}

win_t *collide_nine(win_t *win)
{
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){5, 0
    , 400, 0, 80, 1499, 1580, 54, 54});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){5, 400
    , 730, 0, 144, 1560, 1586, 54, 54});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){5, 400
    , 680, 165, 300, 1550, 1586, 54, 75});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){5, 690
    , 730, 165, 300, 1585, 1586, 54, 60});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 565, 600, 575, 725});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 565, 690, 575, 690});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 630, 690, 600, 725});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){6, 0
    , 250, 325, 520, 1229, 1229, 86, 86});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){6, 0
    , 130, 0, 520, 1229, 1229, 39, 86});
    return collide_ten(win);
}

win_t *collide_eight(win_t *win)
{
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 0, 300, 495, 635, 39, 65});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 0, 195, 615, 1000, 39, 39});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 730, 0, 300, 975, 1016, 39, 845});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 400
    , 400, 300, 300, 225, 324, 175, 369});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 400
    , 405, 300, 300, 300, 496, 175, 335});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){2, 400
    , 405, 300, 300, 380, 496, 289, 369});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){5, 0
    , 400, 300, 300, 1490, 1499, 95, 220});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){5, 400
    , 730, 300, 300, 1560, 1586, 95, 221});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){5, 0
    , 400, 0, 190, 1499, 1510, 54, 54});
    return collide_nine(win);
}

win_t *collide_seven(win_t *win)
{
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 0, 300, 80, 425, 39, 60});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 495, 635, 305, 425});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 620, 1000, 305, 365});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 495, 545, 95, 185});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 495, 640, 155, 245});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 620, 1000, 195, 245});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 705, 760, 125, 185});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 210, 300, 735, 940, 39, 185});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 20, 185, 465, 515, 39, 39});
    return collide_eight(win);
}

win_t *collide_six(win_t *win)
{
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 495, 995, 740, 785});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 740, 870, 395, 545});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 500, 635, 430, 480});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 405, 455, 430, 480});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 0
    , 400, 0, 300, 14, 95, 39, 365});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 110, 150, 95, 420});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 140, 395, 70, 455});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 300, 300, 380, 425, 100, 420});
    win->all_obstacle[win->nbr_obstacle++] = set_obstacles((int[9]){4, 400
    , 400, 295, 300, 315, 370, 39, 95});
    return collide_seven(win);
}
