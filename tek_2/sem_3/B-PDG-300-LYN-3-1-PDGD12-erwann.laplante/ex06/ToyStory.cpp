/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD12-erwann.laplante
** File description:
** ToyStory
*/

#include "ToyStory.hpp"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

void ToyStory::tellMeAStory(const char *filename, Toy &toy1, bool (Toy::*func1)(const std::string &str), Toy &toy2, bool (Toy::*func2)(const std::string &str))
{
    std::ifstream file(filename);
    std::string tmp;
    std::string picture;
    int who = 1;

    if (!file) {
        std::cout << "Bad Story" << std::endl;
        return;
    }
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;
    while (std::getline(file, tmp)) {
        if (tmp.rfind("picture:") == 0) {
            picture = tmp.substr(tmp.find_first_of(":") + 1);
            if (who == 1) {
                if (toy1.setAscii(picture) == true) {
                    std::cout << toy1.getAscii() << std::endl;
                    if (who == 1)
                        who = 2;
                    else
                        who = 1;
                } else {
	                std::cout << toy1.getLastError().where() << ": " << toy1.getLastError().what() << std::endl;
                    return;
                }
            } else {
                if (toy2.setAscii(picture) == true) {
                    std::cout << toy2.getAscii() << std::endl;
                    if (who == 1)
                        who = 2;
                    else
                        who = 1;
                } else {
	                std::cout << toy2.getLastError().where() << ": " << toy2.getLastError().what() << std::endl;
                    return;
                }
            }
        } else {
            if (who == 1) {
                if (!(toy1.*func1)(tmp)) {
	                std::cout << toy2.getLastError().where() << ": " << toy2.getLastError().what() << std::endl;
                    return;
                }
            } else {
                if (!(toy2.*func2)(tmp)) {
	                std::cout << toy2.getLastError().where() << ": " << toy2.getLastError().what() << std::endl;
                    return;
                }
            }
        }
        if (who == 1)
            who = 2;
        else
            who = 1;
    }
}
