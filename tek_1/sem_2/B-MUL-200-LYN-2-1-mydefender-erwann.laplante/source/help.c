/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-erwann.laplante
** File description:
** help
*/

#include "../include/my.h"

void print_h_bis(void)
{
    my_putstr("-                  Decrease volume sound.\n");
    my_putstr("P                  Go to pause menu in game.\n");
    my_putstr("SPACE              In pause menu, quit pause menu and return ");
    my_putstr("to game & in settings menu, quit settings and return to menu.");
    my_putstr("\n");
    my_putstr("TAB                Skip the intro.\n");
    my_putstr("M                  Go to menu from game.\n");
    my_putstr("B                  Go to building menu from settings menu or ");
    my_putstr("pause menu.\n");
    my_putstr("H                  Go to How to play menu from settings menu ");
    my_putstr("or pause menu.\n");
    my_putstr("ENTER              Return to settings menu or pause menu from");
    my_putstr(" building menu or how to play menu.\n");
    my_putstr("NUMBER 1 TO 4      Select what building place in build menu");
}

void print_h(void)
{
    my_putstr("Finite defender created with CSFML.\n");
    my_putstr("\n");
    my_putstr("USAGE\n");
    my_putstr("./defender\n");
    my_putstr("\n");
    my_putstr("GOAL OF THE GAME\n");
    my_putstr("The player must defend his castle by placing defenses to kill");
    my_putstr(" ennemy. If the castle reaches 0 hp. the player has lost.\n");
    my_putstr("\n");
    my_putstr("OPTIONS\n");
    my_putstr("-h     Print the usage and STAT_QUIT.\n");
    my_putstr("\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("MOUSE CLICK        In main menu, select start button, setti");
    my_putstr("ng button or quit button.\n");
    my_putstr("ESCAPE             Quit the game from anywhere.\n");
    my_putstr("F                  Cute the music sound.\n");
    my_putstr("N                  Restart the music sound.\n");
    my_putstr("+                  Increase volume sound.\n");
    print_h_bis();
}
