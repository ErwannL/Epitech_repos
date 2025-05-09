/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** UIai
*/

#include "UIai.hpp"

UIai::UIai()
{
}

UIai::~UIai()
{
}

void UIai::init(sf::Vector2f size, sf::Vector2f pos)
{
    _shape.setSize(size);
    _shape.setFillColor(sf::Color::Black);
    _shape.setOutlineColor(sf::Color::White);
    _shape.setOutlineThickness(2);
    setPos(pos);
    if (!_font.loadFromFile("gui/assets/Minecraft.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
}

void UIai::addStats(std::string key, std::string ele, int Csize)
{
    sf::Text text;
    text.setString(ele);
    text.setPosition(_shape.getPosition().x + 10, _shape.getPosition().y + 10 + _stats.size() * 30);
    text.setCharacterSize(Csize);
    text.setFillColor(sf::Color::Red);

    text.setFont(_font);
    _stats[key] = text;
}

void UIai::update(std::map<std::string, std::string> stats)
{
    for (auto& pair : stats) {
        addStats(pair.first, pair.second, 20);
    }
}

void UIai::draw(sf::RenderWindow& window)
{
    window.draw(_shape);
    for (auto &pair : this->_stats) {
        //std::cout << "display = " << pair.first << " " << pair.second.getString().toAnsiString() << std::endl;
        window.draw(pair.second);
    }
}

void UIai::setView(sf::View &view)
{
    _viewUI = view;
}

sf::View UIai::getView() const
{
    return _viewUI;
}

void UIai::setPos(sf::Vector2f pos)
{
    _shape.setPosition(pos);

    // for (auto& pair : _stats) {
    //     pair.second.setPosition(_shape.getPosition().x + 10, _shape.getPosition().y + 10 + _stats.size() * 30);
    // }
}

void UIai::setIsDisplay(bool isDisplay)
{
    this->isDisplay = isDisplay;
}

bool UIai::getIsDisplay()
{
    return isDisplay;
}

sf::RectangleShape UIai::getShape() const
{
    return _shape;
}

sf::Font UIai::getFont() const
{
    return _font;
}

std::map<std::string, sf::Text> UIai::getStats() const
{
    return _stats;
}

bool UIai::getIsDisplay() const
{
    return isDisplay;
}
