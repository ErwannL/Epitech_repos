/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-allan.branco
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
    #define SPRITE_HPP_

    #include "Texture.hpp"
    #include <vector>
    #include <utility>

    class Sprite {
        protected:
            std::string _name;
            int _xPos;
            int _yPos;
            std::vector<Texture> _texture;
            std::pair <std::string, int> _collide;
            int _facing = 4;

        public:
            Sprite(std::string, int, int, Texture &);
            ~Sprite();
            std::string getName(void) const;
            int getxPos(void) const;
            int getyPos(void) const;
            int getFacing(void) const;
            std::vector<Texture> getTexture(void) const;
            std::pair<std::string, int> getCollide() const;

            void setPos(std::pair<int, int>);
            void setCollide(std::pair<std::string, int>);
            void setFacing(int);
            void setTextureOrigin(float, float);

            Sprite& operator=(const Sprite& copy) {
                _name = copy.getName();
                _xPos = copy.getxPos();
                _yPos = copy.getyPos();
                _collide = copy.getCollide();
                _texture = copy.getTexture();
                return *this;
            }
    };

#endif /* !SPRITE_HPP_ */
