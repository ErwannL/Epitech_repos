/*
** EPITECH PROJECT, 2022
** csfml_utils
** File description:
** csfml utilities.
*/

#include "my_rpg.h"

double randpos(int max, int min)
{
    double r = (double)rand() / (double)RAND_MAX;

    return (min + r * (max - min));
}

win_t *resize_window(win_t *var)
{
    sfVector2u size = sfRenderWindow_getSize(var->window);

    if (size.y < 600 || size.y > 1080) {
        size.y = size.y < 600 ? 600 : 1080;
        sfRenderWindow_setSize(var->window, size);
    }
    if (size.x < 800 || size.x > 1920) {
        size.x = size.x < 800 ? 800 : 1920;
        sfRenderWindow_setSize(var->window, size);
    }
    sfRenderWindow_clear(var->window, sfWhite);
    return var;
}

fb_t *fb_create(int width, int height)
{
    fb_t *buffer = malloc(sizeof(fb_t));
    sfUint8 *pixels = malloc(width * (height + 1) * 4);

    buffer->width = width;
    buffer->height = height;
    buffer->pixels = pixels;
    return buffer;
}

void create_window(win_t *win, int x, int y)
{
    sfVideoMode video_mode = {x, y, 32};

    win->window = sfRenderWindow_create(video_mode, "My RPG",
    sfResize | sfClose, NULL);
    win->buf = fb_create(x, y);
    win->time = sfClock_create();
    win->move_player = sfClock_create();
    win->time_grass = sfClock_create();
    sfRenderWindow_setFramerateLimit(win->window, 60);
    win->win_size = sfRenderWindow_getSize(win->window);
}

void free_all(win_t *win)
{
    for (int i = 0; i < win->opt_beg[0].count; i++)
        sfText_destroy(win->opt_beg[i].txt);
    sfMusic_stop(win->bgm);
    sfSound_destroy(win->hit_btn);
    sfMusic_destroy(win->colide);
    sfMusic_destroy(win->grass);
    sfMusic_destroy(win->bgm);
    free(win->opt_beg);
    free(win->buf->pixels);
    free(win->buf);
    sfSprite_destroy(win->cursor);
    sfSprite_destroy(win->map);
    sfSprite_destroy(win->chen);
    free(win->path_map);
    free(win->all_obstacle);
    for (int i = 0; i != 2; sfSprite_destroy(win->rain_sprite[i]), i++);
    free(win->rain_sprite);
    sfSprite_destroy(win->grass_sprite);
    free(win->player->poke);
    free_next(win);
}
