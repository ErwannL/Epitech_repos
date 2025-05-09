/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Tile
*/

#include "Tile.hpp"

Tile::Tile(sf::Sprite sprite, sf::Text txt)
{
    _sprite = sprite;
    ui.init(sf::Vector2f(200, 200), sf::Vector2f(10, 780));
    text = txt;
}

Tile::~Tile()
{
}

void Tile::update()
{
}

void Tile::animate(int)
{
}

void Tile::setInventory(std::map<std::string, sf::Sprite> inventory)
{
    _inventory = inventory;
}

void Tile::setSprite(sf::Sprite sprite)
{
    sprite = sprite;
}

void Tile::setPos(sf::Vector2f pos)
{
    _sprite.setPosition(pos);
}

void Tile::setTexture(sf::Texture texture)
{
    _texture = texture;
    _sprite.setTexture(_texture);
}

void Tile::setSpriteName(std::string spriteName)
{
    _spriteName = spriteName;
}

void Tile::displayUI(sf::RenderWindow &window)
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

std::map<std::string, sf::Sprite> Tile::getInventory() const
{
    return _inventory;
}

sf::Sprite Tile::getSprite() const
{
    return _sprite;
}

UIai Tile::getUI() const
{
    return ui;
}

void Tile::drawInventory(sf::RenderWindow &window)
{
    for (auto item : _inventory) {
        window.draw(item.second);
        text.setString(std::to_string(_inventory.size()));
        text.setPosition(sf::Vector2f(item.second.getPosition().x + 15, item.second.getPosition().y));
        window.draw(text);
    }
}

void Tile::draw(sf::RenderWindow &window)
{
    if (drawing == false) {
        window.draw(_sprite);
        drawing = false;
    }
    drawInventory(window);
}


void Tile::popResource(std::string)
{

}

void Tile::addResource(std::string resource)
{
    SpriteFactory factory;
    sf::Sprite sprite = factory.createSprite(resource, sf::Vector2f{_pos.x + 16 , _pos.y});
    sprite.setTexture(_texture);
    sprite.setScale(sf::Vector2f(1, 1));
    _inventory[resource] = sprite;
}
