/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD06-erwann.laplante
** File description:
** MyCat
*/

#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
    std::string str;
    int n = 1;
    int r = 0;

    if (ac == 1) {
        while (std::getline(std::cin, str))
            std::cout << str << std::endl;
        return 0;
    }
    for (int i = n; i != ac; i++) {
        std::ifstream file(av[i]);
        if (!file) {
            std::cerr << "MyCat: " << av[i] << ": No such file or directory" << std::endl;
            r = 84;
        }
        while (std::getline(file, str))
            std::cout << str << std::endl;
    }
    return r;
}
