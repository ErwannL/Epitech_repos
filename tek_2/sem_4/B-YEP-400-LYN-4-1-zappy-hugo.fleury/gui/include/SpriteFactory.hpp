/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** SpriteFactory
*/

#ifndef SPRITEFACTORY_HPP_
#define SPRITEFACTORY_HPP_
    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <map>

    class SpriteFactory {
        public:
            SpriteFactory();
            ~SpriteFactory();
            static sf::Sprite createSprite(std::string name, sf::Vector2f pos);

        protected:
            std::map<std::string, sf::IntRect> _rectMap;
        private:
    };

#endif /* !SPRITEFACTORY_HPP_ */
