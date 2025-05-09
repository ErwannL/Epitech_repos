/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Tiles
*/

#ifndef TILES_HPP_
    #define TILES_HPP_
    #include "UIai.hpp"
    #include <memory>
    #include "SpriteFactory.hpp"

    class Tile {
        public:
            Tile(sf::Sprite sprite, sf::Text txt);
            ~Tile();
            void update();
            void animate(int currentFrame);
            void setInventory(std::map<std::string, sf::Sprite>);
            void setSprite(sf::Sprite sprite);
            void setPos(sf::Vector2f pos);
            void setTexture(sf::Texture texture);
            void setSpriteName(std::string spriteName);
            void displayUI(sf::RenderWindow&);
            void drawInventory(sf::RenderWindow&);
            std::map<std::string, sf::Sprite> getInventory() const;
            void popResource(std::string);
            void addResource(std::string);
            sf::Sprite getSprite() const;
            sf::Vector2f getPos() const {};
            UIai getUI() const;

            void draw(sf::RenderWindow &window);
        protected:
            std::map<std::string, sf::Sprite> _inventory;
            sf::Sprite _sprite;
            sf::Texture _texture;
            std::string _spriteName;
            sf::Vector2f _pos;
            UIai ui;
            sf::Font font;
            sf::Text text;
            bool drawing = true;
    };

#endif /* !TILES_HPP_ */
