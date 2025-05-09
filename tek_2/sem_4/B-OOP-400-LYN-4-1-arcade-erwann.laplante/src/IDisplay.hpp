/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** no idea
*/

#ifndef IDISPLAY_HPP_
    #define IDISPLAY_HPP_
    #include <memory>
    #include <cstdio>
    #include <dlfcn.h>
    #include <iostream>
    #include "Sprite.hpp"
    #include <utility>
    #include <map>

    class IDisplay {
        public:
            /* ============= Builders ============= */
            virtual ~IDisplay(void) = default;

            /* ============= Library ============= */
            virtual void clear(void) = 0;
            virtual void refresh(void) = 0;
            virtual void update(std::map<std::string, Sprite> &) = 0;

            /* ============= Window ============= */
            virtual void createWin(void) = 0;
            virtual void deleteWin(void) = 0;

            virtual bool manageEvent(void) = 0;
            virtual void checkCollide(std::map<std::string, Sprite> &) = 0;

            virtual void addSprite(Sprite &) = 0;
            virtual void drawSprites(std::map<std::string, Sprite> &) = 0;
            virtual std::pair<std::string, bool> getKey(void) = 0;
            virtual std::pair<int, int>getWindowBorders(void) = 0;

            /* ============= Extra ============= */
            virtual std::string getName(void) const = 0;
    };
#endif
