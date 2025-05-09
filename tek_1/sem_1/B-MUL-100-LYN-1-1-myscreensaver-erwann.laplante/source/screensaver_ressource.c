/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** csfml_initialisation
*/

#include "../includes/my.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *frame_buffer;

    frame_buffer = malloc(sizeof(framebuffer_t));
    frame_buffer->width = width;
    frame_buffer->height = height;
    frame_buffer->pixels = malloc(sizeof(sfUint8) * height * width * 32 / 8);
    return (frame_buffer);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,\
sfColor color)
{
    framebuffer->pixels[(x + y * framebuffer->width) * 4] = color.r;
    framebuffer->pixels[(x + y * framebuffer->width) * 4 + 1] = color.g;
    framebuffer->pixels[(x + y * framebuffer->width) * 4 + 2] = color.b;
    framebuffer->pixels[(x + y * framebuffer->width) * 4 + 3] = color.a;
}

void my_draw_square(framebuffer_t *buffer, sfVector2u position, int size,\
sfColor color)
{
    for (int i = 0; i != size; i++) {
        for (int j = 0; j != size; j++) {
            my_put_pixel(buffer, (i + position.x), j + position.y, color);
        }
    }
}

void my_draw_rectangle(framebuffer_t *buffer, sfVector2u position, int *size,\
sfColor color)
{
    for (int i = 0; i != size[0]; i++) {
        for (int j = 0; j != size[1]; j++) {
            my_put_pixel(buffer, (i + position.x), (j + position.y), color);
        }
    }
}
