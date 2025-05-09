/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD12-erwann.laplante
** File description:
** Woody
*/

#ifndef WOODY_HPP_
    #define WOODY_HPP_

    #include "Toy.hpp"

    class Woody : public Toy {
        public:
            Woody(std::string name);
            Woody(std::string name, std::string ascii);
            ~Woody();
    };

#endif /* !WOODY_HPP_ */
