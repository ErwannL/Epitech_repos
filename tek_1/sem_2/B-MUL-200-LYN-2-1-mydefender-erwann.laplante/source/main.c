/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** main
*/

#include "../include/my.h"

var_t *menu(var_t *var)
{
    if (var->second_unbug_menu >= 10) {
        var = print_stat(var);
        var = resize_window(var);
    } else {
        (var->second_unbug_menu > 0) ? sfRenderWindow_clear(var->window
        , sfBlack) : 0;
        sfRenderWindow_drawText(var->window, setup_wait(var
        , sfRenderWindow_getSize(var->window).x / 2
        , sfRenderWindow_getSize(var->window).y / 2), NULL);
        sfRenderWindow_display(var->window);
        sfText_destroy(var->text);
    }
    return var;
}

int my_defender(var_t *var)
{
    var = init_struct(var);
    while (sfRenderWindow_isOpen(var->window)) {
        var = detect_events(var);
        if (var->previous_stat == STAT_LOOSE && var->etat == STAT_GAME) {
            var = destroy_music(var);
            var = restart(var);
        }
        if (var->e_nbr == 84) {
            var = destroy_music(var);
            return var->r_val;
        }
        var->time_unbug_menu = sfClock_getElapsedTime(var->clock_unbug_menu);
        var->second_unbug_menu = var->time_unbug_menu.microseconds / 1000000;
        var = menu(var);
        var->second_unbug_menu = 0;
    }
}

int main(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));

    if (argc != 1 && my_strcmp(argv[1], "-h") != 0) {
        my_putstr("Error try -h !\n");
        return 84;
    } else if (argc != 1 && my_strcmp(argv[1], "-h") == 0) {
        print_h();
        return 0;
    } else {
        return (my_defender(var));
    }
}
