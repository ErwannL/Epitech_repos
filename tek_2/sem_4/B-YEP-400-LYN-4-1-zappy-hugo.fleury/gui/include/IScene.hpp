/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_
    #include <map>
    #include <memory>
    #include <iostream>
    #include "Button.hpp"
    #include <string>
    #include "SpriteFactory.hpp"
    #include "AI.hpp"
    #include "Client.hpp"

    class IScene {
        public:
            virtual ~IScene() = default;
            virtual void update(std::shared_ptr<Client> &, sf::RenderWindow &) = 0;
            virtual void animation(int) = 0;
            virtual void draw(sf::RenderWindow &) = 0;
            virtual void handleEvent(sf::Event &, sf::RenderWindow &) = 0;
            virtual void init(sf::RenderWindow &, std::shared_ptr<Client> &) = 0;
            virtual void addSprite(std::string, sf::Sprite) = 0;
            virtual void addButton(Button &) = 0;
            virtual void setName(std::string) = 0;
            virtual void setSpriteMap(std::string) = 0;
            virtual std::map<std::string, sf::Sprite> &getSpritesMap() = 0;
            virtual int getSwitchScene() = 0;
            virtual void timeUpdate(std::shared_ptr<Client> &client) = 0;

        protected:
        private:
    };
#endif /* !ISCENE_HPP_ */
