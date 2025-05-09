/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD11-erwann.laplante
** File description:
** SharedPointer
*/

#include "SharedPointer.hpp"

SharedPointer::SharedPointer()
{
}

SharedPointer::SharedPointer(TestObject *obj)
{
    _obj.reset(obj);
}

SharedPointer::~SharedPointer()
{
}

void SharedPointer::touch()
{
    _obj->touch();
}

SharedPointer &SharedPointer::operator=(TestObject *obj)
{
    _obj.reset(obj);
    return *this;
}

TestObject *SharedPointer::operator->()
{
    return _obj.get();
}

TestObject &SharedPointer::operator*()
{
    return *_obj;
}

void SharedPointer::reset(TestObject *obj)
{
    _obj.reset(obj);
}

void SharedPointer::swap(SharedPointer &obj)
{
    _obj.swap(obj._obj);
}

void SharedPointer::reset()
{
    _obj.reset();
}

long SharedPointer::use_count()
{
    return _obj.use_count();
}
