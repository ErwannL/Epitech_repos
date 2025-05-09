/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** declaration
*/

#include"../includes/my.h"

var_t dec_var5(var_t var)
{
    sfSprite_setTextureRect(var.sprite_bat2, var.bat2);
    sfSprite_setTexture(var.sprite_bat3, var.texture_bat3, sfTrue);
    sfSprite_setTextureRect(var.sprite_bat3, var.bat3);
    sfSprite_setTexture(var.sprite_bat4, var.texture_bat4, sfTrue);
    sfSprite_setTextureRect(var.sprite_bat4, var.bat4);
    sfSprite_setTexture(var.sprite_bat5, var.texture_bat5, sfTrue);
    sfSprite_setTextureRect(var.sprite_bat5, var.bat5);
    var.sprite_bat5 = create_sprite(var.x_bat5, var.y_bat5,
    "pictures/bat.png", 1);
    var.exit_nbr = 0;
    var.speed_bat = 150;
    var.r_nbr = 0;
    var.size.x = var.mode.width;
    var.size.y = var.mode.height;
    var.position.x = 100;
    var.position.y = 100;
    var.etat = 0;
    var.texture_cloud3 = sfTexture_create(800, 600);
    var.sprite_cloud3 = sfSprite_create();
    return dec_var6(var);
}

var_t dec_var4(var_t var)
{
    var.texture_bat = sfTexture_create(70, 50);
    var.texture_bat2 = sfTexture_create(70, 50);
    var.texture_bat3 = sfTexture_create(70, 50);
    var.texture_bat4 = sfTexture_create(70, 50);
    var.texture_bat5 = sfTexture_create(70, 50);
    var.sprite_bird = sfSprite_create();
    var.sprite_cloud = sfSprite_create();
    var.sprite_bat = sfSprite_create();
    var.sprite_bat2 = sfSprite_create();
    var.sprite_bat3 = sfSprite_create();
    var.sprite_bat4 = sfSprite_create();
    var.sprite_bat5 = sfSprite_create();
    sfSprite_setTexture(var.sprite_bird, var.texture_bird, sfTrue);
    sfSprite_setTextureRect(var.sprite_bird, var.bird);
    sfSprite_setTexture(var.sprite_cloud, var.texture_cloud, sfTrue);
    sfSprite_setTextureRect(var.sprite_cloud, var.cloud);
    sfSprite_setTexture(var.sprite_bat, var.texture_bat, sfTrue);
    sfSprite_setTextureRect(var.sprite_bat, var.bat);
    sfSprite_setTexture(var.sprite_bat2, var.texture_bat2, sfTrue);
    return dec_var5(var);
}

var_t dec_var3(var_t var)
{
    var.bat2.height = 50;
    var.bat2.width = 70;
    var.bat2.top = 0;
    var.bat2.left = 0;
    var.bat3.height = 50;
    var.bat3.width = 70;
    var.bat3.top = 0;
    var.bat3.left = 0;
    var.bat4.height = 50;
    var.bat4.width = 70;
    var.bat4.top = 0;
    var.bat4.left = 0;
    var.bat5.height = 50;
    var.bat5.width = 70;
    var.bat5.top = 0;
    var.bat5.left = 0;
    sfRenderWindow_setFramerateLimit(var.window, 144);
    var.texture_bird = sfTexture_create(53, 52);
    var.texture_cloud = sfTexture_create(800, 600);
    return dec_var4(var);
}

var_t dec_var2(var_t var)
{
    var.x_bat3 = 800 + rand() % 540;
    var.y_bat3 = rand() % 540;
    var.x_bat4 = 800 + rand() % 540;
    var.y_bat4 = rand() % 540;
    var.x_bat5 = 800 + rand() % 540;
    var.y_bat5 = rand() % 540;
    var.clock_bird = sfClock_create();
    var.clock_bat = sfClock_create();
    var.clock_speed = sfClock_create();
    var.clock_cloud = sfClock_create();
    var.choice_bird != 0 && var.choice_bird != 1 && var.choice_bird != 2
    && var.choice_bird != 3 ? var.choice_bird = 0 : 0;
    var.bird.height = 100;
    var.bird.width = 98;
    var.bird.top = var.choice_bird * 100;
    var.bird.left = 0;
    var.bat.height = 50;
    var.bat.width = 70;
    var.bat.top = 0;
    return dec_var3(var);
}

var_t dec_var(var_t var)
{
    var.volume > 100 || var.volume < 0 ? var.volume = 10 : 0;
    var.mode.width = 800;
    var.mode.height = 600;
    var.mode.bitsPerPixel = 32;
    var.window = sfRenderWindow_create(var.mode, "My Runner", sfClose |
    sfResize, NULL);
    var.x_bird = 10;
    var.y_bird = 300;
    var.x_cloud = 0;
    var.y_cloud = 0;
    var.x_cloud2 = 800;
    var.y_cloud2 = 0;
    var.pos_cloud2.x = var.x_cloud2;
    var.pos_cloud2.y = var.y_cloud2;
    var.x_bat = 800;
    var.y_bat = rand() % 540;
    var.clock_sun = sfClock_create();
    var.x_bat2 = 800;
    var.y_bat2 = rand() % 540;
    return dec_var2(var);
}
