/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD11-erwann.laplante
** File description:
** List
*/

#include "List.hpp"

List::List()
{
}

List::~List()
{
}

bool List::empty() const
{
    return _list.empty();
}

std::size_t List::size() const
{
    return _list.size();
}

IObject*& List::front()
{
    if (_list.empty() == true)
        throw List::InvalidOperationException();
    return _list.front();
}

IObject* List::front() const
{
    if (_list.empty() == true)
        throw List::InvalidOperationException();
    return _list.front();
}

IObject*& List::back()
{
    if (_list.empty() == true)
        throw List::InvalidOperationException();
    return _list.back();
}

IObject* List::back() const
{
    if (_list.empty() == true)
        throw List::InvalidOperationException();
    return _list.back();
}

void List::pushBack(IObject* obj)
{
    _list.push_back(obj);
}

void List::pushFront(IObject* obj)
{
    _list.push_front(obj);
}

void List::popFront()
{
    if (_list.empty() == true)
        throw List::InvalidOperationException();
    _list.pop_front();
}

void List::popBack()
{
    if (_list.empty() == true)
        throw List::InvalidOperationException();
    _list.pop_back();
}

void List::clear()
{
    IObject *tmp;

    while (_list.empty() != true) {
        tmp = _list.front();
        _list.pop_front();
        delete tmp;
    }
}

void List::forEach(void(*function)(IObject*))
{
    IObject *tmp;
    std::__cxx11::list<IObject*>::size_type size = _list.size();

    for (std::__cxx11::list<IObject*>::size_type i = 0; i != size; i++) {
        tmp = _list.front();
        _list.pop_front();
        function(tmp);
        _list.push_back(tmp);
    }
}

List::InvalidOperationException::InvalidOperationException()
{
}

List::InvalidOperationException::~InvalidOperationException()
{
}

void List::InvalidOperationException::what() const noexcept
{
}
