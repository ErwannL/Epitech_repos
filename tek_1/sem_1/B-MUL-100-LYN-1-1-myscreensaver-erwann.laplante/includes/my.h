/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** my
*/

#ifndef FRAMEBUFFER_H_
    #define FRAMEBUFFER_H_
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <math.h>
    #include <time.h>
    typedef struct framebuffer {
        unsigned int width;
        unsigned int height;
        sfUint8 *pixels;
    } framebuffer_t;
    typedef struct variables {
        sfVideoMode mode;
        sfRenderWindow* window;
        sfTexture* texture;
        sfSprite* sprite;
        sfEvent event;
        framebuffer_t *framebuffer;
        sfVector2u position;
        sfVector2u position2;
        sfVector2u position3;
        sfVector2u position4;
        sfVector2i point_a;
        sfVector2i point_b;
        int n;
        sfColor color;
        int dx;
        int dy;
        int r;
        int size;
        int random;
        int r_val;
    } variables_t;
    typedef struct initialisation {
        char s[9];
        int (*sc[9])(void);
        int i;
        int r;
    } initialisation_t;
    int my_put_nbr(int nb);
    void my_putchar(char c);
    int my_putstr(char const *str);
    framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
    void framebuffer_destroy(framebuffer_t *framebuffer);
    void my_put_pixel(framebuffer_t *framebuffer, unsigned int x,\
    unsigned int y, sfColor color);
    void my_draw_square(framebuffer_t *buffer, sfVector2u position, int size,\
    sfColor color);
    void my_draw_rectangle(framebuffer_t *buffer, sfVector2u position,\
    int *size, sfColor color);
    void my_draw_empty_square(framebuffer_t *buffer, sfVector2u position,\
    int size, sfColor color);
    void draw_empty_circle(framebuffer_t *framebuffer, sfVector2u center,\
    int radius, sfColor col);
    void draw_full_circle(framebuffer_t *framebuffer, sfVector2u center,\
    int radius, sfColor col);
    void draw_line(variables_t var);
    void update(variables_t var);
    variables_t detroy_all(variables_t var);
    initialisation_t help_main(initialisation_t i, char **av);
    variables_t letters1(variables_t var);
    variables_t letters6(variables_t var);
    variables_t letters11(variables_t var);
    variables_t letters16(variables_t var);
    variables_t letters21(variables_t var);
    variables_t screen_saver0_2(variables_t var);
    variables_t screen_saver0_1(void);
    int screen_saver1_1(void);
    int screen_saver2_1(void);
    int screen_saver3_1(void);
    int screen_saver4_1(void);
    int screen_saver5_1(void);
    int screen_saver6_1(void);
    int screen_saver7_1(void);
    int screen_saver8_1(void);
    int screen_saver9_1(void);
    variables_t screen_saver8_5(variables_t var);
    variables_t screen_saver9_2(variables_t var);
#endif
