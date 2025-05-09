/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** AI
*/

#include "AI.hpp"

AI::AI(sf::Sprite sprite, sf::Font)
{
    _sprite = sprite;
    ui.init(sf::Vector2f(200, 200), sf::Vector2f(10, 780));
}

UIai AI::getUI() const
{
    return ui;
}

AI::~AI()
{
}

void AI::update()
{
}

void AI::animate(int currentFrame)
{
    if (_spriteName == "Slime") {
        int left = (currentFrame%6) * _sprite.getTextureRect().width;
        _sprite.setTextureRect(sf::IntRect(689 + left, 222, 16, 16));
    }
    if (_spriteName == "Theif") {
        int left = (currentFrame%6) * _sprite.getTextureRect().width;
        _sprite.setTextureRect(sf::IntRect(689 + left, 222, 16, 16));
    }
}

void AI::displayUI(sf::RenderWindow &window)
{
    sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect spriteBounds = _sprite.getGlobalBounds();
    sf::FloatRect uiBounds = ui.getShape().getGlobalBounds();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (ui.getIsDisplay() == true) {
            worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window), ui.getView());
        }
        if (spriteBounds.contains(static_cast<sf::Vector2f>(worldPos))) {
            if (ui.getIsDisplay() == false) {
                ui.setIsDisplay(true);
            }
        }
        if (uiBounds.contains(static_cast<sf::Vector2f>(worldPos)))
            ui.setIsDisplay(false);
    }

    if (ui.getIsDisplay() == true) {
        window.setView(ui.getView());
        ui.draw(window);
    }
}

void AI::setSpriteName(std::string spriteName)
{
    _spriteName = spriteName;
}

void AI::setInventory(std::map<std::string, std::string> inventory)
{
    _inventory = inventory;
    ui.update(_inventory);
}

void AI::setSprite(sf::Sprite sprite)
{
    sprite = sprite;
}

void AI::setLevel(std::string _level)
{
    level.setString(_level);
}

void AI::setPos(sf::Vector2f pos)
{
    _pos = pos;
    _sprite.setPosition(pos);
}

void AI::setTeamName(std::string teamName)
{
    _teamName = teamName;
}

void AI::setTexture(sf::Texture texture)
{
    _texture = texture;
    _sprite.setTexture(_texture);
}

std::map<std::string, std::string> AI::getInventory() const
{
    return _inventory;
}

sf::Sprite AI::getSprite() const
{
    return _sprite;
}

sf::Text AI::getLevel() const
{
    return level;
}

sf::Vector2f AI::getPos() const
{
    return _sprite.getPosition();
}

std::string AI::getTeamName() const
{
    return _teamName;
}

void AI::setId(int id)
{
    this->id = id;
}

int AI::getId() const
{
    return id;
}

void AI::draw(sf::RenderWindow &window)
{
    window.draw(_sprite);
    displayUI(window);
}
