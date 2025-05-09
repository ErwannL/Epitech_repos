/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH3-oscar.deschamps
** File description:
** CreateText
*/

#include "CreateText.hpp"

CreateText::CreateText(std::string string, sf::Vector2f pos, sf::Vector2f size)
{
    font.loadFromFile("graphical/Interface/arial.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setString(string);
    text.setPosition(pos);
    rec_back.setSize(size);
    rec_back.setPosition(pos);
    rec_back.setOutlineColor(sf::Color::White);
    rec_back.setFillColor(sf::Color::Transparent);
    rec_back.setOutlineThickness(2.0);
}

sf::Text CreateText::getText()
{
    return (text);
}

CreateText::~CreateText()
{

}

sf::RectangleShape CreateText::getRect()
{
    return (rec_back);
}