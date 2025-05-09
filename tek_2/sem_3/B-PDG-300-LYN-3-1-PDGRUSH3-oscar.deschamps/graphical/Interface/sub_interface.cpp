/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH3-oscar.deschamps
** File description:
** sub-interface
*/

#include "sub_interface.hpp"
#include <iostream>

subInterface::subInterface(size_t nb_blocks, sf::Vector2f pos, sf::Vector2f _size, std::string name)
{
    rec_back.setSize(_size);
    rec_back.setPosition(pos);
    rec_back.setOutlineColor(sf::Color::White);
    rec_back.setFillColor(sf::Color::Transparent);
    rec_back.setOutlineThickness(2.0);

    setGraphInterface(nb_blocks);
    setTextInterface();
}

void subInterface::setTextInterface()
{
    font.loadFromFile("graphical/Interface/arial.ttf");
    scale.setFont(font);
    scale.setCharacterSize(10);
    scale.setString("100%");
    scale.setPosition(sf::Vector2f(rec_back.getPosition().x + 10, rec_back.getPosition().y + 10));
    scale.setFillColor(sf::Color::White);
    time.setFont(font);
    time.setCharacterSize(10);
    time.setString("0%");
    time.setPosition(sf::Vector2f(rec_back.getPosition().x + 10, rec_back.getPosition().y + 140));
    time.setFillColor(sf::Color::White);
}

void subInterface::setGraphInterface(int nb_blocks)
{
    float minus_y = rec_back.getPosition().y + 30;
    if (nb_blocks > 0) {
        setTextInterface();
        for (int i = 0; i < nb_blocks; i ++)
        {
            infoBlock block(sf::Vector2f(rec_back.getPosition().x + 10, minus_y), sf::Vector2f(rec_back.getSize().x - 20, 100.f));
            list_blocks.push_front(block);
            minus_y += 110;
        }
    }
}

void subInterface::updateListGraph(float value)
{
    for (infoBlock &block : list_blocks)
    {
        block.setGraph(value);
    }
}

subInterface::~subInterface()
{
}

int subInterface::getSize() const
{
    return (size);
}

std::list<infoBlock> subInterface::getBlocks() const
{
    return (list_blocks);
}

sf::RectangleShape subInterface::getRec_back()
{
    return(rec_back);
}

std::string subInterface::getName() const
{
    return (name);
}

void subInterface::addBlock()
{
}

void subInterface::removeBlock()
{

}

sf::Text subInterface::getScale()
{
    return(scale);
}


sf::Text subInterface::getTime()
{
    return(time);
}


