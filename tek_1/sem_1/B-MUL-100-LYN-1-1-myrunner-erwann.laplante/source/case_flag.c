/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** case_flag
*/

#include"../includes/my.h"

void case_null(int ac)
{
    if (ac < 2) {
        my_putstr("./my_runner: bad arguments: 0 given but 1 is required\nre");
        my_putstr("try with -h\n");
    } else {
        my_putstr("./my_runner: too many arguments: 1 is required\nretry wit");
        my_putstr("h -h\n");
    }
}

void case_h_bis(void)
{
    my_putstr("sound.\n P                   in menu acced to parameter.\n M ");
    my_putstr("                  go back in main menu.\n NUMBER 1 to 2      ");
    my_putstr(" select level.\n N                   go from main menu to lev");
    my_putstr("el menu.\n");
}

void case_h(void)
{
    my_putstr("Finite runner created with CSFML.\n\nUSAGE\n ./my_runner map.");
    my_putstr("txt\n\nGOAL OF THE GAME\n On the levels, the player must reac");
    my_putstr("h the finish line without touching the bats.\n In infinite mo");
    my_putstr("de, the player must go as far as possible without touching th");
    my_putstr("e bats.\n\nOPTIONS\n -i     launch the game in infinity mode.");
    my_putstr("\n -h     print the usage and quit.\n -m     play the game in");
    my_putstr(" menu mode.\n\nUSER INTERACTIONS\n ARROW_UP            go up.");
    my_putstr("\n ARROW_DOWN          go down.\n ENTER               in main");
    my_putstr(" menu go to game and in game make a jump to the bird.\n SPACE");
    my_putstr("               in game go in pause menu and in end screen go ");
    my_putstr("back in main menu.\n TAB                 exit from the pause ");
    my_putstr("menu, exit from the settings or exit from the level menu.\n N");
    my_putstr("UMBER 1 to 4       select bird color (white, gray, blue or gr");
    my_putstr("een) in pause or setting menu.\n ESCAPE              close th");
    my_putstr("e window.\n MOUSE               click to start, to go in leve");
    my_putstr("l menu, to go in setting or to exit settings or pause menu.\n");
    my_putstr(" F                   cute the music sound.\n N               ");
    my_putstr("    restart the music sound.\n +                   increases ");
    my_putstr("the volume sound.\n -                   decreases the volume ");
    case_h_bis();
}
