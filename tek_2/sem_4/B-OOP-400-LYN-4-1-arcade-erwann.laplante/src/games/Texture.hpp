/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <iostream>
#include <vector>
#include <utility>

class Texture {
    protected:
        std::string _path;
        int _xPos;
        int _yPos;
        int _xSize;
        int _ySize;
        std::string _symbol;
    public:
        Texture(std::string, std::string, std::pair<int, int>, std::pair<int, int>);
        ~Texture();

        std::string getPath(void) const;
        int getxSize(void) const;
        int getySize(void) const;
        int getxPos(void) const;
        int getyPos(void) const;
        std::pair<float, float> getOrigin(void) const;
        std::string getPath(void) { return (this->_path); };
        std::string getSymbol(void) const;

        void setOrigin(float, float);
        std::pair<float, float> _origin = {0,0};

        Texture& operator=(const Texture& copy) {
            _path = copy.getPath();
            _xPos = copy.getxPos();
            _yPos = copy.getyPos();
            _symbol = copy.getSymbol();
            _xSize = copy.getxSize();
            _ySize = copy.getyPos();
            return *this;
        }
};

#endif /* !TEXTURE_HPP_ */
