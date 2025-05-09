/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** setup
*/

#include "my_rpg.h"

void create_sounds(win_t *win, char *what)
{
    win->bgm = sfMusic_createFromFile(what);
    sfMusic_play(win->bgm);
    sfMusic_setLoop(win->bgm, sfTrue);
    sfMusic_setVolume(win->bgm, win->volume == 0 ? 0 : 25);
}

sfSprite *create_sprite(char *what, sfVector2f where)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(what, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, where);
    return sprite;
}

btn_t *create_button(sfVector2f size, sfVector2f pos, char *sprite, int i)
{
    btn_t *btn = malloc(sizeof(btn_t));

    btn->size = size;
    btn->pos = pos;
    btn->sprite = create_sprite(sprite, pos);
    btn->color = (sfColor){255, 255, 255, 200};
    (i == 0 ? sfSprite_setScale(btn->sprite, (sfVector2f){0.64, 0.64}) : 0);
    sfSprite_setColor(btn->sprite, btn->color);
    return btn;
}

sfText *create_font(win_t *win, int size, sfVector2f where, char *what)
{
    sfText *txt = sfText_create();
    sfSprite *box_action = sfSprite_copy(win->frame->speak);
    sfSprite_setPosition(win->frame->speak, (sfVector2f){10, 365});
    sfSprite_setPosition(box_action, (sfVector2f){390, 395});
    sfSprite_setScale(box_action, (sfVector2f){0.20, 0.30});
    sfText_setFont(txt, win->font);
    sfText_setColor(txt, sfBlack);
    sfText_setCharacterSize(txt, size);
    sfText_setPosition(txt, where);
    sfText_setString(txt, what);
    return txt;
}

void create_things(win_t *win)
{
    win->win_size = (sfVector2u){800, 600};
    win->font = sfFont_createFromFile("./res/font.ttf");
    create_window(win, win->win_size.x, win->win_size.y);
    win->hit_btn = sfSound_create();
    sfSound_setBuffer(win->hit_btn
                        , sfSoundBuffer_createFromFile("./res/snd/press.ogg"));
    win->frame = setup_frame(win);
    win->step = STATE_HTP;
    win->old_step = STATE_HTP;
    win->cursor_limit = 0;
    win->clock_fight = sfClock_create();
    win->player->name = NULL;
    create_allcapa(win);
    create_poke(win);
    create_trainers(win);
    setup_opts(win, 0);
    setup_sprites(win);
    refresh_sound(win);
    create_fights(win);
    win->action = 0;
}
