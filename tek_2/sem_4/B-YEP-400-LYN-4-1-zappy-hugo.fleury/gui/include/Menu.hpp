/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_
    #include "IScene.hpp"

    class Menu : virtual public IScene {
        public:
            Menu();
            ~Menu();
            void init(sf::RenderWindow &, std::shared_ptr<Client> &);
            void update(std::shared_ptr<Client> &, sf::RenderWindow &);
            void animation(int);
            void draw(sf::RenderWindow &);
            void handleEvent(sf::Event &, sf::RenderWindow &);
            void addSprite(std::string, sf::Sprite);
            void addButton(Button &);
            void setName(std::string name){_name = name;};
            void setSpriteMap(std::string);
            std::map<std::string, sf::Sprite> &getSpritesMap(){return _spritesMap;};
            int getSwitchScene();
            void timeUpdate(std::shared_ptr<Client> &){};
        protected:
            std::string map = "ZZZ\n";
            std::map<std::string, sf::Sprite> _spritesMap;
            std::map<std::string, sf::Texture> _textureMap;
            std::map<std::string, Button> _buttonsMap;
            sf::Font _font;
            std::string _name;
            int _switchScene = 1;
        private:
    };

#endif /* !MENU_HPP_ */
