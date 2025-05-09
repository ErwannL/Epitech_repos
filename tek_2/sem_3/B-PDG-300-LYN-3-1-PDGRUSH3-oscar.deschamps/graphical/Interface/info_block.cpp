/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH3-oscar.deschamps
** File description:
** info_block
*/

#include "info_block.hpp"
#include <iostream>

infoBlock::infoBlock(const sf::Vector2f &position, const sf::Vector2f &size)
{
    rec_back.setSize(size);
    rec_back.setPosition(position);
    this->vertex.position = position;
    graph.setPrimitiveType(sf::LinesStrip);
    _position = position;
    _size = size;
    x = _position.x;
    y = _position.y + size.y;
}

infoBlock::~infoBlock()
{
}

void infoBlock::resetGraphPos()
{
    sf::VertexArray graph_copy;
    graph_copy.setPrimitiveType(sf::LinesStrip);
    for (size_t i = 1; i < graph.getVertexCount(); i ++)
    {
        graph[i].position.x -= 2;
        graph_copy.append(graph[i]);
    }
    graph.clear();

    for (size_t i = 0; i < graph_copy.getVertexCount(); i ++)
    {
        graph.append(graph_copy[i]);
    }
}

void infoBlock::setGraph(float value)
{
    x += 2;

    if ((x -_position.x) > _size.x) {
        x -= 2;
        resetGraphPos();
    }
    y -= value;

    if (value > 70) {
        vertex.color = sf::Color::Red;
    } else {
        vertex.color = sf::Color::Green;
    }
    vertex.position = sf::Vector2f(x, y);
    y += value;
    graph.append(vertex);
}

void infoBlock::setPosBlock(sf::Vector2f pos)
{
    _position.x = pos.x;
    _position.y = pos.y;
}

sf::Vector2f infoBlock::getPosition()
{
    return (_position);
}

sf::VertexArray infoBlock::getGraph() const
{
    return(graph);
}

sf::RectangleShape infoBlock::getRec_back() const
{
    return(rec_back);
}
