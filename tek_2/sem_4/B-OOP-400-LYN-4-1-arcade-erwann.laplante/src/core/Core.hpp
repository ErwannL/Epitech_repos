/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-erwann.laplante
** File description:
** IArcade
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

    #include "IArcade.hpp"
    #include <iostream>
    #include <dlfcn.h>
    #include <memory>
    #include <tuple>
    #include "IGame.hpp"
    #include "Graphicals.hpp"

    namespace Arcade {
        class Core {
            public:
                Core();
                ~Core();

                void addGraphicalLib(std::string);
                void addGameLib(std::string);

                std::vector<std::string> getGraphicalLib(void) const;
                std::vector<std::string> getGameLib(void) const;

            private:
                std::vector<std::string> graphical_lib;
                std::vector<std::string> game_lib;
            protected:
        };
    };

#endif /* !CORE_HPP_ */
