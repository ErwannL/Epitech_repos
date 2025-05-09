/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(unsigned int size)
{
    _size = size;
    _nbr = 0;
}

FruitBox::~FruitBox()
{
    IFruit *to_remove;

    while (_element.empty() == false) {
        to_remove = _element.front();
        _element.pop_front();
        delete to_remove;
    }
}

unsigned int FruitBox::getSize() const
{
    return _size;
}

unsigned int FruitBox::nbFruits() const
{
    return _nbr;
}

bool FruitBox::pushFruit(IFruit *fruit)
{
    if (_nbr == _size || std::find(std::begin(_element), std::end(_element), fruit) != std::end(_element))
        return false;
    _element.push_back(fruit);
    _nbr += 1;
    return true;
}

IFruit *FruitBox::popFruit()
{
    IFruit *to_remove;

    if (_nbr == 0)
        return NULL;
    _nbr -= 1;
    to_remove = _element.front();
    _element.pop_front();
    return to_remove;
}

std::ostream &FruitBox::print(std::ostream &stream) const
{
    std::list<IFruit *> list(_element);
    int a = 0;

    stream << "[";
    while (list.empty() == false) {
        if (a != 0)
            stream << ", ";
        stream << *(list.front());
        list.pop_front();
        a = 1;
    }
    stream << "]";
    return stream;
}

std::ostream &operator<<(std::ostream &stream, FruitBox const &fruit)
{
    return fruit.print(stream);
}
