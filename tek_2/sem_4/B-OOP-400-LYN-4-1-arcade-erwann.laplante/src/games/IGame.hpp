/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** no idea
*/

#ifndef IGAME_HPP_
    #define IGAME_HPP_
    #include <memory>
    #include <cstdio>
    #include <dlfcn.h>
    #include <iostream>
    #include <map>
    #include "Sprite.hpp"
    #include <chrono>
    #include <utility>

    class IGame {
        public:
            /* ============= Builders ============= */
            virtual ~IGame(void) = default;

            /* ============= Library ============= */
            virtual void reset(void) = 0;
            virtual void update(void) = 0;
            virtual std::map<std::string, Sprite> &getMapSprite(void) = 0;
            virtual void setInput(std::pair<std::string, bool>) = 0;
    };
#endif
