/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-erwann.laplante
** File description:
** Input
*/

#include "Input.hpp"

Input::Input()
{
    for (auto i = 0; i != 1; i++)
        state.push_back(nts::Undefined);
}

Input::~Input()
{
}
