/*
** EPITECH PROJECT, 2023
** main.cpp
** File description:
** no ideas
*/

#include <cstring>
#include "main.hpp"
#include <iostream>
#include <ncurses.h>
#include "NCurses/NcurseFile.hpp"
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

#define check_args(str, x, y) (((!strcmp(str, x) || !strcmp(str, y)) ? 1 : 0)

int doSfml()
{
    window();
    return 0;
}

int doNcruses(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    NcurseFile file;
    while (file.diplsayAll() != false);
    return 0;
}

int help(void){
    std::cout << "MyGKrellm project created with ncurses and csfml\n"
        << "USAGE\n"
        << "\t./MyGKrellm [-h/help] [-t/-text] [-g/-graphical]\n\n"
        << "GOAL OF THE PROJECT\n"
        << "\tImplement our version of GKrellM\n\n"
        << "OPTIONS\n"
        << "\t-h, --help\tPrint the usage and quit.\n"
        << "\t-t, --text\tThe monitor will be show on your terminal with ncurses.\n"
        << "\t-g, --graphical\tThe monitor will be show in a graphical window with SFML."
        << std::endl;
    return 0;
}

int main(int argc, char **argv)
{
    for (int i = 1; i != argc; i++) {
        if (check_args(argv[i], "-h", "--help") == 1)) {
            return help();
        } else if (check_args(argv[i], "-t", "--txt") == 1)) {
            return doNcruses(argc, argv);
        } else if (check_args(argv[i], "-g", "--graphical") == 1)) {
            return doSfml();
        }
    }
    return 84;
}
