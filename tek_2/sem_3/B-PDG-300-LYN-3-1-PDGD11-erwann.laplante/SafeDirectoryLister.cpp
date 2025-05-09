/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD11-erwann.laplante
** File description:
** SafeDirectoryLister
*/

#include "SafeDirectoryLister.hpp"

SafeDirectoryLister::SafeDirectoryLister()
{
}

SafeDirectoryLister::SafeDirectoryLister(const std::string& path, bool hidden)
{
    open(path, hidden);
}

SafeDirectoryLister::~SafeDirectoryLister()
{
    if (_is_open == true)
        closedir(_dir);
}

bool SafeDirectoryLister::open(const std::string& path, bool hidden)
{
    _path = path;
    _hidden = hidden;

    if (_is_open == true)
        closedir(_dir);
    _is_open = true;
    if ((_dir = opendir(path.c_str())) == NULL) {
        throw IDirectoryLister::OpenFailureException();
    } else
        return true;
}

std::string SafeDirectoryLister::get()
{
    if ((_file = readdir(_dir)) == NULL) {
        if (_is_open == true)
            closedir(_dir);
        throw IDirectoryLister::NoMoreFileException();
    }
    if (_file->d_name[0] == '.' && _hidden == false)
        return get();
    return _file->d_name;
}
