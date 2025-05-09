/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Button
*/

#include "Button.hpp"

Button::Button(sf::RectangleShape rect, sf::Vector2f pos, sf::Text txt, std::string name)
{
    _RectShape = rect;
    _RectShape.setFillColor(sf::Color::Red);
    _RectShape.setPosition(pos);
    _RectShape.setOutlineThickness(2);
    _text = txt;

    _defaultColor = _RectShape.getFillColor();
    sf::FloatRect textBounds = _text.getLocalBounds();
    _text.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
    _text.setPosition(_RectShape.getPosition().x + _RectShape.getSize().x / 2, _RectShape.getSize().y + _RectShape.getSize().y / 2);

    _text.setPosition(_RectShape.getPosition().x + _RectShape.getSize().x/2 - txt.getCharacterSize()/2, _RectShape.getPosition().y + _RectShape.getSize().y/2);
    this->_name = name;
}


Button::~Button()
{
}

std::string Button::getName() const
{
    return this->_name;
}

sf::RectangleShape Button::getRectShape() const
{
    return this->_RectShape;
}

sf::Text Button::getText() const
{
    return this->_text;
}

void Button::setIsClick(bool click)
{
    if (click == true)
        _RectShape.setFillColor(sf::Color::Black);
    if (click == false)
        _RectShape.setFillColor(_defaultColor);
    this->isClick = click;
}

void Button::setColor(sf::Color color)
{
    _defaultColor = color;
    _RectShape.setFillColor(color);
}