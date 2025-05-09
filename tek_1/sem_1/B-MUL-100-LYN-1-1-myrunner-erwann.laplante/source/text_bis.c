/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** text_bis
*/

#include "../includes/my.h"

sfText *setup_win(var_t var)
{
    sfText *txt = sfText_create();

    var.font = sfFont_createFromFile("font/Astral Sisters.ttf");
    sfText_setFont(txt, var.font);
    sfText_setColor(txt, sfBlack);
    sfText_setCharacterSize(txt, 50);
    var.vec.x = 300;
    var.vec.y = 300;
    sfText_setString(txt, "You win !\nPresse SPACE to exit");
    sfText_setPosition(txt, var.vec);
    return txt;
}

sfText *setup_level(var_t var)
{
    sfText *txt = sfText_create();

    var.font = sfFont_createFromFile("font/Astral Sisters.ttf");
    sfText_setFont(txt, var.font);
    sfText_setColor(txt, sfBlack);
    sfText_setCharacterSize(txt, 50);
    var.vec.x = 225;
    var.vec.y = 150;
    sfText_setString(txt, "Press 1 or 2  to play\n");
    sfText_setPosition(txt, var.vec);
    return txt;
}
