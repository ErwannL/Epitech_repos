/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** text_bis
*/

#include "../include/my.h"

sfText *setup_settings(var_t *var, int x, int y, char *text)
{
    sfVector2f position = {x, y};

    var->text = sfText_create();
    sfText_setFont(var->text, var->font);
    sfText_setColor(var->text, sfBlack);
    sfText_setCharacterSize(var->text, 40);
    sfText_setString(var->text, text);
    sfText_setPosition(var->text, position);
    return var->text;
}

sfText *setup_game(var_t *var, int x, int y, char *text)
{
    sfVector2f position = {x, y};

    var->text = sfText_create();
    sfText_setFont(var->text, var->font);
    sfText_setColor(var->text, sfBlack);
    sfText_setCharacterSize(var->text, 50);
    sfText_setString(var->text, text);
    sfText_setPosition(var->text, position);
    return var->text;
}

sfText *setup_wait(var_t *var, int x, int y)
{
    sfVector2f position = {x, y};
    char *text = int_to_str(10 - var->second_unbug_menu);

    var->text = sfText_create();
    sfText_setFont(var->text, var->font);
    sfText_setColor(var->text, sfWhite);
    sfText_setCharacterSize(var->text, 100);
    sfText_setString(var->text, text);
    sfText_setPosition(var->text, position);
    return var->text;
}
