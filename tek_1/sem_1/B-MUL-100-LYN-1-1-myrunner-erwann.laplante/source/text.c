/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** text
*/

#include"../includes/my.h"

sfText *setup_font(var_t var)
{
    var.text = sfText_create();
    var.font = sfFont_createFromFile("font/Astral Sisters.ttf");
    sfText_setFont(var.text, var.font);
    sfText_setColor(var.text, sfBlack);
    sfText_setCharacterSize(var.text, 50);
    var.vec.x = 600;
    var.vec.y = 50;
    sfText_setString(var.text, int_to_str(var.score));
    sfText_setPosition(var.text, var.vec);
    return var.text;
}

sfText *setup_score(var_t var)
{
    sfText *txt = sfText_create();

    var.font = sfFont_createFromFile("font/Astral Sisters.ttf");
    sfText_setFont(txt, var.font);
    sfText_setColor(txt, sfBlack);
    sfText_setCharacterSize(txt, 50);
    var.vec.x = 400;
    var.vec.y = 50;
    sfText_setString(txt, "Your score : ");
    sfText_setPosition(txt, var.vec);
    return txt;
}

sfText *setup_score_max(var_t var, int n)
{
    sfText *txt = sfText_create();

    var.font = sfFont_createFromFile("font/Astral Sisters.ttf");
    sfText_setFont(txt, var.font);
    sfText_setColor(txt, sfBlack);
    sfText_setCharacterSize(txt, 50);
    if (n == 0) {
        var.vec.x = 400;
        var.vec.y = 50;
    } else {
        var.vec.x = 400;
        var.vec.y = 150;
    }
    sfText_setString(txt, "Best score : ");
    sfText_setPosition(txt, var.vec);
    return txt;
}

sfText *setup_font_max(var_t var, int n)
{
    char *buf = malloc(sizeof(char) * 11);
    int fd;

    fd = open("score/score_max.txt", O_RDONLY);
    read(fd, buf, 10);
    close(fd);
    buf[10] = '\0';
    while (buf[0] == '0' && my_strlen(buf) != 1)
        buf++;
    var.text = sfText_create();
    var.font = sfFont_createFromFile("font/Astral Sisters.ttf");
    sfText_setFont(var.text, var.font);
    sfText_setColor(var.text, sfBlack);
    sfText_setCharacterSize(var.text, 50);
    (n == 0) ? (var.vec.x = 600, var.vec.y = 50) :
    (var.vec.x = 600, var.vec.y = 150);
    sfText_setString(var.text, buf);
    sfText_setPosition(var.text, var.vec);
    return var.text;
}

sfText *setup_lose(var_t var)
{
    sfText *txt = sfText_create();

    var.font = sfFont_createFromFile("font/Astral Sisters.ttf");
    sfText_setFont(txt, var.font);
    sfText_setColor(txt, sfBlack);
    sfText_setCharacterSize(txt, 50);
    var.vec.x = 300;
    var.vec.y = 300;
    sfText_setString(txt, "You lose !\nPresse SPACE to exit");
    sfText_setPosition(txt, var.vec);
    return txt;
}
