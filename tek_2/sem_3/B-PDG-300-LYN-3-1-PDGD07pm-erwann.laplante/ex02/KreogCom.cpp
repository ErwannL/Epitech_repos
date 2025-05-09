/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD07pm-erwann.laplante
** File description:
** KreogCom
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) :  m_serial {serial}
{
    _x = x;
    _y = y;
    _next = NULL;
    _previous = NULL;
    std::cout << "KreogCom " << m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    if (_next != NULL)
        _next->_previous = _next;
    if (_next != NULL)
        _previous->_next = _next;
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom (int x, int y, int serial)
{
    KreogCom *the_new = new KreogCom(x, y, serial);

    if (_next == NULL){
        _next = the_new;
        the_new->_previous = this;
        the_new->_next = NULL;
        return;
    }
    the_new->_next = _next;
    the_new->_previous = this;
    _next->_previous = the_new;
    _next = the_new;
}

KreogCom *KreogCom::getCom ()
{
    return _next;
}

void KreogCom::removeCom ()
{
    KreogCom *to_delete;

    if (_next == NULL)
        return;
    to_delete = _next;
    if (to_delete->_next == NULL) {
        _next->_previous = NULL;
        _next = NULL;
    } else {
        _next = to_delete->_next;
        _next->_previous = this;
    }
    delete to_delete;
}

void KreogCom::ping () const
{
    std::cout << "KreogCom " << m_serial << " currently at " << _x << " " << _y << std::endl;
}

void KreogCom::locateSquad () const
{
    KreogCom *tmp = _next;

    while (tmp != NULL) {
        tmp->ping();
        tmp = tmp->_next;
    }
    ping();
}
