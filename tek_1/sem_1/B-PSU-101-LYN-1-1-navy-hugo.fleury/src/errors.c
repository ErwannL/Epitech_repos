/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-navy-hugo.fleury
** File description:
** error
*/

#include "navy.h"

int open_file(char *what)
{
    int length = 0;
    int fd = open(what, O_RDONLY);

    if (!fd) {
        my_putstr("[navy]: unable to open the given file.\n", 2);
        return 84;
    }
    length = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    if ((game->buf = (char *)malloc(length)) == NULL) {
        my_putstr("[navy]: allocation failed (NULL).\n", 2);
        return 84;
    }
    read(fd, game->buf, length);
    close(fd);
    return 0;
}

int *get_dimensions(char *str)
{
    int *dimensions = malloc(sizeof(int) * 2);

    for (int i = 0; str[i] != '\n'; i++, dimensions[0]++);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            dimensions[1]++;
    return dimensions;
}

int error_handling(int argc, char **argv)
{
    if ((argc < 2) || (argc > 3)) {
        my_putstr("[navy]: this program must take 2 or 3 arguments.\n", 2);
        return 84;
    }
    if (((argc == 2) ? open_file(argv[1]) : open_file(argv[2])) == 84) {
        return 84;
    }
    game->dimensions = get_dimensions(game->buf);
    if (game->dimensions[1] != 4) {
        my_putstr("[navy]: number of boats max. is 4 with a line break.\n", 2);
        return 84;
    }
    game->map = my_str_to_word_array(game->buf, game->dimensions);
    return file_params_are_valids();
}
