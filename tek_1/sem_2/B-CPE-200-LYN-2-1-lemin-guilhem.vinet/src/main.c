/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** main
*/

#include "lemin.h"

static char **read_stdin(void)
{
    int len = 0;
    int off = 0;
    int *dims = NULL;
    char **array = NULL;
    char *buf = (char *)malloc(sizeof(char) * (4096 + 1));

    for (; (len = read(0, buf + off, 4096 - off)) > 0; off += len);
    if (buf[off - 1] != '\n') {
        buf[off] = '\n';
        buf[off + 1] = '\0';
    } else {
        buf[off] = '\0';
    }
    if (len < 0)
        return NULL;
    dims = get_dimensions(buf);
    array = my_str_to_word_array(buf, dims);
    free(dims);
    free(buf);
    return array;
}

int print_ants (char **buf, ants_t *ants, int space)
{
    for (int i = 0; i != my_str_to_int(buf[0]); i++)
        if (ants[i].print == 1) {
            my_putstr("\n");
            space++;
            break;
        }
    return (space);
}

int set_finish (ants_t *ants, List *comp_room, int i, int space)
{
    if (my_strcmp(ants[i].where
    , clean_start(my_revstr(get_end(comp_room)))) == 0) {
        ants[i].finish = 1;
    } else {
        ants[i] = get_next_ant(ants[i], ants, i, space);
        space = 0;
        if (my_strcmp(ants[i].where
        , clean_start(my_revstr(get_end(comp_room)))) == 0)
            ants[i].finish = 1;
    }
    return (ants[i].finish);
}

int main_next(char **buf, List *comp_room, int *size_path, path_t *r_path)
{
    ants_t *ants;
    int space = 0;

    ants = malloc(sizeof(ants_t) * my_str_to_int(buf[0]));
    for (int i = 0; i != my_str_to_int(buf[0]); i++) {
        ants[i].finish = 0;
        ants[i].where = clean_start(my_revstr(get_start(comp_room)));
        ants[i].nbr_path = fin_mini_path(size_path, r_path->nbr_node);
        size_path[ants[i].nbr_path]++;
        ants[i].path = r_path->path[ants[i].nbr_path];
    }
    while (all_finish(ants, my_str_to_int(buf[0])) == 84) {
        for (int i = 0; i != my_str_to_int(buf[0]); i++) {
            ants[i].finish = set_finish(ants, comp_room, i, space);
        }
        space = print_ants(buf, ants, space);
    }
    return 0;
}

int main(int argc, char **argv)
{
    char **buf = NULL;
    List *room_list = init();
    List *comp_room = init();
    List *path = init();
    path_t *r_path = malloc(sizeof(path_t));
    int *size_path;

    if ((buf = read_stdin()) == NULL)
        return 84;
    if (error_handling(buf, room_list, comp_room, path) == 84)
        return (84);
    r_path = main_di(r_path, room_list, path, comp_room);
    for (int i = 0; i != r_path->nbr_node; i++)
        r_path->path[i] = clean_string(r_path->path[i]);
    size_path = malloc(sizeof(int) * r_path->nbr_node);
    for (int i = 0; i != r_path->nbr_node; i++)
        size_path[i] = get_len_path(r_path->path[i]) + 1;
    return main_next(buf, comp_room, size_path, r_path);
}
