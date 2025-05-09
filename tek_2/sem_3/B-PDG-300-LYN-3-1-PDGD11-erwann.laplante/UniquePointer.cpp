/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD11-erwann.laplante
** File description:
** UniquePointer
*/

#include "UniquePointer.hpp"

UniquePointer::UniquePointer()
{
}

UniquePointer::UniquePointer(TestObject *obj)
{
    _obj.reset(obj);
}

UniquePointer::~UniquePointer()
{
}

void UniquePointer::touch()
{
    _obj->touch();
}

UniquePointer &UniquePointer::operator=(TestObject *obj)
{
    _obj.reset(obj);
    return *this;
}

TestObject *UniquePointer::operator->()
{
    return _obj.get();
}

TestObject &UniquePointer::operator*()
{
    return *_obj;
}

void UniquePointer::reset(TestObject *obj)
{
    _obj.reset(obj);
}

void UniquePointer::swap(UniquePointer &obj)
{
    _obj.swap(obj._obj);
}

void UniquePointer::reset()
{
    _obj.reset();
}
