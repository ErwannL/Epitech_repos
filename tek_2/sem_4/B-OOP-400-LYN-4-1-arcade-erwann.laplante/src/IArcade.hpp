/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-erwann.laplante
** File description:
** IArcade
*/

#ifndef IARCADE_HPP_
    #define IARCADE_HPP_

    #include <iostream>
    #include <dlfcn.h>
    #include <memory>
    #include <string>
    #include <cstring>
    #include <vector>
    #include <filesystem>

    namespace Arcade {
        enum Type {
            Uknown = -1,
            Game,
            Graphical
        };

        class Core;
        class Games;
        class Graphicals;
    };

#endif /* !IARCADE_HPP_ */
