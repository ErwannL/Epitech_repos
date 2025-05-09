/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-navy-hugo.fleury
** File description:
** error
*/

#include "navy.h"

int check_boat_positions(int i)
{
    if (game->map[i][2] != game->map[i][5] &&
        game->map[i][3] != game->map[i][6]) {
        my_putstr("[navy]: one or several boats are badly placed.\n", 2);
        return 84;
    }
    if (game->map[i][2] + i + 1 != game->map[i][5] &&
        game->map[i][3] == game->map[i][6]) {
        my_putstr("[navy]: one or several boats are badly placed.\n", 2);
        return 84;
    }
    if (game->map[i][2] == game->map[i][5] &&
        (game->map[i][3] - 48 + game->map[i][0] - 48) - 1 !=
        game->map[i][6] - 48) {
        my_putstr("[navy]: one or several boats are badly placed.\n", 2);
        return 84;
    }
    return 0;
}

int file_params_are_valids(void)
{
    char *check = malloc(sizeof(char) * 64);

    for (int i = 0; i != 64; i++)
        check[i] = '.';
    for (int i = 0; i != 4; i++) {
        if (((int)game->map[i][0] - '0') != (i + 2)) {
            my_putstr("[navy]: invalid boat length.\n", 2);
            return 84;
        }
        if (((game->map[i][2] < 'A' || game->map[i][2] > 'H') ||
                        (game->map[i][5] < 'A' || game->map[i][5] > 'H')) ||
                        ((game->map[i][3] < '1' || game->map[i][3] > '8') ||
                        (game->map[i][6] < '1' || game->map[i][6] > '8'))) {
            my_putstr("[navy]: one or several boats are not in the map.\n", 2);
            return 84;
        }
        if (check_boat_positions(i) == 84)
            return 84;
    }
    return 0;
}

char **setup_boats_positions(char **array, int n, int i)
{
    if (n == 0) {
        for (char j = game->map[i][2]; j != game->map[i][5] + 1;
            array[game->map[i][3] + 1 - '0'][get_pos_int(j)] = game->map[i][0],
            j++);
    } else {
        for (char j = game->map[i][3] + 1; j != game->map[i][6] + 2;
            array[j - '0'][get_pos_int(game->map[i][2])] = game->map[i][0],
            j++);
    }
    return array;
}

char **setup_boats(char **array)
{
    for (int i = 0; i != game->dimensions[1]; i++) {
        if (game->map[i][3] == game->map[i][6]) {
            array = setup_boats_positions(array, 0, i);
        } else {
            array = setup_boats_positions(array, 1, i);
        }
    }
    return array;
}

char **setup_map_positions(int x)
{
    char what = 'A';
    int dimensions[2] = { 17, 10 };
    char **array = mem_alloc_2d_array(dimensions);

    array[0][0] = ' ';
    array[0][1] = '|';
    for (int i = 2; i < 18; i++) {
        array[0][i] = (((i % 2) == 0) ? what : ' ');
        what += (((i % 2) == 0) ? 1 : 0);
    }
    array[0][17] = '\0';
    for (int i = 2; i != 10; array[i][0] = (i - 1) + '0', i++);
    for (int i = 2; i != 10; array[i][1] = '|', i++);
    for (int i = 0; i != 17; array[1][i] = ((i == 1) ? '+' : '-'), i++);
    for (int i = 2; i != 10; i++)
        for (int j = 2; j != 17; j++)
            array[i][j] = (((j % 2) == 0) ? '.' : ' ');
    array = ((x == 1) ? setup_boats(array) : array);
    return array;
}
