/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** create_poke
*/

#include "my_rpg.h"

poke_t create_carapuce(win_t *win)
{
    poke_t salameche;

    salameche.name = create_font(win, 20
                    , (sfVector2f){200, 100}, "salameche");
    salameche.sprite_front = create_sprite("res/spr/pokemon.png"
                                            , (sfVector2f){540, 50});
    sfSprite_setTextureRect(salameche.sprite_front
                                            , (sfIntRect){1034, 30});
    sfSprite_setScale(salameche.sprite_front, (sfVector2f){4, 4});
    salameche.sprite_back = create_sprite("res/spr/pokemon.png"
                                            , (sfVector2f){80, 180});
    sfSprite_setTextureRect(salameche.sprite_back
                                        , (sfIntRect){518, 144, 50, 50});
    sfSprite_setScale(salameche.sprite_back, (sfVector2f){4, 4});
    salameche = set_capa(salameche, win->ember, win->leer, win->tackle);
    salameche = set_statbulbi(salameche, win);
    win->change = 0;
    return (salameche);
}

poke_t create_salameche(win_t *win)
{
    poke_t salameche;

    salameche.name = create_font(win, 20
                    , (sfVector2f){200, 100}, "salameche");
    salameche.sprite_front = create_sprite("res/spr/pokemon.png"
                                            , (sfVector2f){540, 50});
    sfSprite_setTextureRect(salameche.sprite_front
                                            , (sfIntRect){519, 29, 42});
    sfSprite_setScale(salameche.sprite_front, (sfVector2f){4, 4});
    salameche.sprite_back = create_sprite("res/spr/pokemon.png"
                                            , (sfVector2f){80, 180});
    sfSprite_setTextureRect(salameche.sprite_back
                                        , (sfIntRect){519, 29, 50});
    sfSprite_setScale(salameche.sprite_back, (sfVector2f){4, 4});
    salameche = set_capa(salameche, win->ember, win->leer, win->tackle);
    salameche = set_statbulbi(salameche, win);
    win->change = 0;
    return (salameche);
}

poke_t create_pikachu(win_t *win)
{
    poke_t pikachu;

    pikachu.name = create_font(win, 20
                    , (sfVector2f){200, 100}, "Pikachu");
    pikachu.sprite_front = create_sprite("res/spr/pokemon.png"
                                            , (sfVector2f){540, 50});
    sfSprite_setTextureRect(pikachu.sprite_front
                                            , (sfIntRect){690, 409, 42, 42});
    sfSprite_setScale(pikachu.sprite_front, (sfVector2f){4, 4});
    pikachu.sprite_back = create_sprite("res/spr/pokemon.png"
                                            , (sfVector2f){80, 180});
    sfSprite_setTextureRect(pikachu.sprite_back
                                        , (sfIntRect){690, 517, 50, 50});
    sfSprite_setScale(pikachu.sprite_back, (sfVector2f){4, 4});
    pikachu = set_capa(pikachu, win->thunder, win->leer, win->tackle);
    pikachu = set_statpika(pikachu, win);
    return (pikachu);
}

poke_t create_bulbizare(win_t *win)
{
    poke_t bulbizare;
    bulbizare.name = create_font(win, 20
                    , (sfVector2f){100, 100}, "Bulbizarre");
    bulbizare.sprite_front = create_sprite("res/spr/pokemon.png"
                                                    , (sfVector2f){540, 50});
    sfSprite_setTextureRect(bulbizare.sprite_front
                                            , (sfIntRect){0, 34, 41, 36});
    sfSprite_setScale(bulbizare.sprite_front, (sfVector2f){4, 4});
    bulbizare.sprite_back = create_sprite("res/spr/pokemon.png"
                                                    , (sfVector2f){80, 180});
    sfSprite_setTextureRect(bulbizare.sprite_back
                                            , (sfIntRect){8, 148, 47, 40});
    sfSprite_setScale(bulbizare.sprite_back, (sfVector2f){4, 4});
    set_capa(bulbizare, win->vine_whip, win->leer, win->tackle);
    bulbizare.lvl = 5;
    bulbizare.hp_max = 50;
    bulbizare = set_statbulbi(bulbizare, win);
    bulbizare.xp = 0;
    return (bulbizare);
}

void create_poke(win_t *win)
{
    win->pikachu = create_pikachu(win);
    win->bulbizare = create_bulbizare(win);
    win->salameche = create_salameche(win);
}
