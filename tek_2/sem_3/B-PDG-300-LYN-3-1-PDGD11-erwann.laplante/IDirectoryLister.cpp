/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD11-erwann.laplante
** File description:
** IDirectoryLister
*/

#include "IDirectoryLister.hpp"

IDirectoryLister::OpenFailureException::OpenFailureException()
{
}

IDirectoryLister::OpenFailureException::~OpenFailureException()
{
}

const char *IDirectoryLister::OpenFailureException::what() const noexcept
{
    return strerror(errno);
}

IDirectoryLister::NoMoreFileException::NoMoreFileException()
{
}

IDirectoryLister::NoMoreFileException::~NoMoreFileException()
{
}

const char *IDirectoryLister::NoMoreFileException::what() const noexcept
{
    return "End of stream";
}
