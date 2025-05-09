/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** my
*/

#ifndef FRAMEBUFFER_H_
    #define FRAMEBUFFER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio/Music.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <math.h>
    #include <time.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    typedef struct var
    {
        sfTexture *texture_cloud2;
        sfTexture *texture_cloud3;
        sfTexture *texture_cloud4;
        sfTexture *texture_option;
        sfTexture *texture_select;
        sfTexture *texture_cloud;
        sfTexture *texture_sound;
        sfTexture *texture_start;
        sfTexture *texture_level;
        sfSprite *sprite_cloud2;
        sfSprite *sprite_cloud3;
        sfSprite *sprite_cloud4;
        sfSprite *sprite_option;
        sfTexture *texture_bat2;
        sfTexture *texture_bat3;
        sfTexture *texture_bat4;
        sfTexture *texture_bat5;
        sfTexture *texture_bird;
        sfSprite *sprite_select;
        sfRenderWindow *window;
        sfSprite *sprite_cloud;
        sfSprite *sprite_sound;
        sfSprite *sprite_start;
        sfTexture *texture_bat;
        sfTexture *texture_end;
        sfTexture *texture_sun;
        sfSprite *sprite_level;
        sfSprite *sprite_bat2;
        sfSprite *sprite_bat3;
        sfSprite *sprite_bat4;
        sfSprite *sprite_bat5;
        sfSprite *sprite_bird;
        sfVector2f pos_cloud2;
        sfVector2f pos_cloud3;
        sfVector2f pos_cloud4;
        sfVector2f pos_option;
        sfClock *clock_cloud;
        sfClock *clock_speed;
        sfSprite *sprite_bat;
        sfSprite *sprite_sun;
        sfVector2f pos_sound;
        sfVector2f pos_start;
        sfSprite *sprite_end;
        sfClock *clock_bird;
        sfVector2i position;
        float second_cloud;
        float second_speed;
        sfClock *clock_bat;
        sfClock *clock_sun;
        sfVector2f pos_sun;
        float second_bird;
        sfTime time_cloud;
        sfTime time_speed;
        float second_bat;
        float second_sun;
        sfIntRect cloud2;
        sfIntRect cloud3;
        sfIntRect cloud4;
        sfIntRect option;
        sfTime time_bird;
        sfVideoMode mode;
        sfIntRect select;
        int choice_bird;
        sfMusic *music2;
        sfIntRect cloud;
        sfIntRect sound;
        sfIntRect start;
        sfTime time_bat;
        sfTime time_sun;
        sfVector2u size;
        sfIntRect level;
        int stat_music;
        float x_cloud2;
        float x_cloud3;
        float x_cloud4;
        float x_option;
        float y_cloud2;
        float y_cloud3;
        float y_cloud4;
        float y_option;
        sfIntRect bat2;
        sfIntRect bat3;
        sfIntRect bat4;
        sfIntRect bat5;
        sfIntRect bird;
        sfMusic *music;
        sfVector2f vec;
        float x_select;
        float y_select;
        int speed_bat;
        float x_cloud;
        float x_sound;
        float x_start;
        float y_cloud;
        float y_sound;
        float y_start;
        sfEvent event;
        sfIntRect bat;
        sfIntRect sun;
        sfIntRect end;
        float x_level;
        float y_level;
        int exit_nbr;
        float volume;
        float x_bat2;
        float x_bat3;
        float x_bat4;
        float x_bat5;
        float x_bird;
        float y_bat2;
        float y_bat3;
        float y_bat4;
        float y_bat5;
        float y_bird;
        sfFont *font;
        sfText *text;
        float x_bat;
        float x_sun;
        float y_bat;
        float y_sun;
        float x_end;
        float y_end;
        int r_nbr;
        int score;
        int etat;
        int nbr;
    } var_t;
    sfSprite *create_sprite(float x, float y, char *image, int zoom);
    sfSprite *move_sprite(float x, float y, sfSprite *sprite);
    var_t detects_music(var_t var, sfVector2i mouse);
    char *my_strcpy(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    sfText *setup_score_max(var_t var, int n);
    sfText *setup_font_max(var_t var, int n);
    char *my_strcat(char *dest, char *src);
    var_t select_bat_fourth(var_t var);
    var_t select_bat_second(var_t var);
    var_t select_bat_fifth(var_t var);
    var_t select_bat_first(var_t var);
    var_t select_bat_third(var_t var);
    var_t update_main_menu(var_t var);
    var_t set_bat_fourth(var_t var);
    var_t set_bat_second(var_t var);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    sfText *setup_score(var_t var);
    var_t detects_event(var_t var);
    var_t set_bat_fifth(var_t var);
    var_t set_bat_first(var_t var);
    var_t set_bat_third(var_t var);
    var_t resize_window(var_t var);
    var_t update_window(var_t var);
    var_t second_level(var_t  var);
    sfText *setup_level(var_t var);
    sfText *setup_font(var_t var);
    sfText *setup_lose(var_t var);
    var_t animate_bird(var_t var);
    var_t free_foncion(var_t var);
    var_t move_sprites(var_t var);
    var_t select_music(var_t var);
    var_t animate_bat(var_t var);
    var_t print_pause(var_t var);
    var_t first_level(var_t var);
    sfText *setup_win(var_t var);
    var_t print_level(var_t var);
    var_t move_cloud(var_t var);
    var_t print_game(var_t var);
    var_t print_menu(var_t var);
    var_t set_sprite(var_t var);
    char *my_revstr(char *str);
    var_t collision(var_t var);
    var_t print_end(var_t var);
    var_t dec_var6(var_t var);
    var_t move_bat(var_t var);
    var_t move_sun(var_t var);
    char *int_to_str(int nb);
    var_t dec_var(var_t var);
    var_t replay(var_t var);
    void case_null(int ac);
    void my_putchar(char c);
    void case_h(void);
    var_t first_level_2(var_t var);
    var_t second_level_5(var_t var, int c);
    var_t second_level_7(var_t var, int c);
    var_t second_level_9(var_t var, int c);
    var_t play_game_loop(var_t var);
    var_t test_replay(var_t var);
    void test_flag(int ac, char **av, var_t var);
#endif
