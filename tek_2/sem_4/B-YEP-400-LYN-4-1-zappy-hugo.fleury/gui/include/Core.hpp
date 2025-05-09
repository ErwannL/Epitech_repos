/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
    #include <memory>
    #include <iostream>
    #include "Menu.hpp"
    #include "Game.hpp"
    #include "Client.hpp"
    #include "Camera.hpp"
    #include "WindowSFML.hpp"

     enum Scene {
        NONE,
        MENU,
        GAME,
        END
    };

    class Core {
        private:
            std::shared_ptr<Client> client = nullptr;

        public:
            ~Core(void) {};
            Core(std::shared_ptr<Client> client) : client(client) {};

            void run(void);
    };

#endif /* !CORE_HPP_ */
