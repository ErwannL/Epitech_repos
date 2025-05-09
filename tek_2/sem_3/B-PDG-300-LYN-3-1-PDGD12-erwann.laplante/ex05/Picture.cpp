/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD12-erwann.laplante
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture(const std::string &file)
{
    data = "";
    getPictureFromFile(file);
}

Picture::Picture()
{
    data = "";
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream _file(file);
    std::string tmp;

    if (!_file) {
        data = "ERROR";
        return false;
    }
    data = "";
    while (std::getline(_file, tmp))
        data += tmp + "\n";
    return true;
}

Picture &Picture::operator=(Picture const &picture)
{
    data = picture.data;
    return *this;
}
