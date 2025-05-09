/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** csfml_initialisation
*/

#include "../includes/my.h"

void my_draw_empty_square(framebuffer_t *buffer, sfVector2u position,\
int size, sfColor color)
{
    for (int i = 0; i != size; i++) {
        for (int j = 0; j != size; j++) {
            ((i == 0 || i == size - 1 || j == 0 || j == size - 1) ?\
            my_put_pixel(buffer, (i + position.x), (j + position.y), color) :\
            0);
        }
    }
}

void draw_empty_circle(framebuffer_t *framebuffer, sfVector2u center,\
int radius, sfColor col)
{
    int x_pos = -1 * radius;
    int y_pos = 0;
    int number = 2 - 2 * radius;
    int num;

    if (center.x >= framebuffer->width || center.y >= framebuffer->height)
        return;
    while (1 == 1) {
        my_put_pixel(framebuffer, center.x - x_pos, center.y + y_pos, col);
        my_put_pixel(framebuffer, center.x + x_pos, center.y + y_pos, col);
        my_put_pixel(framebuffer, center.x + x_pos, center.y - y_pos, col);
        my_put_pixel(framebuffer, center.x - x_pos, center.y - y_pos, col);
        num = number;
        ((num <= y_pos) ? y_pos += 1, number += y_pos * 2 + 1, ((-1 * x_pos ==\
        y_pos && num <= x_pos) ? num = 0 : 0) : 0);
        ((num > x_pos) ? x_pos += 1, number += x_pos * 2 + 1 : 0);
        if (x_pos > 0)
            break;
    }
}

void draw_full_circle(framebuffer_t *framebuffer, sfVector2u center,\
int radius, sfColor col)
{
    int x_pos = -1 * radius;
    int y_pos = 0;
    int number = 2 - 2 * radius;
    int num;

    if (radius == 0)
        return;
    if (center.x >= framebuffer->width || center.y >= framebuffer->height)
        return;
    while (x_pos <= 0) {
        my_put_pixel(framebuffer, center.x - x_pos, center.y + y_pos, col);
        my_put_pixel(framebuffer, center.x + x_pos, center.y + y_pos, col);
        my_put_pixel(framebuffer, center.x + x_pos, center.y - y_pos, col);
        my_put_pixel(framebuffer, center.x - x_pos, center.y - y_pos, col);
        num = number;
        ((num <= y_pos) ? y_pos += 1, number += y_pos * 2 + 1, ((-1 * x_pos ==\
        y_pos && num <= x_pos) ? num = 0 : 0) : 0);
        ((num > x_pos) ? x_pos += 1, number += x_pos * 2 + 1 : 0);
    }
    draw_full_circle(framebuffer, center, --radius, col);
}

void draw_line(variables_t var)
{
    int dx = abs(var.position2.x - var.position.x);
    int sx = var.position.x < var.position2.x ? 1 : -1;
    int dy = -1 * abs(var.position2.y - var.position.y);
    int sy = var.position.y < var.position2.y ? 1 : -1;
    int err = dx + dy;
    int e2;

    while (1 == 1) {
        draw_full_circle(var.framebuffer, var.position, var.size, var.color);
        if (var.position.x == var.position2.x && var.position.y ==\
        var.position2.y)
            break;
        e2 = 2 * err;
        if (e2 >= dy) {
            err += dy; var.position.x += sx;
        }
        if (e2 <= dx) {
            err += dx; var.position.y += sy;
        }
   }
}

void update(variables_t var)
{
    sfTexture_updateFromPixels(var.texture, var.framebuffer->pixels, 800,600,\
    0, 0);
    sfRenderWindow_clear(var.window, sfBlack);
    sfRenderWindow_drawSprite(var.window, var.sprite, NULL);
    sfRenderWindow_display(var.window);
}
