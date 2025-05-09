/*
** EPITECH PROJECT, 2021
** Task 03 - my_params_to_array
** File description:
** my_params_to_array
*/
#include"include/my.h"

struct info_param *my_params_to_array(int ac , char **av)
{
    struct info_param *param;
    param = malloc(sizeof(struct info_param) * (ac + 1));
    for (int i = 0; i < ac; i++) {
        param[i].length = my_strlen(av[i]);
        param[i].str = av[i];
        param[i].copy = my_strdup(av[i]);
        param[i].word_array = my_str_to_world_array(av[i]);
    }
    param[ac].str = 0;
    return (param);
}
