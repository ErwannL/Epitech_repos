/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** my
*/

#ifndef MY_H

    //define

    #define MY_H
    #define INT_MAX 2147483647
    #define STAT_QUIT -1
    #define STAT_MENU 0
    #define STAT_SETTINGS 1
    #define STAT_GAME 2
    #define STAT_PAUSE 3
    #define STAT_BUILDING 4
    #define STAT_HOW_PLAY 5
    #define STAT_INTRO 6
    #define STAT_BUY 7
    #define STAT_LOOSE 8
    #define MUSIC_ON 0
    #define MUSIC_OFF 1

    //include

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

    //struct

    typedef struct var {
        sfRenderWindow *window;
        sfVideoMode mode;
        int e_nbr;
        int etat;
        sfEvent event;
        int r_val;
        sfFont *font;
        sfText *text;
        sfMusic *music;
        sfTexture *texture_background;
        sfSprite *sprite_background;
        sfIntRect background;
        sfSprite **ennemy;
        sfSprite **flying_ennemy;
        sfSprite **heavy_ennemy;
        sfIntRect flying_rec;
        sfIntRect heavy_rec;
        sfIntRect rec_ennemy;
        sfClock *clock;
        sfClock *clock_spawn;
        sfTime time_spawn;
        sfTime time;
        sfClock *clock_walk_ennemy;
        sfTime time_walk;
        float seconds;
        float seconds_walk;
        float seconds_spawn;
        int round;
        int heavy;
        int flying;
        int *path;
        int *life_ennemy;
        int *life_heavy;
        int *life_flying;
        int *path_heavy;
        int *path_flying;
        int number_round;
        int number_ennemy;
        float x_background;
        float y_background;
        float volume;
        int stat_music;
        int dif_x;
        int dif_y;
        int previous_stat;
        sfTime time_cloud;
        sfClock *clock_cloud;
        float second_cloud;
        sfTexture **texture_cloud;
        sfSprite **sprite_cloud;
        sfIntRect *cloud;
        float *x_cloud;
        float *y_cloud;
        int nb_cloud;
        char **how_play;
        sfMusic *click_mouse;
        sfMusic *gold;
        sfTime time_pause;
        sfClock *clock_pause;
        float second_pause;
        sfSprite *sprite_sound;
        sfIntRect sound;
        float x_sound;
        float y_sound;
        int score;
        sfTime time_game;
        sfClock *clock_game;
        float second_game;
        sfSprite **sprite_weapons;
        sfIntRect *weapons;
        float *x_weapons;
        float *y_weapons;
        char **price_weapons;
        sfSprite *sprite_dark;
        sfIntRect dark;
        sfTime time_unbug_menu;
        sfClock *clock_unbug_menu;
        float second_unbug_menu;
        sfTime time_free_music;
        sfClock *clock_free_music;
        float second_free_music;
        sfSprite **sprite_play_weapons;
        sfTexture *texture_castle;
        sfSprite *sprite_castle;
        sfIntRect castle;
        int *turret;
        int life;
        sfTime time_kill;
        sfClock *clock_kill;
        float second_kill;
        sfTime time_deg_en;
        sfClock *clock_deg_en;
        float second_deg_en;
    } var_t;

    //lib

    char *int_to_str(int nb);
    int my_put_nbr(int nb);
    void my_putchar(char c);
    int my_putstr(char const *str);
    char *my_revstr(char *str);
    char *my_strcat(char *dest, char *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest , char const *src);
    int my_strlen(char const *str);

    //source

    void print_h(void);
    var_t *more_path(var_t *var, int i, sfVector2f vec);
    var_t *more_more_path(var_t *var, int i, sfVector2f vec);
    var_t *move_path_heavy(var_t *var, int i);
    var_t *move_path(var_t *var, int i);
    var_t *damage(var_t *var);
    var_t *resize_window(var_t *var);
    var_t *move(var_t *var);
    int *my_intncat(int *list, int n, int lenght);
    sfSprite **my_spritencat(sfSprite **list, int n, int lenght);
    var_t *check_round(var_t *var);
    var_t *game(var_t *var);
    var_t *move_path_flying(var_t *var, int i);
    var_t *entity_death(var_t *var);
    sfSprite *create_sprite_rec(sfIntRect rec, char *image);
    sfVector2f create_vector(int x, int y);
    var_t * print_stat(var_t *var);
    var_t *init_struct(var_t *var);
    var_t *detect_events(var_t *var);
    sfText *setup_text(var_t *var, int x, int y, char *text);
    var_t *destroy_music(var_t *var);
    var_t *more_path_heavy(var_t *var, int i, sfVector2f vec);
    sfSprite *create_sprite(float x, float y, char *image, int zoom);
    sfSprite *move_sprite(float x, float y, sfSprite *sprite);
    var_t *print_menu(var_t *var);
    var_t *print_how_play(var_t *var);
    var_t *print_intro(var_t *var);
    sfText *setup_how_play(var_t *var, int x, int y, char *text);
    var_t *print_pause(var_t *var);
    sfText *setup_pause(var_t *var, int x, int y, char *text);
    var_t *print_settings(var_t *var);
    var_t *set_sprite_volume_start(var_t *var);
    sfText *setup_settings(var_t *var, int x, int y, char *text);
    var_t *print_building(var_t *var);
    sfText *setup_game(var_t *var, int x, int y, char *text);
    var_t *print_game(var_t *var);
    sfSprite *change_scale(sfSprite *sprite, float i, float j);
    var_t *print_buy(var_t *var);
    sfSprite *change_image(sfSprite *sprite, char *image);
    var_t *save_play_weapons_one(var_t *var, sfVector2i mouse);
    var_t *save_play_weapons_six(var_t *var, sfVector2i mouse);
    var_t *init_struct_six(var_t *var);
    int detect_key_one_to_four(var_t *var);
    var_t *reset_pos(var_t *var);
    var_t *round_on(var_t *var);
    var_t *round_off(var_t *var);
    var_t *move_ennemy(var_t *var);
    var_t *print_background(var_t *var);
    var_t *death(var_t *var);
    var_t *entity_death_ter(var_t *var);
    var_t *print_game_bis(var_t *var);
    var_t *print_loose(var_t *var);
    var_t *restart(var_t *var);
    int my_sqrt(int n);
    var_t *damage_bis(var_t *var, int j);
    var_t *damage_flying(var_t *var, int i, int check);
    var_t *damage_heavy(var_t *var, int i, int check);
    var_t *damage_ennemy(var_t *var, int i, int check);
    int check_range(sfSprite *weapons, sfSprite *ennemy, var_t *var, int pos);
    sfText *setup_wait(var_t *var, int x, int y);
    var_t *move_ennemy_new(var_t *var);

#endif
