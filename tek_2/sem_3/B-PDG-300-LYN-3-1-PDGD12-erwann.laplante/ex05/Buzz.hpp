/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD12-erwann.laplante
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
    #define BUZZ_HPP_

    #include "Toy.hpp"

    class Buzz : public Toy {
        public:
            Buzz(std::string name);
            Buzz(std::string name, std::string ascii);
            ~Buzz();

            bool speak_es(std::string statement);
    };

#endif /* !BUZZ_HPP_ */
