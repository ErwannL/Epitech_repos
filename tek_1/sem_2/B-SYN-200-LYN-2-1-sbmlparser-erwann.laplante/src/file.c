/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** file
*/

#include "my.h"

int get_file_info(var_t *var, char **av)
{
    var->st_error = stat(av[1], &var->st);
    if (var->st_error == -1)
        return free_all(84, var);
    var->buf = malloc(sizeof(char) * (var->st.st_size + 1));
    var->buf[var->st.st_size] = '\0';
    var->fd = open(av[1], O_RDONLY);
    if (var->fd == -1)
        return free_all(84, var);
    var->re_error = read(var->fd, var->buf, var->st.st_size);
    if (var->re_error == -1)
        return free_all(84, var);
    return 0;
}
