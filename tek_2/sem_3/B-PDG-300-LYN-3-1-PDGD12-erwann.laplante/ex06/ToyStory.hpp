/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD12-erwann.laplante
** File description:
** ToyStory
*/

#ifndef TOYSTORY_HPP_
#define TOYSTORY_HPP_

#include "Toy.hpp"

class ToyStory {
    public:
        ToyStory();
        ~ToyStory();
        static void tellMeAStory(const char *filename, Toy &toy1, bool (Toy::*func1)(const std::string &str), Toy &toy2, bool (Toy::*func2)(const std::string &str));

    protected:
    private:
};

#endif /* !TOYSTORY_HPP_ */
