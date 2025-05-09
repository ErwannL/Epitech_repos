/*
** EPITECH PROJECT, 2022
** utilities
** File description:
** my_runner refresh file.
*/

#include "my_rpg.h"

char **get_game_infos(win_t *win)
{
    char **arr = NULL;
    int sz = sizeof(player_t) + sizeof(poke_t) + sizeof(capa_t);

    if ((arr = (char **)malloc(sizeof(char *) * (sz + 1))) == NULL) {
        return NULL;
    }
    arr[0] = my_strcat("player", win->player->name);
    arr[1] = my_strcat("badges", my_itoa(win->player->badges));
    arr[2] = my_strcat("pokedex", my_itoa(win->player->pokedex));
    arr[3] = NULL;
    return arr;
}

char *open_file(void)
{
    int fd = 0;
    int len = 0;
    int off = 0;
    char *buf = (char *)malloc(4096 + 1);

    if ((fd = open(".rpg", O_RDONLY)) == -1)
        return NULL;
    for (; (len = read(fd, buf + off, 4096 - off)) > 0; off += len) {
        off += len;
    }
    buf[off] = '\0';
    close(fd);
    return buf;
}

void write_to_file(win_t *win)
{
    FILE *fd = fopen(".rpg", "w");
    char **infos = get_game_infos(win);

    if (infos == NULL)
        return;
    for (int i = 0; infos[i] != NULL; i++) {
        fwrite(infos[i], my_strlen_two(NULL, infos[i], 0), 1, fd);
    }
    fclose(fd);
    for (int i = 0; infos[i] != NULL; free(infos[i]), i++);
    free(infos);
}

int ibcollision(sfSprite *one, sfSprite *two)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(one);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(two);

    return ((sfFloatRect_intersects(&rect1, &rect2, NULL) == 1) ? 1 : 0);
}
