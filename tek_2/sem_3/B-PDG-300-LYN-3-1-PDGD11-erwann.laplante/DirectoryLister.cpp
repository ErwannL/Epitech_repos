/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD11-erwann.laplante
** File description:
** DirectoryLister
*/

#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister()
{
}

DirectoryLister::DirectoryLister(const std::string& path, bool hidden)
{
    open(path, hidden);
}

DirectoryLister::~DirectoryLister()
{
    if (_is_open == true) {
        closedir(_dir);
        _is_open = false;
    }
}

bool DirectoryLister::open(const std::string& path, bool hidden)
{
    _hidden = hidden;

    if (_is_open == true)
        closedir(_dir);
    if ((_dir = opendir(path.c_str())) == NULL) {
        perror(path.c_str());
        return false;
    } else {
        _is_open = true;
        return true;
    }
}

std::string DirectoryLister::get()
{
    if (_dir == NULL)
        return "";
    if ((_is_open == true) && ((_file = readdir(_dir)) == NULL))
        return "";
    if (_file->d_name[0] == '.' && _hidden == false)
        return get();
    return _file->d_name;
}
