/*
** EPITECH PROJECT, 2023
** illegale_rush_3
** File description:
** window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include "Interface/info_block.hpp"
    #include <iostream>
    #include <math.h>
    #include <list>
    #include "Interface/sub_interface.hpp"
    #include "../IMonitorDisplay.hpp"
    #include <string>
    #include <sstream>
    int window();

    class var
    {
        public:
            var(){};
            ~var(){};
            float value;
            int display;
            sf::Event event;
            sf::Time elapsed1;
            sf::Clock clock;
    };
#endif /* !WINDOW_HPP_ */
