/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** SpriteFactory
*/

#include "SpriteFactory.hpp"

SpriteFactory::SpriteFactory()
{
}

SpriteFactory::~SpriteFactory()
{
}

sf::Sprite SpriteFactory::createSprite(std::string name, sf::Vector2f pos)
{
    sf::Sprite sprite;
    sprite.scale(5, 5);
    sprite.setPosition(sf::Vector2f(pos.x * sprite.getScale().x, pos.y * sprite.getScale().y));

     if (name == "0") {
        sprite.setTextureRect(sf::IntRect(384, 128, 16, 16));
    }
    if (name == "1") {
        sprite.setTextureRect(sf::IntRect(145, 289, 16, 16));
    }
    if (name == "2") {
        sprite.setTextureRect(sf::IntRect(161, 289, 16, 16));
    }
    if (name == "3") {
        sprite.setTextureRect(sf::IntRect(177, 289, 16, 16));
    }
    if (name == "4") {
        sprite.setTextureRect(sf::IntRect(193, 289, 16, 16));
    }
    if (name == "5") {
        sprite.setTextureRect(sf::IntRect(209, 289, 16, 16));
    }
    if (name == "6") {
        sprite.setTextureRect(sf::IntRect(225, 289, 16, 16));
    }
    if (name == "sand") {
        sprite.setTextureRect(sf::IntRect(144, 256, 16, 16));
    }
    if (name == "grass")
        sprite.setTextureRect(sf::IntRect(160, 240, 16, 16));
    if (name == "water")
        sprite.setTextureRect(sf::IntRect(144, 240, 16, 16));
    if (name == "tree")
        sprite.setTextureRect(sf::IntRect(18, 241, 16, 16));
    if (name == "Slime")
        sprite.setTextureRect(sf::IntRect(689, 225, 16, 16));
    if (name == "Theif")
        sprite.setTextureRect(sf::IntRect(433, 33, 16, 16));
    return sprite;
}