/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** create_capa
*/

#include "my_rpg.h"

sfText *create_text(win_t *win, int size, sfVector2f where, char *what)
{
    sfText *txt = sfText_create();
    sfText_setFont(txt, win->font);
    sfText_setColor(txt, sfBlack);
    sfText_setCharacterSize(txt, size);
    sfText_setPosition(txt, where);
    sfText_setString(txt, what);
    return txt;
}

poke_t set_capa(poke_t poke, capa_t capa1, capa_t capa2, capa_t capa3)
{
    poke.capa1.name = sfText_copy(capa1.name);
    poke.capa1.dmg = capa1.dmg;
    poke.capa1.type = capa1.type;
    poke.capa2.name = sfText_copy(capa2.name);
    poke.capa2.dmg = capa2.dmg;
    poke.capa2.type = capa2.type;
    poke.capa3.name = sfText_copy(capa3.name);
    poke.capa3.dmg = capa3.dmg;
    poke.capa3.type = capa3.type;
    return (poke);
}

capa_t create_capa(sfText *txt, int dmg, int type)
{
    capa_t capa;
    capa.name = sfText_copy(txt);
    capa.dmg = dmg;
    capa.type = type;
    return (capa);
}

void create_allcapa(win_t *win)
{
    win->thunder = create_capa(create_text(win, 20, (sfVector2f){422, 459}
    , "thunder"), 2, ELECK);
    win->leer = create_capa(create_text(win, 20, (sfVector2f){419, 528}
    , "leer"), 0, NORMAL);
    win->vine_whip = create_capa(create_text(win, 20, (sfVector2f){422, 459}
    , "vine_whip"), 2, GRASS);
    win->ember = create_capa(create_text(win, 20, (sfVector2f){422, 459}
    , "ember"), 2, FIRE);
    win->water_gun = create_capa(create_text(win, 20, (sfVector2f){422, 459}
    , "water_gun"), 2, WATER);
    win->tackle = create_capa(create_text(win, 20, (sfVector2f){598, 458}
    , "tackle"), 1, NORMAL);
}
