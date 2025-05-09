/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** UIai
*/

#ifndef UIAI_HPP_
#define UIAI_HPP_
    #include <map>
    #include <iostream>
    #include <SFML/Graphics.hpp>

    class UIai {
         protected:
            void addStats(std::string, std::string, int);
            sf::Font _font;
            sf::RectangleShape _shape;
            std::map<std::string, sf::Text> _stats;
            bool isDisplay = false;
            sf::View _viewUI;

        public:
            UIai();
            ~UIai();
            void init(sf::Vector2f size, sf::Vector2f pos);
            void draw(sf::RenderWindow& window);
            void update(std::map<std::string, std::string> stats);
            void setIsDisplay(bool);
            void setPos(sf::Vector2f pos);
            void setView(sf::View &view);

            bool getIsDisplay() const;
            sf::Font getFont() const;
            sf::RectangleShape getShape() const;
            std::map<std::string, sf::Text> getStats() const;
            sf::View getView() const;
            bool getIsDisplay();
};

#endif /* !UIAI_HPP_ */
