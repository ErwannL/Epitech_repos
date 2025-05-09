/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07pm-erwann.laplante
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot()
{
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(Arms arms)
{
    _arms = arms;
}

void KoalaBot::setParts(Legs legs)
{
    _legs = legs;
}

void KoalaBot::setParts(Head head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    Arms tempo = _arms;

    _arms = arms;
    arms = tempo;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs tempo = _legs;

    _legs = legs;
    legs = tempo;
}

void KoalaBot::swapParts(Head &head)
{
    Head tempo = _head;

    _head = head;
    head = tempo;
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status() const
{
    if (_arms.isFunctional() == true && _legs.isFunctional() == true && _head.isFunctional() == true)
        return true;
    return false;
}
