/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD09-erwann.laplante
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
    #define PALADIN_HPP_

    #include "Knight.hpp"
    #include "Priest.hpp"

    class Paladin : virtual public Knight, virtual public Priest {
        public:
            Paladin(const std::string &name, int power);
            ~Paladin();

            int attack();
            int special();
            void rest();
    };

#endif /* !PALADIN_HPP_ */
