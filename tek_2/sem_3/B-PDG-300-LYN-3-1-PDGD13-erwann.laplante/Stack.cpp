/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD13-erwann.laplante
** File description:
** Stack
*/

#include "Stack.hpp"

Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::push(double value)
{
    _stack.push(value);
}

double Stack::pop()
{
    if (_stack.empty() == true)
        throw Error(Error::EMPTY);
    double tmp = top();

    _stack.pop();
    return tmp;
}

double Stack::top() const
{
    if (_stack.empty() == true)
        throw Error(Error::EMPTY);
    return _stack.top();
}

void Stack::add()
{
    if (_stack.size() < 2)
        throw Error(Error::NOT_ENOUGH);
    double one = pop();
    double two = pop();
    double res = one + two;

    push(res);
}

void Stack::sub()
{
    if (_stack.size() < 2)
        throw Error(Error::NOT_ENOUGH);
    double one = pop();
    double two = pop();
    double res = one - two;

    push(res);
}

void Stack::mul()
{
    if (_stack.size() < 2)
        throw Error(Error::NOT_ENOUGH);
    double one = pop();
    double two = pop();
    double res = one * two;
    push(res);
}

void Stack::div()
{
    if (_stack.size() < 2)
        throw Error(Error::NOT_ENOUGH);
    double one = pop();
    double two = pop();
    if (two == 0) {
        push(two);
        push(one);
        throw Error(Error::ZERO);
    }
    double res = one / two;

    push(res);
}

Stack::Error::Error(ErrorType erreur)
{
    type = erreur;
}

Stack::Error::Error()
{
}

Stack::Error::~Error()
{
}

const char *Stack::Error::what() const noexcept
{
    if (this->type == EMPTY) {
        return "Empty stack";
    } else if (this->type == NOT_ENOUGH) {
        return "Not enough operands";
    } else {
        return "divide by zero";
    }
}
