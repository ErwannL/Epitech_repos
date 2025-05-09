/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** bsq
*/

#include"../includes/my.h"

variables_t bsq_4(variables_t var, int a)
{
    for (int b = 0; var.result[a][b] != '\n'; b++) {
        if (b >= var.start[0] && b <= var.max[1] && a >= var.start[1] && a <= \
        var.max[2])
            var.result[a][b] = 'x';
        my_putchar(var.result[a][b]);
    }
}

void bsq_3(variables_t var)
{
    var.start[0] = -1;
    var.start[1] = -1;
    if (var.max[1] == -1 || var.max [2] == -1) {
        my_putstr(var.buf);
        my_putstr("\n\0");
        free(var.result);
        free(var.map);
        exit(0);
    } else {
        var.start[0] = var.max[1] + 1 - var.max[0];
        var.start[1] = var.max[2] + 1 - var.max[0];
        for (int a = 0; var.result[a] != NULL; a++) {
            var = bsq_4(var, a);
            my_putchar('\n');
        }
        my_putstr("\0");
        free(var.result);
        free(var.map);
        exit(0);
    }
}

void bsq_2(variables_t var)
{
    var.result[var.j] = NULL;
    var.max[0] = 0;
    var.max[1] = -1;
    var.max[2] = -1;
    for (int x = 0; var.result[x] != NULL; x++) {
        for (int y = 0; var.result[x][y] != '\n'; y++) {
            (((x == 0 || y == 0) && var.result[x][y] == '.') ? (var.map[x][y] \
            = 1, var = var) : (((x == 0 || y == 0) && var.result[x][y] == \
            'o') ? (var.map[x][y] = 0, var = var) : (((x != 0 && y != 0) && \
            var.result[x][y] == '.') ? (var.map[x][y] = -1, var = \
            minimmum(var, x, y)) : (var.map[x][y] = 0, var = var))));
            ((var.map[x][y] > var.max[0]) ? (var.max[0] = var.map[x][y], \
            var.max[1] = y, var.max[2] = x) : 0);
        }
    }
    bsq_3(var);
}

void bsq_1(variables_t var)
{
    var.j = 0;
    var.len = 0;
    var.result = malloc(sizeof(char *) * (number_of_word(var.buf) + 1));
    var.map = malloc(sizeof(int *) * (number_of_word(var.buf) + 1));
    for (int i = 0; var.buf[i] != '\0'; i++) {
        if (alpha_num(var.buf[i]) == 0)
            var.len++;
        if (alpha_num(var.buf[i]) == 0 && alpha_num(var.buf[i + 1]) == 1) {
            var.result[var.j] = malloc(sizeof(char) * (var.len + 1));
            var.map[var.j] = malloc(sizeof(int) * (var.len + 1));
            my_strncpy(var.result[var.j], &var.buf[i - var.len + 1], var.len);
            my_strcat(var.result[var.j], "\n");
            var.len = 0;
            var.j++;
        }
    }
    bsq_2(var);
}

int main(int ac, char **av)
{
    variables_t var;

    var.height = 0;
    ((ac != 2) ? (exit(84)) : 0);
    var.fd = open(av[1], O_RDONLY);
    ((var.fd == -1) ? (exit(84)) : 0);
    var.st = malloc(sizeof(struct stat));
    stat(av[1], var.st);
    var.buf = malloc(sizeof(char) * (var.st->st_size + 2));
    read(var.fd, var.buf, var.st->st_size - 1);
    var.buf[var.st->st_size] = '\n';
    var.buf[var.st->st_size + 1] = '\0';
    ((var.st->st_size <= 1) ? exit(84) : 0);
    var = error(var);
    var.width = my_get_width(var.buf);
    (var.height < 1 || var.width < 1) ? exit(84) : ((var.height == 1 || \
    var.width == 1) ? one_c_l(var) : bsq_1(var));
    return (84);
}
