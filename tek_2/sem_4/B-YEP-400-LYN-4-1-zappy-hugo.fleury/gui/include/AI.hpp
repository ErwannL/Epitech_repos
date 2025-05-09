/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_
    #include "UIai.hpp"
    #include <memory>

    class AI {
        public:
            AI(sf::Sprite, sf::Font);
            ~AI();

            void update();
            void animate(int currentFrame);
            void setInventory(std::map<std::string, std::string> inventory);
            void setSprite(sf::Sprite sprite);
            void setLevel(std::string level);
            void setPos(sf::Vector2f pos);
            void setTeamName(std::string teamName);
            void setTexture(sf::Texture texture);
            void setSpriteName(std::string spriteName);
            void displayUI(sf::RenderWindow&);
            std::map<std::string, std::string> getInventory() const;
            sf::Sprite getSprite() const;
            sf::Text getLevel() const;
            sf::Vector2f getPos() const;
            std::string getTeamName() const;
            UIai getUI() const;
            int getId() const;
            void setId(int);

            void draw(sf::RenderWindow &window);

        protected:
            int id;
            std::map<std::string, std::string> _inventory;
            sf::Sprite _sprite;
            sf::Texture _texture;
            sf::Text level;
            std::string _spriteName;
            sf::Vector2f _pos;
            std::string _teamName;
            UIai ui;
        private:
    };

#endif /* !AI_HPP_ */
