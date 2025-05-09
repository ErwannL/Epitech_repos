/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** include all prototypes of my_rpg
*/

#ifndef MY_RPG_H
    #define MY_RPG_H
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <time.h>

    #define STATE_QUIT -1
    #define STATE_HTP 0
    #define STATE_MENU 1
    #define STATE_OPTIONS 3
    #define STATE_PLAYER 4
    #define STATE_GAME 5
    #define STATE_PAUSE 6
    #define STATE_POKEDEX 7
    #define STATE_FIGHT 8
    #define STATE_ITEMS 9
    #define STATE_SAVE 10
    #define STATE_CHOOSE_NAME 11
    #define FIGHT_RIVAL 20
    #define ATK_INTERFACE 2
    #define BAG_INTERFACE 3
    #define PKM_INTERFACE 4
    #define RUN_INTERFACE 5
    #define NORMAL 0
    #define WATER 1
    #define GRASS 2
    #define FIRE 3
    #define ELECK 4
    #define TURN_A 1
    #define TURN_B 2

    typedef struct {
        unsigned int height;
        unsigned int width;
        sfUint8 *pixels;
    } fb_t;

    typedef struct {
        sfVector2f size;
        sfVector2f pos;
        sfSprite *sprite;
        sfColor color;
    } btn_t;

    typedef struct {
        int count;
        sfText *txt;
        sfVector2f where;
    } opt_t;

    typedef struct {
        sfText *name;
        int dmg;
        int type;
    } capa_t;

    typedef struct {
        sfText *name;
        sfText *t_lvl;
        int lvl;
        sfText *t_hp;
        int hp;
        sfText *t_hp_max;
        int hp_max;
        int atk;
        int def;
        int type;
        int xp;
        sfSprite *sprite_back;
        sfSprite *sprite_front;
        capa_t capa1;
        capa_t capa2;
        capa_t capa3;
        capa_t capa4;
    } poke_t;

    typedef struct {
        char *name;
        int badges;
        int pokedex;
        char **bag;
        poke_t *poke;
        sfSprite *player;
    } player_t;

    typedef struct {
        char *name;
        poke_t poke;
        sfSprite *sprite;
    } trainer_t;

    typedef struct {
        sfSprite *beg;
        sfSprite *beg1;
        sfSprite *options;
        sfSprite *ingame;
        sfSprite *speak;
        sfSprite *name;
    } frame_t;

    typedef struct {
        int piece;
        int x_player_min;
        int x_player_max;
        int y_player_min;
        int y_player_max;
        int x_map_min;
        int x_map_max;
        int y_map_min;
        int y_map_max;
    } obstacle_t;

    typedef struct {
        int x_player;
        int y_player;
        int x_map;
        int y_map;
        int x_collide;
        int y_collide;
        int x_chen;
        int y_chen;
        int x_labo;
        int y_labo;
    } pos_t;

    typedef struct {
        int done;
        char *name;
    } quest_t;

    typedef struct {
        sfRenderWindow *window;
        sfVector2u win_size;
        trainer_t rival;
        trainer_t you;
        trainer_t wild;
        poke_t pikachu;
        poke_t bulbizare;
        poke_t salameche;
        player_t *player;
        frame_t *frame;
        sfClock *clock;
        sfClock *clock_fight;
        sfSprite *map;
        sfSprite *chen;
        sfSprite *cursor;
        sfSound *hit_btn;
        sfEvent event;
        sfClock *time;
        opt_t *opt_beg;
        opt_t *select_action;
        sfSprite *start;
        sfFont *font;
        sfMusic *bgm;
        fb_t *buf;
        sfVector2f pos_cursor;
        sfSprite *introf_interface;
        sfSprite *fight_interface;
        sfSprite *stat_interface;
        sfSprite *box_action;
        char *input;
        int skip_intro_fight;
        int step;
        int old_step;
        int one_time;
        int cursor_limit;
        int x_map;
        int y_map;
        char *path_map;
        sfSprite *player_sprite;
        int x_player;
        int y_player;
        int piece;
        sfIntRect player_rect;
        sfClock *move_player;
        obstacle_t *all_obstacle;
        int nbr_obstacle;
        int last_key;
        pos_t *old_pos;
        sfMusic *colide;
        obstacle_t *all_grass;
        int nbr_grass;
        sfMusic *grass;
        sfClock *time_grass;
        int cursorx_limit;
        sfSprite *grass_sprite;
        int int_grass;
        sfSprite **rain_sprite;
        int rain;
        sfSprite *moving_collide;
        int x_collide;
        int y_collide;
        sfSprite *moving_chen;
        int x_chen;
        int y_chen;
        sfSprite *moving_labo;
        int x_labo;
        int y_labo;
        quest_t *quest;
        int nbr_custo;
        int what_custo;
        int *customise;
        int volume;
        int prev_step;
        int action;
        capa_t thunder;
        capa_t leer;
        capa_t vine_whip;
        capa_t ember;
        capa_t water_gun;
        capa_t tackle;
        int turn;
        int change;
        sfSprite *pokemon;
    } win_t;

    int my_strcmp(char const *s1, char const *s2);
    int my_strlen(char const *str);
    char *my_strcpy(char *src);

    int can_player_move(win_t *win);
    win_t *create_obstacles(win_t *win);
    win_t *create_grass(win_t *win);
    void player_is_in_grass(win_t *win);
    win_t *game(win_t *win);
    win_t *collide(win_t *win);
    obstacle_t set_obstacles(int *nbr);
    win_t *collide_six(win_t *win);
    win_t *grass(win_t *grass);
    win_t *move_player(win_t *win);
    win_t *tp_player(win_t *win);
    win_t *tp_player_six(win_t *win);
    win_t *print_grass(win_t *win);
    win_t *print_rain(win_t *win);
    int ibcollision(sfSprite *one, sfSprite *two);
    win_t *right_four(win_t *win);
    win_t *left_four(win_t *win);
    win_t *down_four(win_t *win);
    win_t *up_four(win_t *win);
    win_t *right_five(win_t *win);
    win_t *left_five(win_t *win);
    win_t *down_five(win_t *win);
    win_t *up_five(win_t *win);
    win_t *right_six(win_t *win);
    win_t *left_six(win_t *win);
    win_t *down_six(win_t *win);
    win_t *up_six(win_t *win);
    win_t *print_moving_collide(win_t *win);
    win_t *save_pos(win_t *win);
    win_t *get_pos(win_t *win);
    int print_done(win_t *win, int j);
    int print_to_do(win_t *win, int j);
    void setup_sprites_five(win_t *win);
    int custome(win_t *win, int j);
    void my_putchar(char c);
    int my_putstr(char const *str);
    void print_htp(win_t *win);
    win_t *print_option(win_t *win);
    int print_pause(win_t *win);
    win_t *print_player_stat(win_t *win);
    win_t *choose_name(win_t *win);
    win_t *accept_name(win_t *win);
    win_t *print_pokedex(win_t *win);
    int detect_click_pause(win_t *win);
    win_t *tp_player_in_pause(win_t *win);
    void change_poke(win_t *win);

    void intro_scene(win_t *win);
    void name_scene(win_t *win);
    void chen_intro(win_t *win, int *i);

    char *my_itoa(int number);
    char *my_strdup(char *src);
    char *my_revstr(char *str);
    char *my_strcat(char *dest, char *src);
    int my_strlen_two(char **array, char *what, int x);

    void free_all(win_t *win);
    void free_next(win_t *win);
    double randpos(int max, int min);
    fb_t *fb_create(int width, int height);
    void create_window(win_t *win, int x, int y);

    int ibaction(win_t *win, btn_t *btn);
    int buttons_events(win_t *win);

    void create_things(win_t *win);
    void create_sounds(win_t *win, char *what);
    sfSprite *create_sprite(char *what, sfVector2f where);
    sfText *create_font(win_t *win, int size, sfVector2f where, char *what);
    btn_t *create_button(sfVector2f size, sfVector2f where, char *sprite
    , int i);

    void refresh_all(win_t *win);
    void refresh_sound(win_t *win);
    void refresh_sprites(win_t *win);

    void setup_sprites(win_t *win);
    frame_t *setup_frame(win_t *win);
    void setup_opts(win_t *win, int x);

    void refresh_menu(win_t *win);
    opt_t *create_menu(win_t *win, int sz, char *list[], sfVector2i where);
    void menu_event(win_t *win, int limit_max);

    char *open_file(void);
    void write_to_file(win_t *win);

    void print_player_infos(win_t *win);

    win_t *resize_window(win_t *var);

    void create_poke(win_t *win);
    void create_trainers(win_t *win);
    void create_fights(win_t *win);
    void create_allcapa(win_t *win);
    poke_t set_capa(poke_t poke, capa_t capa1, capa_t capa2, capa_t capa3);

    poke_t set_fight(win_t *win, trainer_t you, trainer_t trainer);
    void draw_cursor(win_t *win);
    void set_interfaces(win_t *win);
    void select_action(win_t *win);

    void draw_stat(win_t *win, poke_t ally, poke_t enemy);
    char *my_getstr(int nb);
    sfText *set_update_data(char *score, sfText *text);
    int my_getnbr(char const *str, int i);
    poke_t set_statpika(poke_t poke, win_t *win);

    sfText *create_text(win_t *win, int size, sfVector2f where, char *what);

    int do_dmg(win_t *win, poke_t ally, poke_t enemy);
    void handle_keys(win_t *win);

    int take_dmg(win_t *win, poke_t ally, poke_t enemy);
    poke_t set_statbulbi(poke_t poke, win_t *win);

    void update_xp(win_t *win);
    void reset_stat(win_t *win);


    #define MY_PUTSTR(x) for (int i = 0; x[i]; write(1, &x[i], 1), i++)

    #define CHEN1 "Hello   and   welcome   into   this\n\n" \
                "amazing   world   Pokemon!"

    #define CHEN2 "You   are   about   to   start   a\n\nnew   journey!\n\n"

    #define CHEN3 "But   do   not   worry,   \n\nyou   will   not   be   " \
                "alone."

    #define CHEN4 "Indeed,   Pokemons   will   be   \n\nwith   you   through" \
                "   this!\n"

    #define CHEN5 "This   is   a   great   opportunity\n\nto  learn   more " \
                "about   them!"

    #define CHEN6 "But   before...  \n\ntell   me   more   about   you."
#endif
