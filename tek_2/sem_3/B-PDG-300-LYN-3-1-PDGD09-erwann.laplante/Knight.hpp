/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
    #define KNIGHT_HPP_

    #include "Peasant.hpp"

    class Knight : virtual public Peasant {
        public:
            Knight(const std::string &name, int power);
            ~Knight();

            int attack();
            int special();
            void rest();
    };

#endif /* !KNIGHT_HPP_ */
