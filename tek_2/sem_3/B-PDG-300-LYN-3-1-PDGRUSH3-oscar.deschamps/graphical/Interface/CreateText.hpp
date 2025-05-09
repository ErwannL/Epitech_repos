/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH3-oscar.deschamps
** File description:
** CreateText
*/

#ifndef CREATETEXT_HPP_
#define CREATETEXT_HPP_
    #include "info_block.hpp"

    class CreateText
    {
        public:
            CreateText(std::string string, sf::Vector2f pos, sf::Vector2f size);
            ~CreateText();
            sf::Text getText();
            sf::RectangleShape getRect();
            void updateText(std::string string) {text.setString(string);};
        private:
            sf::Font font;
            sf::Text text;
            sf::RectangleShape rec_back;
    };

#endif /* !CREATETEXT_HPP_ */
