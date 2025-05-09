/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** setup
*/

#include "my_rpg.h"

frame_t *setup_frame(win_t *win)
{
    frame_t *frame = (frame_t *)malloc(sizeof(frame_t));

    frame->beg = create_sprite("./res/spr/frame.png", (sfVector2f){10, 10});
    sfSprite_setScale(frame->beg, (sfVector2f){0.3, 0.3});
    frame->ingame = create_sprite("./res/spr/frame1.png"
                                , (sfVector2f){(win->win_size.x - 318), 10});
    sfSprite_setScale(frame->ingame, (sfVector2f){0.215, 0.215});
    frame->beg1 = create_sprite("./res/spr/frame.png", (sfVector2f){180, 280});
    sfSprite_setScale(frame->beg1, (sfVector2f){0.3, 0.3});
    frame->options = create_sprite("./res/spr/frame2.png"
                                                , (sfVector2f){25, 1});
    sfSprite_setScale(frame->options, (sfVector2f){0.38, 0.34});
    frame->speak = create_sprite("./res/spr/frame3.png"
                                , (sfVector2f){7, win->win_size.y - 250});
    sfSprite_setScale(frame->speak, (sfVector2f){0.41, 0.41});
    frame->name = create_sprite("./res/spr/frame4.png", (sfVector2f){10, 10});
    sfSprite_setScale(frame->name, (sfVector2f){0.21, 0.21});
    return frame;
}

void setup_sprites_four(win_t *win)
{
    win->rain_sprite = malloc(sizeof(sfSprite *) * 2);
    win->x_collide = 0;
    for (int i = 0; i != 2; i++) {
        win->rain_sprite[i] = create_sprite("res/spr/rain.png",
        (sfVector2f){0, i == 0 ? 0 : -600});
        sfSprite_setScale(win->rain_sprite[i], (sfVector2f){4, 4});
    }
    win->y_collide = -10;
    win->moving_collide = create_sprite("res/spr/char_mini.png",
                                (sfVector2f){win->x_collide, win->y_collide});
    sfSprite_setTextureRect(win->moving_collide,
                                            (sfIntRect){9, 1540, 16, 14});
    sfSprite_setScale(win->moving_collide, (sfVector2f){4, 4});
    win->x_chen = 30;
    win->y_chen = -45;
    win->moving_chen = create_sprite("res/spr/char_mini.png",
                                (sfVector2f){win->x_chen, win->y_chen});
    sfSprite_setTextureRect(win->moving_chen,
                                            (sfIntRect){26, 170, 17, 16});
    return setup_sprites_five(win);
}

void setup_sprites_three(win_t *win)
{
    win->what_custo = 0;
    win->customise = malloc(sizeof(int) * win->nbr_custo);
    for (int i = 0; i != win->nbr_custo; win->customise[i] = i == 0 ? 34
    : i == 1 ? 85 : i == 2 ? 221 : i == 3 ? 238 : i == 4 ? 289 : i == 5
    ? 374 : i == 6 ? 391 : i == 7 ? 442 : i == 8 ? 476 : 1258, i++);
    win->player_sprite = create_sprite("res/spr/char_mini.png"
    , (sfVector2f){win->x_player, win->y_player});
    win->old_pos->y_labo = win->y_labo;
    win->player_rect = (sfIntRect){25, win->customise[win->what_custo], 17
    , 16};
    sfSprite_setTextureRect(win->player_sprite, win->player_rect);
    sfSprite_setScale(win->player_sprite, (sfVector2f){5, 5});
    win->player->player = create_sprite("res/spr/char_mini.png"
                                                    , (sfVector2f){80, 80});
    sfSprite_setTextureRect(win->player->player
                                            , (sfIntRect){24, 34, 18, 16});
    sfSprite_setScale(win->player->player, (sfVector2f){4, 4});
    win->grass_sprite = create_sprite("res/spr/leaf.png", (sfVector2f){0, 0});
    win->int_grass = 0;
    return setup_sprites_four(win);
}

void setup_sprites_two(win_t *win)
{
    win->old_pos->x_player = win->x_player;
    win->old_pos->y_map = win->y_map;
    win->old_pos->y_player = win->y_player;
    win->old_pos->x_collide = win->x_collide;
    win->old_pos->y_collide = win->y_collide;
    win->old_pos->x_chen = win->x_chen;
    win->old_pos->y_chen = win->y_chen;
    win->old_pos->x_labo = win->x_labo;
    win->start = create_sprite("./res/spr/start.jpeg", (sfVector2f){70, 50});
    sfSprite_setScale(win->start, (sfVector2f){0.75, 0.75});
    sfSprite_setTextureRect(win->map, (sfIntRect){win->x_map, win->y_map
    , 2000, 900});
    win->cursor = create_sprite("res/spr/select.png", (sfVector2f){55, 60});
    sfSprite_setTextureRect(win->cursor, (sfIntRect){0, 0, 10, 10});
    sfSprite_setScale(win->cursor, (sfVector2f){3, 3});
    win->chen = create_sprite("res/spr/trainers.png", (sfVector2f){260, 80});
    sfSprite_setTextureRect(win->chen, (sfIntRect){0, 235, 300, 265});
    sfSprite_setScale(win->chen, (sfVector2f){1, 1});
    win->nbr_custo = 10;
    setup_sprites_three(win);
}

void setup_sprites(win_t *win)
{
    win->volume = 1;
    win->nbr_obstacle = 0;
    win->nbr_grass = 0;
    win->grass = sfMusic_createFromFile("res/snd/grass.ogg");
    win->colide = sfMusic_createFromFile("res/snd/colide.ogg");
    sfMusic_setVolume(win->grass, win->volume == 0 ? 0 : 125);
    sfMusic_setVolume(win->colide, win->volume == 0 ? 0 : 25);
    win = create_obstacles(win);
    win = create_grass(win);
    win->path_map = my_strcpy("./res/map/pallet.png");
    win->map = create_sprite(win->path_map, (sfVector2f){0, 0});
    sfSprite_setScale(win->map, (sfVector2f){2.52, 1.92});
    win->piece = 0;
    win->x_map = 1168;
    win->y_map = 59;
    win->x_player = 406;
    win->y_player = 300;
    win->old_pos = malloc(sizeof(pos_t));
    win->old_pos->x_map = win->x_map;
    setup_sprites_two(win);
}
